//#include <linux/config.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/pci.h>
#include <linux/delay.h>
#include <asm/delay.h>
#include "ar7240.h"
/*
 * PCI cfg an I/O routines are done by programming a 
 * command/byte enable register, and then read/writing
 * the data from a data regsiter. We need to ensure
 * these transactions are atomic or we will end up
 * with corrupt data on the bus or in a driver.
 */
static DEFINE_SPINLOCK(ar7100_pci_lock);

int
ar7240_local_read_config(int where, int size, uint32_t *value)
{
    unsigned long flags, addr, tval, mask;

    /* Make sure the address is aligned to natural boundary */
    if(where & (size - 1))
        return PCIBIOS_BAD_REGISTER_NUMBER;

    spin_lock_irqsave(&ar7100_pci_lock, flags);
    switch (size) {
        case 1:
            addr = where & ~3;
            mask = 0xff000000 >> ((where % 4) * 8);
            tval = ar7240_reg_rd(AR7240_PCI_CRP + addr);
            tval = tval & ~mask;
            *value = (tval >> ((4 - (where % 4))*8));
            break;
        case 2:
            addr = where & ~3;
            mask = 0xffff0000 >> ((where % 4)*8);
            tval = ar7240_reg_rd(AR7240_PCI_CRP + addr);
            tval = tval & ~mask;
            *value = (tval >> ((4 - (where % 4))*8));
            break;
        case 4:
            *value = ar7240_reg_rd(AR7240_PCI_CRP + where);
            break;
        default:
            spin_unlock_irqrestore(&ar7100_pci_lock, flags);
            return PCIBIOS_BAD_REGISTER_NUMBER;
    }
    spin_unlock_irqrestore(&ar7100_pci_lock, flags);
    return PCIBIOS_SUCCESSFUL;
}

int
ar7240_local_write_config(int where, int size, uint32_t value) 
{
    unsigned long flags, addr, tval, mask;

    /* Make sure the address is aligned to natural boundary */
    if(where & (size - 1))
        return PCIBIOS_BAD_REGISTER_NUMBER;

    spin_lock_irqsave(&ar7100_pci_lock, flags);
    switch (size) {
        case 1:
            addr = (AR7240_PCI_CRP + where) & ~3;
            mask = 0xff000000 >> ((where % 4)*8);
            tval = ar7240_reg_rd(addr);
            tval = tval & ~mask;
            tval |= (value << ((4 - (where % 4))*8)) & mask;
            ar7240_reg_wr(addr,tval);
            break;
        case 2:
            addr = (AR7240_PCI_CRP + where) & ~3;
            mask = 0xffff0000 >> ((where % 4)*8);
            tval = ar7240_reg_rd(addr);
            tval = tval & ~mask;
            tval |= (value << ((4 - (where % 4))*8)) & mask;
            ar7240_reg_wr(addr,tval);
            break;
        case 4:
            ar7240_reg_wr((AR7240_PCI_CRP + where),value);
            break;
        default:
            spin_unlock_irqrestore(&ar7100_pci_lock, flags);
            return PCIBIOS_BAD_REGISTER_NUMBER;
    }
    spin_unlock_irqrestore(&ar7100_pci_lock, flags);
    return PCIBIOS_SUCCESSFUL;
}

