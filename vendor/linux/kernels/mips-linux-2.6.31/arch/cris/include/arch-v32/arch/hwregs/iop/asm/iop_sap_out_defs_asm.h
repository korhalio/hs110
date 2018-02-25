#ifndef __iop_sap_out_defs_asm_h
#define __iop_sap_out_defs_asm_h

/*
 * This file is autogenerated from
 *   file:           ../../inst/io_proc/rtl/iop_sap_out.r
 *     id:           <not found>
 *     last modfied: Mon Apr 11 16:08:46 2005
 *
 *   by /n/asic/design/tools/rdesc/src/rdes2c -asm --outfile asm/iop_sap_out_defs_asm.h ../../inst/io_proc/rtl/iop_sap_out.r
 *      id: $Id: //depot/sw/releases/Aquila_9.2.0_U11/linux/kernels/mips-linux-2.6.31/arch/cris/include/arch-v32/arch/hwregs/iop/asm/iop_sap_out_defs_asm.h#1 $
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

/* Register rw_gen_gated, scope iop_sap_out, type rw */
#define reg_iop_sap_out_rw_gen_gated___clk0_src___lsb 0
#define reg_iop_sap_out_rw_gen_gated___clk0_src___width 2
#define reg_iop_sap_out_rw_gen_gated___clk0_gate_src___lsb 2
#define reg_iop_sap_out_rw_gen_gated___clk0_gate_src___width 2
#define reg_iop_sap_out_rw_gen_gated___clk0_force_src___lsb 4
#define reg_iop_sap_out_rw_gen_gated___clk0_force_src___width 3
#define reg_iop_sap_out_rw_gen_gated___clk1_src___lsb 7
#define reg_iop_sap_out_rw_gen_gated___clk1_src___width 2
#define reg_iop_sap_out_rw_gen_gated___clk1_gate_src___lsb 9
#define reg_iop_sap_out_rw_gen_gated___clk1_gate_src___width 2
#define reg_iop_sap_out_rw_gen_gated___clk1_force_src___lsb 11
#define reg_iop_sap_out_rw_gen_gated___clk1_force_src___width 3
#define reg_iop_sap_out_rw_gen_gated___clk2_src___lsb 14
#define reg_iop_sap_out_rw_gen_gated___clk2_src___width 2
#define reg_iop_sap_out_rw_gen_gated___clk2_gate_src___lsb 16
#define reg_iop_sap_out_rw_gen_gated___clk2_gate_src___width 2
#define reg_iop_sap_out_rw_gen_gated___clk2_force_src___lsb 18
#define reg_iop_sap_out_rw_gen_gated___clk2_force_src___width 3
#define reg_iop_sap_out_rw_gen_gated___clk3_src___lsb 21
#define reg_iop_sap_out_rw_gen_gated___clk3_src___width 2
#define reg_iop_sap_out_rw_gen_gated___clk3_gate_src___lsb 23
#define reg_iop_sap_out_rw_gen_gated___clk3_gate_src___width 2
#define reg_iop_sap_out_rw_gen_gated___clk3_force_src___lsb 25
#define reg_iop_sap_out_rw_gen_gated___clk3_force_src___width 3
#define reg_iop_sap_out_rw_gen_gated_offset 0

/* Register rw_bus0, scope iop_sap_out, type rw */
#define reg_iop_sap_out_rw_bus0___byte0_clk_sel___lsb 0
#define reg_iop_sap_out_rw_bus0___byte0_clk_sel___width 3
#define reg_iop_sap_out_rw_bus0___byte0_gated_clk___lsb 3
#define reg_iop_sap_out_rw_bus0___byte0_gated_clk___width 2
#define reg_iop_sap_out_rw_bus0___byte0_clk_inv___lsb 5
#define reg_iop_sap_out_rw_bus0___byte0_clk_inv___width 1
#define reg_iop_sap_out_rw_bus0___byte0_clk_inv___bit 5
#define reg_iop_sap_out_rw_bus0___byte1_clk_sel___lsb 6
#define reg_iop_sap_out_rw_bus0___byte1_clk_sel___width 3
#define reg_iop_sap_out_rw_bus0___byte1_gated_clk___lsb 9
#define reg_iop_sap_out_rw_bus0___byte1_gated_clk___width 2
#define reg_iop_sap_out_rw_bus0___byte1_clk_inv___lsb 11
#define reg_iop_sap_out_rw_bus0___byte1_clk_inv___width 1
#define reg_iop_sap_out_rw_bus0___byte1_clk_inv___bit 11
#define reg_iop_sap_out_rw_bus0___byte2_clk_sel___lsb 12
#define reg_iop_sap_out_rw_bus0___byte2_clk_sel___width 3
#define reg_iop_sap_out_rw_bus0___byte2_gated_clk___lsb 15
#define reg_iop_sap_out_rw_bus0___byte2_gated_clk___width 2
#define reg_iop_sap_out_rw_bus0___byte2_clk_inv___lsb 17
#define reg_iop_sap_out_rw_bus0___byte2_clk_inv___width 1
#define reg_iop_sap_out_rw_bus0___byte2_clk_inv___bit 17
#define reg_iop_sap_out_rw_bus0___byte3_clk_sel___lsb 18
#define reg_iop_sap_out_rw_bus0___byte3_clk_sel___width 3
#define reg_iop_sap_out_rw_bus0___byte3_gated_clk___lsb 21
#define reg_iop_sap_out_rw_bus0___byte3_gated_clk___width 2
#define reg_iop_sap_out_rw_bus0___byte3_clk_inv___lsb 23
#define reg_iop_sap_out_rw_bus0___byte3_clk_inv___width 1
#define reg_iop_sap_out_rw_bus0___byte3_clk_inv___bit 23
#define reg_iop_sap_out_rw_bus0_offset 4

