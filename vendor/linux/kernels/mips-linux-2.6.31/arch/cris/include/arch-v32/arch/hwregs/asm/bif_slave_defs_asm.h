#ifndef __bif_slave_defs_asm_h
#define __bif_slave_defs_asm_h

/*
 * This file is autogenerated from
 *   file:           ../../inst/bif/rtl/bif_slave_regs.r
 *     id:           bif_slave_regs.r,v 1.5 2005/02/04 13:55:28 perz Exp
 *     last modfied: Mon Apr 11 16:06:34 2005
 *
 *   by /n/asic/design/tools/rdesc/src/rdes2c -asm --outfile asm/bif_slave_defs_asm.h ../../inst/bif/rtl/bif_slave_regs.r
 *      id: $Id: //depot/sw/releases/Aquila_9.2.0_U11/linux/kernels/mips-linux-2.6.31/arch/cris/include/arch-v32/arch/hwregs/asm/bif_slave_defs_asm.h#1 $
 * Any changes here will be lost.
 *
 * -*- buffer-read-only: t -*-
 */

#ifndef REG_FIELD
#define REG_FIELD( scope, reg, field, value ) \
  REG_FIELD_X_( value, reg_##scope##_##reg##___##field##___lsb )
#define REG_FIELD_X_( value, shift ) ((value) << shift)
#endif

#ifndef REG_STATE
#define REG_STATE( scope, reg, field, symbolic_value ) \
  REG_STATE_X_( regk_##scope##_##symbolic_value, reg_##scope##_##reg##___##field##___lsb )
#define REG_STATE_X_( k, shift ) (k << shift)
#endif

#ifndef REG_MASK
#define REG_MASK( scope, reg, field ) \
  REG_MASK_X_( reg_##scope##_##reg##___##field##___width, reg_##scope##_##reg##___##field##___lsb )
#define REG_MASK_X_( width, lsb ) (((1 << width)-1) << lsb)
#endif

#ifndef REG_LSB
#define REG_LSB( scope, reg, field ) reg_##scope##_##reg##___##field##___lsb
#endif

#ifndef REG_BIT
#define REG_BIT( scope, reg, field ) reg_##scope##_##reg##___##field##___bit
#endif

#ifndef REG_ADDR
#define REG_ADDR( scope, inst, reg ) REG_ADDR_X_(inst, reg_##scope##_##reg##_offset)
#define REG_ADDR_X_( inst, offs ) ((inst) + offs)
#endif

#ifndef REG_ADDR_VECT
#define REG_ADDR_VECT( scope, inst, reg, index ) \
         REG_ADDR_VECT_X_(inst, reg_##scope##_##reg##_offset, index, \
			 STRIDE_##scope##_##reg )
#define REG_ADDR_VECT_X_( inst, offs, index, stride ) \
                          ((inst) + offs + (index) * stride)
#endif

/* Register rw_slave_cfg, scope bif_slave, type rw */
#define reg_bif_slave_rw_slave_cfg___slave_id___lsb 0
#define reg_bif_slave_rw_slave_cfg___slave_id___width 3
#define reg_bif_slave_rw_slave_cfg___use_slave_id___lsb 3
#define reg_bif_slave_rw_slave_cfg___use_slave_id___width 1
#define reg_bif_slave_rw_slave_cfg___use_slave_id___bit 3
#define reg_bif_slave_rw_slave_cfg___boot_rdy___lsb 4
#define reg_bif_slave_rw_slave_cfg___boot_rdy___width 1
#define reg_bif_slave_rw_slave_cfg___boot_rdy___bit 4
#define reg_bif_slave_rw_slave_cfg___loopback___lsb 5
#define reg_bif_slave_rw_slave_cfg___loopback___width 1
#define reg_bif_slave_rw_slave_cfg___loopback___bit 5
#define reg_bif_slave_rw_slave_cfg___dis___lsb 6
#define reg_bif_slave_rw_slave_cfg___dis___width 1
#define reg_bif_slave_rw_slave_cfg___dis___bit 6
#define reg_bif_slave_rw_slave_cfg_offset 0

/* Register r_slave_mode, scope bif_slave, type r */
#define reg_bif_slave_r_slave_mode___ch0_mode___lsb 0
#define reg_bif_slave_r_slave_mode___ch0_mode___width 1
#define reg_bif_slave_r_slave_mode___ch0_mode___bit 0
#define reg_bif_slave_r_slave_mode___ch1_mode___lsb 1
#define reg_bif_slave_r_slave_mode___ch1_mode___width 1
#define reg_bif_slave_r_slave_mode___ch1_mode___bit 1
#define reg_bif_slave_r_slave_mode___ch2_mode___lsb 2
#define reg_bif_slave_r_slave_mode___ch2_mode___width 1
#define reg_bif_slave_r_slave_mode___ch2_mode___bit 2
#define reg_bif_slave_r_slave_mode___ch3_mode___lsb 3
#define reg_bif_slave_r_slave_mode___ch3_mode___width 1
#define reg_bif_slave_r_slave_mode___ch3_mode___bit 3
#define reg_bif_slave_r_slave_mode_offset 4

/* Register rw_ch0_cfg, scope bif_slave, type rw */
#define reg_bif_slave_rw_ch0_cfg___rd_hold___lsb 0
#define reg_bif_slave_rw_ch0_cfg___rd_hold___width 2
#define reg_bif_slave_rw_ch0_cfg___access_mode___lsb 2
#define reg_bif_slave_rw_ch0_cfg___access_mode___width 1
#define reg_bif_slave_rw_ch0_cfg___access_mode___bit 2
#define reg_bif_slave_rw_ch0_cfg___access_ctrl___lsb 3
#define reg_bif_slave_rw_ch0_cfg___access_ctrl___width 1
#define reg_bif_slave_rw_ch0_cfg___access_ctrl___bit 3
#define reg_bif_slave_rw_ch0_cfg___data_cs___lsb 4
#define reg_bif_slave_rw_ch0_cfg___data_cs___width 2
#define reg_bif_slave_rw_ch0_cfg_offset 16

/* Register rw_ch1_cfg, scope bif_slave, type rw */
#define reg_bif_slave_rw_ch1_cfg___rd_hold___lsb 0
#define reg_bif_slave_rw_ch1_cfg___rd_hold___width 2
#define reg_bif_slave_rw_ch1_cfg___access_mode___lsb 2
#define reg_bif_slave_rw_ch1_cfg___access_mode___width 1
#define reg_bif_slave_rw_ch1_cfg___access_mode___bit 2
#define reg_bif_slave_rw_ch1_cfg___access_ctrl___lsb 3
#define reg_bif_slave_rw_ch1_cfg___access_ctrl___width 1
#define reg_bif_slave_rw_ch1_cfg___access_ctrl___bit 3
#define reg_bif_slave_rw_ch1_cfg___data_cs___lsb 4
#define reg_bif_slave_rw_ch1_cfg___data_cs___width 2
#define reg_bif_slave_rw_ch1_cfg_offset 20

/* Register rw_ch2_cfg, scope bif_slave, type rw */
#define reg_bif_slave_rw_ch2_cfg___rd_hold___lsb 0
#define reg_bif_slave_rw_ch2_cfg___rd_hold___width 2
#define reg_bif_slave_rw_ch2_cfg___access_mode___lsb 2
#define reg_bif_slave_rw_ch2_cfg___access_mode___width 1
#define reg_bif_slave_rw_ch2_cfg___access_mode___bit 2
#define reg_bif_slave_rw_ch2_cfg___access_ctrl___lsb 3
#define reg_bif_slave_rw_ch2_cfg___access_ctrl___width 1
#define reg_bif_slave_rw_ch2_cfg___access_ctrl___bit 3
#define reg_bif_slave_rw_ch2_cfg___data_cs___lsb 4
#define reg_bif_slave_rw_ch2_cfg___data_cs___width 2
#define reg_bif_slave_rw_ch2_cfg_offset 24

/* Register rw_ch3_cfg, scope bif_slave, type rw */
#define reg_bif_slave_rw_ch3_cfg___rd_hold___lsb 0
#define reg_bif_slave_rw_ch3_cfg___rd_hold___width 2
#define reg_bif_slave_rw_ch3_cfg___access_mode___lsb 2
#define reg_bif_slave_rw_ch3_cfg___access_mode___width 1
#define reg_bif_slave_rw_ch3_cfg___access_mode___bit 2
#define reg_bif_slave_rw_ch3_cfg___access_ctrl___lsb 3
#define reg_bif_slave_rw_ch3_cfg___access_ctrl___width 1
#define reg_bif_slave_rw_ch3_cfg___access_ctrl___bit 3
#define reg_bif_slave_rw_ch3_cfg___data_cs___lsb 4
#define reg_bif_slave_rw_ch3_cfg___data_cs___width 2
#define reg_bif_slave_rw_ch3_cfg_offset 28

/* Register rw_arb_cfg, scope bif_slave, type rw */
#define reg_bif_slave_rw_arb_cfg___brin_mode___lsb 0
#define reg_bif_slave_rw_arb_cfg___brin_mode___width 1
#define reg_bif_slave_rw_arb_cfg___brin_mode___bit 0
#define reg_bif_slave_rw_arb_cfg___brout_mode___lsb 1
#define reg_bif_slave_rw_arb_cfg___brout_mode___width 3
#define reg_bif_slave_rw_arb_cfg___bg_mode___lsb 4
#define reg_bif_slave_rw_arb_cfg___bg_mode___width 3
#define reg_bif_slave_rw_arb_cfg___release___lsb 7
#define reg_bif_slave_rw_arb_cfg___release___width 2
#define reg_bif_slave_rw_arb_cfg___acquire___lsb 9
#define reg_bif_slave_rw_arb_cfg___acquire___width 1
#define reg_bif_slave_rw_arb_cfg___acquire___bit 9
#define reg_bif_slave_rw_arb_cfg___settle_time___lsb 10
#define reg_bif_slave_rw_arb_cfg___settle_time___width 2
#define reg_bif_slave_rw_arb_cfg___dram_ctrl___lsb 12
#define reg_bif_slave_rw_arb_cfg___dram_ctrl___width 1
#define reg_bif_slave_rw_arb_cfg___dram_ctrl___bit 12
#define reg_bif_slave_rw_arb_cfg_offset 32

/* Register r_arb_stat, scope bif_slave, type r */
#define reg_bif_slave_r_arb_stat___init_mode___lsb 0
#define reg_bif_slave_r_arb_stat___init_mode___width 1
#define reg_bif_slave_r_arb_stat___init_mode___bit 0
#define reg_bif_slave_r_arb_stat___mode___lsb 1
#define reg_bif_slave_r_arb_stat___mode___width 1
#define reg_bif_slave_r_arb_stat___mode___bit 1
#define reg_bif_slave_r_arb_stat___brin___lsb 2
#define reg_bif_slave_r_arb_stat___brin___width 1
#define reg_bif_slave_r_arb_stat___brin___bit 2
#define reg_bif_slave_r_arb_stat___brout___lsb 3
#define reg_bif_slave_r_arb_stat___brout___width 1
#define reg_bif_slave_r_arb_stat___brout___bit 3
#define reg_bif_slave_r_arb_stat___bg___lsb 4
#define reg_bif_slave_r_arb_stat___bg___width 1
#define reg_bif_slave_r_arb_stat___bg___bit 4
#define reg_bif_slave_r_arb_stat_offset 36

/* Register rw_intr_mask, scope bif_slave, type rw */
#define reg_bif_slave_rw_intr_mask___bus_release___lsb 0
#define reg_bif_slave_rw_intr_mask___bus_release___width 1
#define reg_bif_slave_rw_intr_mask___bus_release___bit 0
#define reg_bif_slave_rw_intr_mask___bus_acquire___lsb 1
#define reg_bif_slave_rw_intr_mask___bus_acquire___width 1
#define reg_bif_slave_rw_intr_mask___bus_acquire___bit 1
#define reg_bif_slave_rw_intr_mask_offset 64

/* Register rw_ack_intr, scope bif_slave, type rw */
#define reg_bif_slave_rw_ack_intr___bus_release___lsb 0
#define reg_bif_slave_rw_ack_intr___bus_release___width 1
#define reg_bif_slave_rw_ack_intr___bus_release___bit 0
#define reg_bif_slave_rw_ack_intr___bus_acquire___lsb 1
#define reg_bif_slave_rw_ack_intr___bus_acquire___width 1
#define reg_bif_slave_rw_ack_intr___bus_acquire___bit 1
#define reg_bif_slave_rw_ack_intr_offset 68

/* Register r_intr, scope bif_slave, type r */
#define reg_bif_slave_r_intr___bus_release___lsb 0
#define reg_bif_slave_r_intr___bus_release___width 1
#define reg_bif_slave_r_intr___bus_release___bit 0
#define reg_bif_slave_r_intr___bus_acquire___lsb 1
#define reg_bif_slave_r_intr___bus_acquire___width 1
#define reg_bif_slave_r_intr___bus_acquire___bit 1
#define reg_bif_slave_r_intr_offset 72

/* Register r_masked_intr, scope bif_slave, type r */
#define reg_bif_slave_r_masked_intr___bus_release___lsb 0
#define reg_bif_slave_r_masked_intr___bus_release___width 1
#define reg_bif_slave_r_masked_intr___bus_release___bit 0
#define reg_bif_slave_r_masked_intr___bus_acquire___lsb 1
#define reg_bif_slave_r_masked_intr___bus_acquire___width 1
#define reg_bif_slave_r_masked_intr___bus_acquire___bit 1
#define reg_bif_slave_r_masked_intr_offset 76


/* Constants */
#define regk_bif_slave_active_hi                  0x00000003
#define regk_bif_slave_active_lo                  0x00000002
#define regk_bif_slave_addr                       0x00000000
#define regk_bif_slave_always                     0x00000001
#define regk_bif_slave_at_idle                    0x00000002
#define regk_bif_slave_burst_end                  0x00000003
#define regk_bif_slave_dma                        0x00000001
#define regk_bif_slave_hi                         0x00000003
#define regk_bif_slave_inv                        0x00000001
#define regk_bif_slave_lo                         0x00000002
#define regk_bif_slave_local                      0x00000001
#define regk_bif_slave_master                     0x00000000
#define regk_bif_slave_mode_reg                   0x00000001
#define regk_bif_slave_no                         0x00000000
#define regk_bif_slave_norm                       0x00000000
#define regk_bif_slave_on_access                  0x00000000
#define regk_bif_slave_rw_arb_cfg_default         0x00000000
#define regk_bif_slave_rw_ch0_cfg_default         0x00000000
#define regk_bif_slave_rw_ch1_cfg_default         0x00000000
#define regk_bif_slave_rw_ch2_cfg_default         0x00000000
#define regk_bif_slave_rw_ch3_cfg_default         0x00000000
#define regk_bif_slave_rw_intr_mask_default       0x00000000
#define regk_bif_slave_rw_slave_cfg_default       0x00000000
#define regk_bif_slave_shared                     0x00000000
#define regk_bif_slave_slave                      0x00000001
#define regk_bif_slave_t0ns                       0x00000003
#define regk_bif_slave_t10ns                      0x00000002
#define regk_bif_slave_t20ns                      0x00000003
#define regk_bif_slave_t30ns                      0x00000002
#define regk_bif_slave_t40ns                      0x00000001
#define regk_bif_slave_t50ns                      0x00000000
#define regk_bif_slave_yes                        0x00000001
#define regk_bif_slave_z                          0x00000004
#endif /* __bif_slave_defs_asm_h */