#ifdef CONFIG_PERICOM
static int 
ar7240_pci_read_config(struct pci_bus *bus, unsigned int devfn, int where,
                       int size, uint32_t *data)
{
	int		err, offset;

	if(devfn)
		return PCIBIOS_DEVICE_NOT_FOUND;

	if(where & (size - 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	err = PCIBIOS_SUCCESSFUL;

	ar7240_reg_wr(0xb80f0000, 0x0ffc1);	// Address Translation disable

	switch(bus->number) {
	case AR7240_PRI_BUS_NO:
		offset = where & (~3);
		*data = ar7240_reg_rd(0x15100000 + offset);
		break;
	case AR7240_PORT0_BUS_NO:
		offset = where & (~3);
		*data = ar7240_reg_rd(0x16000000 + offset);
		break;
	case AR7240_PORT1_BUS_NO:
		*data = ar7240_reg_rd(0x17000000 + where);
		break;
	default:
		*data = 0xdeadbeef;
		err = PCIBIOS_BAD_REGISTER_NUMBER;
		goto out;
	}

	if (size == 1 || size == 2) {
		*data = (*data >> ((where % 4) * 8)) & ((1u << (size * 8)) - 1);
	} else if (size == 4) {
		/* no adjustment needed */
	} else {
		*data = 0xdeadbeef;
		err = PCIBIOS_BAD_REGISTER_NUMBER;
		goto out;
	}

out:
	ar7240_reg_wr(0xb80f0000, 0x1ffc1);	// Address Translation enable
	return err;
}

int 
ar7240_pci_write_config(struct pci_bus *bus,  unsigned int devfn, int where, 
                        int size, uint32_t data)
{
	int		err, offset;
	unsigned	base, tval, mask, busno;

	if (devfn)
		return PCIBIOS_DEVICE_NOT_FOUND;

	if (where & (size - 1))
		return PCIBIOS_BAD_REGISTER_NUMBER;

	/*
	 * A hack to handle the request to program the command
	 * register from ar7240_pcibios_init()
	 */
	if (where == PCI_COMMAND &&
	    (((unsigned)bus == AR7240_PORT0_BUS_NO) ||
	     ((unsigned)bus == AR7240_PORT1_BUS_NO))) {
		busno = (unsigned)bus;
	} else {
		busno = bus->number;
	}

	/*
	 * Don't allow linux to override, the setup done
	 * by ar7240_pcibios_init
	 */
	if (where == PCI_PRIMARY_BUS || where == PCI_SECONDARY_BUS ||
		where == PCI_SUBORDINATE_BUS) {
		return PCIBIOS_SUCCESSFUL;
	}

	err = PCIBIOS_SUCCESSFUL;

	ar7240_reg_wr(0xb80f0000, 0x0ffc1);	// Address Translation disable
	switch (busno) {
	case AR7240_PRI_BUS_NO:
		/*
		 * Don't allow linux to override, the setup done
		 * by ar7240_pcibios_init
		 */
		if (where == PCI_BASE_ADDRESS_4 ||
		    where == PCI_BASE_ADDRESS_5) {
			//printk("%s(%d): ignoring write to bar%d of bus %d\n",
			//	__func__, __LINE__,
			//	(where == PCI_BASE_ADDRESS_4) ? 4 : 5,
			//	busno);
			goto out;
		}
		base = 0x15100000;
		break;
	case AR7240_PORT0_BUS_NO:
		base = 0x16000000;
		break;
	case AR7240_PORT1_BUS_NO:
		base = 0x17000000;
		break;
	default:
		err = PCIBIOS_BAD_REGISTER_NUMBER;
		goto out;
	}

	switch (size) {
	case 1:
		offset = (base + where) & ~3;
		mask = 0xff000000 >> ((where % 4) * 8);
		tval = ar7240_reg_rd(offset);
		tval = tval & mask;
		tval |= (data << ((4 - (where % 4)) * 8)) & ~mask;
		ar7240_reg_wr(offset, tval);
		break;
	case 2:
		offset = (base + where) & ~3;
		mask = 0xffff0000 >> ((where % 4) * 8);
		tval = ar7240_reg_rd(offset);
		tval = tval & mask;
		tval |= (data << ((4 - (where % 4)) * 8)) & ~mask;
		ar7240_reg_wr(offset, tval);
		break;
	case 4:
		ar7240_reg_wr(base + where, data);
		break;
	default:
		err = PCIBIOS_BAD_REGISTER_NUMBER;
		goto out;
	}
out:
	ar7240_reg_wr(0xb80f0000, 0x1ffc1);	// Address Translation enable
	return err;
}
#else
static int 
ar7240_pci_read_config(struct pci_bus *bus, unsigned int devfn, int where,
                       int size, uint32_t *value)
{
    unsigned long flags, addr, tval, mask;
	if(devfn)
        return PCIBIOS_DEVICE_NOT_FOUND;

    /* Make sure the address is aligned to natural boundary */
    if(where & (size - 1))
        return PCIBIOS_BAD_REGISTER_NUMBER;

    spin_lock_irqsave(&ar7100_pci_lock, flags);
    switch (size) {
        case 1:
            addr = where & ~3;
            mask = 0xff000000 >> ((where % 4) * 8);
            tval = ar7240_reg_rd(AR7240_PCI_DEV_CFGBASE + addr);
            tval = tval & ~mask;
            *value = (tval >> ((4 - (where % 4))*8));
            break;
        case 2:
            addr = where & ~3;
            mask = 0xffff0000 >> ((where % 4)*8);
            tval = ar7240_reg_rd(AR7240_PCI_DEV_CFGBASE + addr);
            tval = tval & ~mask;
            *value = (tval >> ((4 - (where % 4))*8));
            break;
        case 4:
            *value = ar7240_reg_rd(AR7240_PCI_DEV_CFGBASE + where);
            if (is_ar7240()) {
                /*
                 * WAR for BAR issue - We are unable to access the PCI device spac 
                 * if we set the BAR with proper base address 
                 */
                if(where == 0x10)
                    ar7240_reg_wr((AR7240_PCI_DEV_CFGBASE + where),0xffff);
            }
            break;
        default:
            spin_unlock_irqrestore(&ar7100_pci_lock, flags);
            return PCIBIOS_BAD_REGISTER_NUMBER;
    }
    spin_unlock_irqrestore(&ar7100_pci_lock, flags);
    return PCIBIOS_SUCCESSFUL;
}

static int 
ar7240_pci_write_config(struct pci_bus *bus,  unsigned int devfn, int where, 
                        int size, uint32_t value)
{
    uint32_t flags, tval, addr, mask;

	if(devfn)
           return PCIBIOS_DEVICE_NOT_FOUND;

    /* Make sure the address is aligned to natural boundary */
    if(where & (size - 1))
        return PCIBIOS_BAD_REGISTER_NUMBER;

    spin_lock_irqsave(&ar7100_pci_lock, flags);
    switch (size) {
        case 1:
            addr = (AR7240_PCI_DEV_CFGBASE + where) & ~3;
            mask = 0xff000000 >> ((where % 4)*8);
            tval = ar7240_reg_rd(addr);
            tval = tval & ~mask;
            tval |= (value << ((4 - (where % 4))*8)) & mask;
            ar7240_reg_wr(addr,tval);
            break;
        case 2:
            addr = (AR7240_PCI_DEV_CFGBASE + where) & ~3;
            mask = 0xffff0000 >> ((where % 4)*8);
            tval = ar7240_reg_rd(addr);
            tval = tval & ~mask;
            tval |= (value << ((4 - (where % 4))*8)) & mask;
            ar7240_reg_wr(addr,tval);
            break;
        case 4:
            ar7240_reg_wr((AR7240_PCI_DEV_CFGBASE + where),value);
            break;
        default:
            spin_unlock_irqrestore(&ar7100_pci_lock, flags);
            return PCIBIOS_BAD_REGISTER_NUMBER;
    }
    spin_unlock_irqrestore(&ar7100_pci_lock, flags);
    return PCIBIOS_SUCCESSFUL;
}
#endif

struct pci_ops ar7240_pci_ops = {
	.read =  ar7240_pci_read_config,
	.write = ar7240_pci_write_config,
};