/* Register rw_bus1, scope iop_sap_out, type rw */
#define reg_iop_sap_out_rw_bus1___byte0_clk_sel___lsb 0
#define reg_iop_sap_out_rw_bus1___byte0_clk_sel___width 3
#define reg_iop_sap_out_rw_bus1___byte0_gated_clk___lsb 3
#define reg_iop_sap_out_rw_bus1___byte0_gated_clk___width 2
#define reg_iop_sap_out_rw_bus1___byte0_clk_inv___lsb 5
#define reg_iop_sap_out_rw_bus1___byte0_clk_inv___width 1
#define reg_iop_sap_out_rw_bus1___byte0_clk_inv___bit 5
#define reg_iop_sap_out_rw_bus1___byte1_clk_sel___lsb 6
#define reg_iop_sap_out_rw_bus1___byte1_clk_sel___width 3
#define reg_iop_sap_out_rw_bus1___byte1_gated_clk___lsb 9
#define reg_iop_sap_out_rw_bus1___byte1_gated_clk___width 2
#define reg_iop_sap_out_rw_bus1___byte1_clk_inv___lsb 11
#define reg_iop_sap_out_rw_bus1___byte1_clk_inv___width 1
#define reg_iop_sap_out_rw_bus1___byte1_clk_inv___bit 11
#define reg_iop_sap_out_rw_bus1___byte2_clk_sel___lsb 12
#define reg_iop_sap_out_rw_bus1___byte2_clk_sel___width 3
#define reg_iop_sap_out_rw_bus1___byte2_gated_clk___lsb 15
#define reg_iop_sap_out_rw_bus1___byte2_gated_clk___width 2
#define reg_iop_sap_out_rw_bus1___byte2_clk_inv___lsb 17
#define reg_iop_sap_out_rw_bus1___byte2_clk_inv___width 1
#define reg_iop_sap_out_rw_bus1___byte2_clk_inv___bit 17
#define reg_iop_sap_out_rw_bus1___byte3_clk_sel___lsb 18
#define reg_iop_sap_out_rw_bus1___byte3_clk_sel___width 3
#define reg_iop_sap_out_rw_bus1___byte3_gated_clk___lsb 21
#define reg_iop_sap_out_rw_bus1___byte3_gated_clk___width 2
#define reg_iop_sap_out_rw_bus1___byte3_clk_inv___lsb 23
#define reg_iop_sap_out_rw_bus1___byte3_clk_inv___width 1
#define reg_iop_sap_out_rw_bus1___byte3_clk_inv___bit 23
#define reg_iop_sap_out_rw_bus1_offset 8

/* Register rw_bus0_lo_oe, scope iop_sap_out, type rw */
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_clk_sel___lsb 0
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_clk_sel___width 3
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_clk_ext___lsb 3
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_clk_ext___width 3
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_gated_clk___lsb 6
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_gated_clk___width 2
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_clk_inv___lsb 8
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_clk_inv___width 1
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_clk_inv___bit 8
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_logic___lsb 9
#define reg_iop_sap_out_rw_bus0_lo_oe___byte0_logic___width 2
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_clk_sel___lsb 11
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_clk_sel___width 3
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_clk_ext___lsb 14
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_clk_ext___width 3
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_gated_clk___lsb 17
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_gated_clk___width 2
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_clk_inv___lsb 19
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_clk_inv___width 1
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_clk_inv___bit 19
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_logic___lsb 20
#define reg_iop_sap_out_rw_bus0_lo_oe___byte1_logic___width 2
#define reg_iop_sap_out_rw_bus0_lo_oe_offset 12

/* Register rw_bus0_hi_oe, scope iop_sap_out, type rw */
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_clk_sel___lsb 0
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_clk_sel___width 3
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_clk_ext___lsb 3
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_clk_ext___width 3
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_gated_clk___lsb 6
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_gated_clk___width 2
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_clk_inv___lsb 8
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_clk_inv___width 1
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_clk_inv___bit 8
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_logic___lsb 9
#define reg_iop_sap_out_rw_bus0_hi_oe___byte2_logic___width 2
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_clk_sel___lsb 11
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_clk_sel___width 3
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_clk_ext___lsb 14
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_clk_ext___width 3
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_gated_clk___lsb 17
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_gated_clk___width 2
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_clk_inv___lsb 19
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_clk_inv___width 1
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_clk_inv___bit 19
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_logic___lsb 20
#define reg_iop_sap_out_rw_bus0_hi_oe___byte3_logic___width 2
#define reg_iop_sap_out_rw_bus0_hi_oe_offset 16

/* Register rw_bus1_lo_oe, scope iop_sap_out, type rw */
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_clk_sel___lsb 0
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_clk_sel___width 3
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_clk_ext___lsb 3
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_clk_ext___width 3
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_gated_clk___lsb 6
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_gated_clk___width 2
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_clk_inv___lsb 8
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_clk_inv___width 1
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_clk_inv___bit 8
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_logic___lsb 9
#define reg_iop_sap_out_rw_bus1_lo_oe___byte0_logic___width 2
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_clk_sel___lsb 11
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_clk_sel___width 3
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_clk_ext___lsb 14
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_clk_ext___width 3
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_gated_clk___lsb 17
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_gated_clk___width 2
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_clk_inv___lsb 19
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_clk_inv___width 1
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_clk_inv___bit 19
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_logic___lsb 20
#define reg_iop_sap_out_rw_bus1_lo_oe___byte1_logic___width 2
#define reg_iop_sap_out_rw_bus1_lo_oe_offset 20

/* Register rw_bus1_hi_oe, scope iop_sap_out, type rw */
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_clk_sel___lsb 0
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_clk_sel___width 3
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_clk_ext___lsb 3
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_clk_ext___width 3
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_gated_clk___lsb 6
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_gated_clk___width 2
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_clk_inv___lsb 8
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_clk_inv___width 1
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_clk_inv___bit 8
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_logic___lsb 9
#define reg_iop_sap_out_rw_bus1_hi_oe___byte2_logic___width 2
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_clk_sel___lsb 11
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_clk_sel___width 3
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_clk_ext___lsb 14
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_clk_ext___width 3
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_gated_clk___lsb 17
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_gated_clk___width 2
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_clk_inv___lsb 19
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_clk_inv___width 1
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_clk_inv___bit 19
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_logic___lsb 20
#define reg_iop_sap_out_rw_bus1_hi_oe___byte3_logic___width 2
#define reg_iop_sap_out_rw_bus1_hi_oe_offset 24

#define STRIDE_iop_sap_out_rw_gio 4
/* Register rw_gio, scope iop_sap_out, type rw */
#define reg_iop_sap_out_rw_gio___out_clk_sel___lsb 0
#define reg_iop_sap_out_rw_gio___out_clk_sel___width 3
#define reg_iop_sap_out_rw_gio___out_clk_ext___lsb 3
#define reg_iop_sap_out_rw_gio___out_clk_ext___width 4
#define reg_iop_sap_out_rw_gio___out_gated_clk___lsb 7
#define reg_iop_sap_out_rw_gio___out_gated_clk___width 2
#define reg_iop_sap_out_rw_gio___out_clk_inv___lsb 9
#define reg_iop_sap_out_rw_gio___out_clk_inv___width 1
#define reg_iop_sap_out_rw_gio___out_clk_inv___bit 9
#define reg_iop_sap_out_rw_gio___out_logic___lsb 10
#define reg_iop_sap_out_rw_gio___out_logic___width 1
#define reg_iop_sap_out_rw_gio___out_logic___bit 10
#define reg_iop_sap_out_rw_gio___oe_clk_sel___lsb 11
#define reg_iop_sap_out_rw_gio___oe_clk_sel___width 3
#define reg_iop_sap_out_rw_gio___oe_clk_ext___lsb 14
#define reg_iop_sap_out_rw_gio___oe_clk_ext___width 3
#define reg_iop_sap_out_rw_gio___oe_gated_clk___lsb 17
#define reg_iop_sap_out_rw_gio___oe_gated_clk___width 2
#define reg_iop_sap_out_rw_gio___oe_clk_inv___lsb 19
#define reg_iop_sap_out_rw_gio___oe_clk_inv___width 1
#define reg_iop_sap_out_rw_gio___oe_clk_inv___bit 19
#define reg_iop_sap_out_rw_gio___oe_logic___lsb 20
#define reg_iop_sap_out_rw_gio___oe_logic___width 2
#define reg_iop_sap_out_rw_gio_offset 28


/* Constants */
#define regk_iop_sap_out_and                      0x00000002
#define regk_iop_sap_out_clk0                     0x00000000
#define regk_iop_sap_out_clk1                     0x00000001
#define regk_iop_sap_out_clk12                    0x00000002
#define regk_iop_sap_out_clk2                     0x00000002
#define regk_iop_sap_out_clk200                   0x00000001
#define regk_iop_sap_out_clk3                     0x00000003
#define regk_iop_sap_out_ext                      0x00000003
#define regk_iop_sap_out_gated                    0x00000004
#define regk_iop_sap_out_gio1                     0x00000000
#define regk_iop_sap_out_gio13                    0x00000002
#define regk_iop_sap_out_gio13_clk                0x0000000c
#define regk_iop_sap_out_gio15                    0x00000001
#define regk_iop_sap_out_gio18                    0x00000003
#define regk_iop_sap_out_gio18_clk                0x0000000d
#define regk_iop_sap_out_gio1_clk                 0x00000008
#define regk_iop_sap_out_gio21_clk                0x0000000e
#define regk_iop_sap_out_gio23                    0x00000002
#define regk_iop_sap_out_gio29_clk                0x0000000f
#define regk_iop_sap_out_gio31                    0x00000003
#define regk_iop_sap_out_gio5                     0x00000001
#define regk_iop_sap_out_gio5_clk                 0x00000009
#define regk_iop_sap_out_gio6_clk                 0x0000000a
#define regk_iop_sap_out_gio7                     0x00000000
#define regk_iop_sap_out_gio7_clk                 0x0000000b
#define regk_iop_sap_out_gio_in13                 0x00000001
#define regk_iop_sap_out_gio_in21                 0x00000002
#define regk_iop_sap_out_gio_in29                 0x00000003
#define regk_iop_sap_out_gio_in5                  0x00000000
#define regk_iop_sap_out_inv                      0x00000001
#define regk_iop_sap_out_nand                     0x00000003
#define regk_iop_sap_out_no                       0x00000000
#define regk_iop_sap_out_none                     0x00000000
#define regk_iop_sap_out_rw_bus0_default          0x00000000
#define regk_iop_sap_out_rw_bus0_hi_oe_default    0x00000000
#define regk_iop_sap_out_rw_bus0_lo_oe_default    0x00000000
#define regk_iop_sap_out_rw_bus1_default          0x00000000
#define regk_iop_sap_out_rw_bus1_hi_oe_default    0x00000000
#define regk_iop_sap_out_rw_bus1_lo_oe_default    0x00000000
#define regk_iop_sap_out_rw_gen_gated_default     0x00000000
#define regk_iop_sap_out_rw_gio_default           0x00000000
#define regk_iop_sap_out_rw_gio_size              0x00000020
#define regk_iop_sap_out_spu0_gio0                0x00000002
#define regk_iop_sap_out_spu0_gio1                0x00000003
#define regk_iop_sap_out_spu0_gio12               0x00000004
#define regk_iop_sap_out_spu0_gio13               0x00000004
#define regk_iop_sap_out_spu0_gio14               0x00000004
#define regk_iop_sap_out_spu0_gio15               0x00000004
#define regk_iop_sap_out_spu0_gio2                0x00000002
#define regk_iop_sap_out_spu0_gio3                0x00000003
#define regk_iop_sap_out_spu0_gio4                0x00000002
#define regk_iop_sap_out_spu0_gio5                0x00000003
#define regk_iop_sap_out_spu0_gio6                0x00000002
#define regk_iop_sap_out_spu0_gio7                0x00000003
#define regk_iop_sap_out_spu1_gio0                0x00000005
#define regk_iop_sap_out_spu1_gio1                0x00000006
#define regk_iop_sap_out_spu1_gio12               0x00000007
#define regk_iop_sap_out_spu1_gio13               0x00000007
#define regk_iop_sap_out_spu1_gio14               0x00000007
#define regk_iop_sap_out_spu1_gio15               0x00000007
#define regk_iop_sap_out_spu1_gio2                0x00000005
#define regk_iop_sap_out_spu1_gio3                0x00000006
#define regk_iop_sap_out_spu1_gio4                0x00000005
#define regk_iop_sap_out_spu1_gio5                0x00000006
#define regk_iop_sap_out_spu1_gio6                0x00000005
#define regk_iop_sap_out_spu1_gio7                0x00000006
#define regk_iop_sap_out_timer_grp0_tmr2          0x00000004
#define regk_iop_sap_out_timer_grp1_tmr2          0x00000005
#define regk_iop_sap_out_timer_grp2_tmr2          0x00000006
#define regk_iop_sap_out_timer_grp3_tmr2          0x00000007
#define regk_iop_sap_out_tmr                      0x00000005
#define regk_iop_sap_out_yes                      0x00000001
#endif /* __iop_sap_out_defs_asm_h */
