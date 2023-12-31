/*******************************************************************************
* File Name: cyfittergnu.inc
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* LED */
.set LED__0__INTTYPE, CYREG_PICU2_INTTYPE1
.set LED__0__MASK, 0x02
.set LED__0__PC, CYREG_PRT2_PC1
.set LED__0__PORT, 2
.set LED__0__SHIFT, 1
.set LED__AG, CYREG_PRT2_AG
.set LED__AMUX, CYREG_PRT2_AMUX
.set LED__BIE, CYREG_PRT2_BIE
.set LED__BIT_MASK, CYREG_PRT2_BIT_MASK
.set LED__BYP, CYREG_PRT2_BYP
.set LED__CTL, CYREG_PRT2_CTL
.set LED__DM0, CYREG_PRT2_DM0
.set LED__DM1, CYREG_PRT2_DM1
.set LED__DM2, CYREG_PRT2_DM2
.set LED__DR, CYREG_PRT2_DR
.set LED__INP_DIS, CYREG_PRT2_INP_DIS
.set LED__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set LED__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set LED__LCD_EN, CYREG_PRT2_LCD_EN
.set LED__MASK, 0x02
.set LED__PORT, 2
.set LED__PRT, CYREG_PRT2_PRT
.set LED__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set LED__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set LED__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set LED__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set LED__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set LED__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set LED__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set LED__PS, CYREG_PRT2_PS
.set LED__SHIFT, 1
.set LED__SLW, CYREG_PRT2_SLW

/* SS_1 */
.set SS_1__0__INTTYPE, CYREG_PICU1_INTTYPE7
.set SS_1__0__MASK, 0x80
.set SS_1__0__PC, CYREG_PRT1_PC7
.set SS_1__0__PORT, 1
.set SS_1__0__SHIFT, 7
.set SS_1__AG, CYREG_PRT1_AG
.set SS_1__AMUX, CYREG_PRT1_AMUX
.set SS_1__BIE, CYREG_PRT1_BIE
.set SS_1__BIT_MASK, CYREG_PRT1_BIT_MASK
.set SS_1__BYP, CYREG_PRT1_BYP
.set SS_1__CTL, CYREG_PRT1_CTL
.set SS_1__DM0, CYREG_PRT1_DM0
.set SS_1__DM1, CYREG_PRT1_DM1
.set SS_1__DM2, CYREG_PRT1_DM2
.set SS_1__DR, CYREG_PRT1_DR
.set SS_1__INP_DIS, CYREG_PRT1_INP_DIS
.set SS_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU1_BASE
.set SS_1__LCD_COM_SEG, CYREG_PRT1_LCD_COM_SEG
.set SS_1__LCD_EN, CYREG_PRT1_LCD_EN
.set SS_1__MASK, 0x80
.set SS_1__PORT, 1
.set SS_1__PRT, CYREG_PRT1_PRT
.set SS_1__PRTDSI__CAPS_SEL, CYREG_PRT1_CAPS_SEL
.set SS_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT1_DBL_SYNC_IN
.set SS_1__PRTDSI__OE_SEL0, CYREG_PRT1_OE_SEL0
.set SS_1__PRTDSI__OE_SEL1, CYREG_PRT1_OE_SEL1
.set SS_1__PRTDSI__OUT_SEL0, CYREG_PRT1_OUT_SEL0
.set SS_1__PRTDSI__OUT_SEL1, CYREG_PRT1_OUT_SEL1
.set SS_1__PRTDSI__SYNC_OUT, CYREG_PRT1_SYNC_OUT
.set SS_1__PS, CYREG_PRT1_PS
.set SS_1__SHIFT, 7
.set SS_1__SLW, CYREG_PRT1_SLW

/* MISO_1 */
.set MISO_1__0__INTTYPE, CYREG_PICU1_INTTYPE6
.set MISO_1__0__MASK, 0x40
.set MISO_1__0__PC, CYREG_PRT1_PC6
.set MISO_1__0__PORT, 1
.set MISO_1__0__SHIFT, 6
.set MISO_1__AG, CYREG_PRT1_AG
.set MISO_1__AMUX, CYREG_PRT1_AMUX
.set MISO_1__BIE, CYREG_PRT1_BIE
.set MISO_1__BIT_MASK, CYREG_PRT1_BIT_MASK
.set MISO_1__BYP, CYREG_PRT1_BYP
.set MISO_1__CTL, CYREG_PRT1_CTL
.set MISO_1__DM0, CYREG_PRT1_DM0
.set MISO_1__DM1, CYREG_PRT1_DM1
.set MISO_1__DM2, CYREG_PRT1_DM2
.set MISO_1__DR, CYREG_PRT1_DR
.set MISO_1__INP_DIS, CYREG_PRT1_INP_DIS
.set MISO_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU1_BASE
.set MISO_1__LCD_COM_SEG, CYREG_PRT1_LCD_COM_SEG
.set MISO_1__LCD_EN, CYREG_PRT1_LCD_EN
.set MISO_1__MASK, 0x40
.set MISO_1__PORT, 1
.set MISO_1__PRT, CYREG_PRT1_PRT
.set MISO_1__PRTDSI__CAPS_SEL, CYREG_PRT1_CAPS_SEL
.set MISO_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT1_DBL_SYNC_IN
.set MISO_1__PRTDSI__OE_SEL0, CYREG_PRT1_OE_SEL0
.set MISO_1__PRTDSI__OE_SEL1, CYREG_PRT1_OE_SEL1
.set MISO_1__PRTDSI__OUT_SEL0, CYREG_PRT1_OUT_SEL0
.set MISO_1__PRTDSI__OUT_SEL1, CYREG_PRT1_OUT_SEL1
.set MISO_1__PRTDSI__SYNC_OUT, CYREG_PRT1_SYNC_OUT
.set MISO_1__PS, CYREG_PRT1_PS
.set MISO_1__SHIFT, 6
.set MISO_1__SLW, CYREG_PRT1_SLW

/* MOSI_1 */
.set MOSI_1__0__INTTYPE, CYREG_PICU15_INTTYPE4
.set MOSI_1__0__MASK, 0x10
.set MOSI_1__0__PC, CYREG_IO_PC_PRT15_PC4
.set MOSI_1__0__PORT, 15
.set MOSI_1__0__SHIFT, 4
.set MOSI_1__AG, CYREG_PRT15_AG
.set MOSI_1__AMUX, CYREG_PRT15_AMUX
.set MOSI_1__BIE, CYREG_PRT15_BIE
.set MOSI_1__BIT_MASK, CYREG_PRT15_BIT_MASK
.set MOSI_1__BYP, CYREG_PRT15_BYP
.set MOSI_1__CTL, CYREG_PRT15_CTL
.set MOSI_1__DM0, CYREG_PRT15_DM0
.set MOSI_1__DM1, CYREG_PRT15_DM1
.set MOSI_1__DM2, CYREG_PRT15_DM2
.set MOSI_1__DR, CYREG_PRT15_DR
.set MOSI_1__INP_DIS, CYREG_PRT15_INP_DIS
.set MOSI_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set MOSI_1__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set MOSI_1__LCD_EN, CYREG_PRT15_LCD_EN
.set MOSI_1__MASK, 0x10
.set MOSI_1__PORT, 15
.set MOSI_1__PRT, CYREG_PRT15_PRT
.set MOSI_1__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set MOSI_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set MOSI_1__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set MOSI_1__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set MOSI_1__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set MOSI_1__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set MOSI_1__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set MOSI_1__PS, CYREG_PRT15_PS
.set MOSI_1__SHIFT, 4
.set MOSI_1__SLW, CYREG_PRT15_SLW

/* SCLK_1 */
.set SCLK_1__0__INTTYPE, CYREG_PICU15_INTTYPE5
.set SCLK_1__0__MASK, 0x20
.set SCLK_1__0__PC, CYREG_IO_PC_PRT15_PC5
.set SCLK_1__0__PORT, 15
.set SCLK_1__0__SHIFT, 5
.set SCLK_1__AG, CYREG_PRT15_AG
.set SCLK_1__AMUX, CYREG_PRT15_AMUX
.set SCLK_1__BIE, CYREG_PRT15_BIE
.set SCLK_1__BIT_MASK, CYREG_PRT15_BIT_MASK
.set SCLK_1__BYP, CYREG_PRT15_BYP
.set SCLK_1__CTL, CYREG_PRT15_CTL
.set SCLK_1__DM0, CYREG_PRT15_DM0
.set SCLK_1__DM1, CYREG_PRT15_DM1
.set SCLK_1__DM2, CYREG_PRT15_DM2
.set SCLK_1__DR, CYREG_PRT15_DR
.set SCLK_1__INP_DIS, CYREG_PRT15_INP_DIS
.set SCLK_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU15_BASE
.set SCLK_1__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set SCLK_1__LCD_EN, CYREG_PRT15_LCD_EN
.set SCLK_1__MASK, 0x20
.set SCLK_1__PORT, 15
.set SCLK_1__PRT, CYREG_PRT15_PRT
.set SCLK_1__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set SCLK_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set SCLK_1__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set SCLK_1__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set SCLK_1__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set SCLK_1__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set SCLK_1__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set SCLK_1__PS, CYREG_PRT15_PS
.set SCLK_1__SHIFT, 5
.set SCLK_1__SLW, CYREG_PRT15_SLW

/* SPIS_1 */
.set SPIS_1_BSPIS_BitCounter__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB10_11_ACTL
.set SPIS_1_BSPIS_BitCounter__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB10_11_CTL
.set SPIS_1_BSPIS_BitCounter__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB10_11_CTL
.set SPIS_1_BSPIS_BitCounter__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB10_11_CTL
.set SPIS_1_BSPIS_BitCounter__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB10_11_CTL
.set SPIS_1_BSPIS_BitCounter__16BIT_MASK_MASK_REG, CYREG_B0_UDB10_11_MSK
.set SPIS_1_BSPIS_BitCounter__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB10_11_MSK
.set SPIS_1_BSPIS_BitCounter__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB10_11_MSK
.set SPIS_1_BSPIS_BitCounter__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB10_11_MSK
.set SPIS_1_BSPIS_BitCounter__CONTROL_AUX_CTL_REG, CYREG_B0_UDB10_ACTL
.set SPIS_1_BSPIS_BitCounter__CONTROL_REG, CYREG_B0_UDB10_CTL
.set SPIS_1_BSPIS_BitCounter__CONTROL_ST_REG, CYREG_B0_UDB10_ST_CTL
.set SPIS_1_BSPIS_BitCounter__COUNT_REG, CYREG_B0_UDB10_CTL
.set SPIS_1_BSPIS_BitCounter__COUNT_ST_REG, CYREG_B0_UDB10_ST_CTL
.set SPIS_1_BSPIS_BitCounter__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set SPIS_1_BSPIS_BitCounter__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set SPIS_1_BSPIS_BitCounter__PERIOD_REG, CYREG_B0_UDB10_MSK
.set SPIS_1_BSPIS_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB10_11_ACTL
.set SPIS_1_BSPIS_BitCounter_ST__16BIT_STATUS_REG, CYREG_B0_UDB10_11_ST
.set SPIS_1_BSPIS_BitCounter_ST__MASK_REG, CYREG_B0_UDB10_MSK
.set SPIS_1_BSPIS_BitCounter_ST__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set SPIS_1_BSPIS_BitCounter_ST__PER_ST_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set SPIS_1_BSPIS_BitCounter_ST__STATUS_AUX_CTL_REG, CYREG_B0_UDB10_ACTL
.set SPIS_1_BSPIS_BitCounter_ST__STATUS_CNT_REG, CYREG_B0_UDB10_ST_CTL
.set SPIS_1_BSPIS_BitCounter_ST__STATUS_CONTROL_REG, CYREG_B0_UDB10_ST_CTL
.set SPIS_1_BSPIS_BitCounter_ST__STATUS_REG, CYREG_B0_UDB10_ST
.set SPIS_1_BSPIS_RxStsReg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB11_12_ACTL
.set SPIS_1_BSPIS_RxStsReg__16BIT_STATUS_REG, CYREG_B0_UDB11_12_ST
.set SPIS_1_BSPIS_RxStsReg__3__MASK, 0x08
.set SPIS_1_BSPIS_RxStsReg__3__POS, 3
.set SPIS_1_BSPIS_RxStsReg__4__MASK, 0x10
.set SPIS_1_BSPIS_RxStsReg__4__POS, 4
.set SPIS_1_BSPIS_RxStsReg__5__MASK, 0x20
.set SPIS_1_BSPIS_RxStsReg__5__POS, 5
.set SPIS_1_BSPIS_RxStsReg__6__MASK, 0x40
.set SPIS_1_BSPIS_RxStsReg__6__POS, 6
.set SPIS_1_BSPIS_RxStsReg__MASK, 0x78
.set SPIS_1_BSPIS_RxStsReg__MASK_REG, CYREG_B0_UDB11_MSK
.set SPIS_1_BSPIS_RxStsReg__STATUS_AUX_CTL_REG, CYREG_B0_UDB11_ACTL
.set SPIS_1_BSPIS_RxStsReg__STATUS_REG, CYREG_B0_UDB11_ST
.set SPIS_1_BSPIS_sR16_Dp_u0__16BIT_A0_REG, CYREG_B0_UDB10_11_A0
.set SPIS_1_BSPIS_sR16_Dp_u0__16BIT_A1_REG, CYREG_B0_UDB10_11_A1
.set SPIS_1_BSPIS_sR16_Dp_u0__16BIT_D0_REG, CYREG_B0_UDB10_11_D0
.set SPIS_1_BSPIS_sR16_Dp_u0__16BIT_D1_REG, CYREG_B0_UDB10_11_D1
.set SPIS_1_BSPIS_sR16_Dp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB10_11_ACTL
.set SPIS_1_BSPIS_sR16_Dp_u0__16BIT_F0_REG, CYREG_B0_UDB10_11_F0
.set SPIS_1_BSPIS_sR16_Dp_u0__16BIT_F1_REG, CYREG_B0_UDB10_11_F1
.set SPIS_1_BSPIS_sR16_Dp_u0__A0_A1_REG, CYREG_B0_UDB10_A0_A1
.set SPIS_1_BSPIS_sR16_Dp_u0__A0_REG, CYREG_B0_UDB10_A0
.set SPIS_1_BSPIS_sR16_Dp_u0__A1_REG, CYREG_B0_UDB10_A1
.set SPIS_1_BSPIS_sR16_Dp_u0__D0_D1_REG, CYREG_B0_UDB10_D0_D1
.set SPIS_1_BSPIS_sR16_Dp_u0__D0_REG, CYREG_B0_UDB10_D0
.set SPIS_1_BSPIS_sR16_Dp_u0__D1_REG, CYREG_B0_UDB10_D1
.set SPIS_1_BSPIS_sR16_Dp_u0__DP_AUX_CTL_REG, CYREG_B0_UDB10_ACTL
.set SPIS_1_BSPIS_sR16_Dp_u0__F0_F1_REG, CYREG_B0_UDB10_F0_F1
.set SPIS_1_BSPIS_sR16_Dp_u0__F0_REG, CYREG_B0_UDB10_F0
.set SPIS_1_BSPIS_sR16_Dp_u0__F1_REG, CYREG_B0_UDB10_F1
.set SPIS_1_BSPIS_sR16_Dp_u0__MSK_DP_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set SPIS_1_BSPIS_sR16_Dp_u0__PER_DP_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set SPIS_1_BSPIS_sR16_Dp_u1__16BIT_A0_REG, CYREG_B0_UDB11_12_A0
.set SPIS_1_BSPIS_sR16_Dp_u1__16BIT_A1_REG, CYREG_B0_UDB11_12_A1
.set SPIS_1_BSPIS_sR16_Dp_u1__16BIT_D0_REG, CYREG_B0_UDB11_12_D0
.set SPIS_1_BSPIS_sR16_Dp_u1__16BIT_D1_REG, CYREG_B0_UDB11_12_D1
.set SPIS_1_BSPIS_sR16_Dp_u1__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB11_12_ACTL
.set SPIS_1_BSPIS_sR16_Dp_u1__16BIT_F0_REG, CYREG_B0_UDB11_12_F0
.set SPIS_1_BSPIS_sR16_Dp_u1__16BIT_F1_REG, CYREG_B0_UDB11_12_F1
.set SPIS_1_BSPIS_sR16_Dp_u1__A0_A1_REG, CYREG_B0_UDB11_A0_A1
.set SPIS_1_BSPIS_sR16_Dp_u1__A0_REG, CYREG_B0_UDB11_A0
.set SPIS_1_BSPIS_sR16_Dp_u1__A1_REG, CYREG_B0_UDB11_A1
.set SPIS_1_BSPIS_sR16_Dp_u1__D0_D1_REG, CYREG_B0_UDB11_D0_D1
.set SPIS_1_BSPIS_sR16_Dp_u1__D0_REG, CYREG_B0_UDB11_D0
.set SPIS_1_BSPIS_sR16_Dp_u1__D1_REG, CYREG_B0_UDB11_D1
.set SPIS_1_BSPIS_sR16_Dp_u1__DP_AUX_CTL_REG, CYREG_B0_UDB11_ACTL
.set SPIS_1_BSPIS_sR16_Dp_u1__F0_F1_REG, CYREG_B0_UDB11_F0_F1
.set SPIS_1_BSPIS_sR16_Dp_u1__F0_REG, CYREG_B0_UDB11_F0
.set SPIS_1_BSPIS_sR16_Dp_u1__F1_REG, CYREG_B0_UDB11_F1
.set SPIS_1_BSPIS_TxStsReg__0__MASK, 0x01
.set SPIS_1_BSPIS_TxStsReg__0__POS, 0
.set SPIS_1_BSPIS_TxStsReg__1__MASK, 0x02
.set SPIS_1_BSPIS_TxStsReg__1__POS, 1
.set SPIS_1_BSPIS_TxStsReg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB12_13_ACTL
.set SPIS_1_BSPIS_TxStsReg__16BIT_STATUS_REG, CYREG_B0_UDB12_13_ST
.set SPIS_1_BSPIS_TxStsReg__2__MASK, 0x04
.set SPIS_1_BSPIS_TxStsReg__2__POS, 2
.set SPIS_1_BSPIS_TxStsReg__6__MASK, 0x40
.set SPIS_1_BSPIS_TxStsReg__6__POS, 6
.set SPIS_1_BSPIS_TxStsReg__MASK, 0x47
.set SPIS_1_BSPIS_TxStsReg__MASK_REG, CYREG_B0_UDB12_MSK
.set SPIS_1_BSPIS_TxStsReg__STATUS_AUX_CTL_REG, CYREG_B0_UDB12_ACTL
.set SPIS_1_BSPIS_TxStsReg__STATUS_REG, CYREG_B0_UDB12_ST
.set SPIS_1_IntClock__CFG0, CYREG_CLKDIST_DCFG1_CFG0
.set SPIS_1_IntClock__CFG1, CYREG_CLKDIST_DCFG1_CFG1
.set SPIS_1_IntClock__CFG2, CYREG_CLKDIST_DCFG1_CFG2
.set SPIS_1_IntClock__CFG2_SRC_SEL_MASK, 0x07
.set SPIS_1_IntClock__INDEX, 0x01
.set SPIS_1_IntClock__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set SPIS_1_IntClock__PM_ACT_MSK, 0x02
.set SPIS_1_IntClock__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set SPIS_1_IntClock__PM_STBY_MSK, 0x02

/* Pin_ADC_in */
.set Pin_ADC_in__0__INTTYPE, CYREG_PICU0_INTTYPE0
.set Pin_ADC_in__0__MASK, 0x01
.set Pin_ADC_in__0__PC, CYREG_PRT0_PC0
.set Pin_ADC_in__0__PORT, 0
.set Pin_ADC_in__0__SHIFT, 0
.set Pin_ADC_in__AG, CYREG_PRT0_AG
.set Pin_ADC_in__AMUX, CYREG_PRT0_AMUX
.set Pin_ADC_in__BIE, CYREG_PRT0_BIE
.set Pin_ADC_in__BIT_MASK, CYREG_PRT0_BIT_MASK
.set Pin_ADC_in__BYP, CYREG_PRT0_BYP
.set Pin_ADC_in__CTL, CYREG_PRT0_CTL
.set Pin_ADC_in__DM0, CYREG_PRT0_DM0
.set Pin_ADC_in__DM1, CYREG_PRT0_DM1
.set Pin_ADC_in__DM2, CYREG_PRT0_DM2
.set Pin_ADC_in__DR, CYREG_PRT0_DR
.set Pin_ADC_in__INP_DIS, CYREG_PRT0_INP_DIS
.set Pin_ADC_in__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU0_BASE
.set Pin_ADC_in__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set Pin_ADC_in__LCD_EN, CYREG_PRT0_LCD_EN
.set Pin_ADC_in__MASK, 0x01
.set Pin_ADC_in__PORT, 0
.set Pin_ADC_in__PRT, CYREG_PRT0_PRT
.set Pin_ADC_in__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set Pin_ADC_in__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set Pin_ADC_in__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set Pin_ADC_in__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set Pin_ADC_in__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set Pin_ADC_in__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set Pin_ADC_in__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set Pin_ADC_in__PS, CYREG_PRT0_PS
.set Pin_ADC_in__SHIFT, 0
.set Pin_ADC_in__SLW, CYREG_PRT0_SLW

/* ADC_DelSig_1 */
.set ADC_DelSig_1_DEC__COHER, CYREG_DEC_COHER
.set ADC_DelSig_1_DEC__CR, CYREG_DEC_CR
.set ADC_DelSig_1_DEC__DR1, CYREG_DEC_DR1
.set ADC_DelSig_1_DEC__DR2, CYREG_DEC_DR2
.set ADC_DelSig_1_DEC__DR2H, CYREG_DEC_DR2H
.set ADC_DelSig_1_DEC__GCOR, CYREG_DEC_GCOR
.set ADC_DelSig_1_DEC__GCORH, CYREG_DEC_GCORH
.set ADC_DelSig_1_DEC__GVAL, CYREG_DEC_GVAL
.set ADC_DelSig_1_DEC__OCOR, CYREG_DEC_OCOR
.set ADC_DelSig_1_DEC__OCORH, CYREG_DEC_OCORH
.set ADC_DelSig_1_DEC__OCORM, CYREG_DEC_OCORM
.set ADC_DelSig_1_DEC__OUTSAMP, CYREG_DEC_OUTSAMP
.set ADC_DelSig_1_DEC__OUTSAMPH, CYREG_DEC_OUTSAMPH
.set ADC_DelSig_1_DEC__OUTSAMPM, CYREG_DEC_OUTSAMPM
.set ADC_DelSig_1_DEC__OUTSAMPS, CYREG_DEC_OUTSAMPS
.set ADC_DelSig_1_DEC__PM_ACT_CFG, CYREG_PM_ACT_CFG10
.set ADC_DelSig_1_DEC__PM_ACT_MSK, 0x01
.set ADC_DelSig_1_DEC__PM_STBY_CFG, CYREG_PM_STBY_CFG10
.set ADC_DelSig_1_DEC__PM_STBY_MSK, 0x01
.set ADC_DelSig_1_DEC__SHIFT1, CYREG_DEC_SHIFT1
.set ADC_DelSig_1_DEC__SHIFT2, CYREG_DEC_SHIFT2
.set ADC_DelSig_1_DEC__SR, CYREG_DEC_SR
.set ADC_DelSig_1_DEC__TRIM__M1, CYREG_FLSHID_CUST_TABLES_DEC_M1
.set ADC_DelSig_1_DEC__TRIM__M2, CYREG_FLSHID_CUST_TABLES_DEC_M2
.set ADC_DelSig_1_DEC__TRIM__M3, CYREG_FLSHID_CUST_TABLES_DEC_M3
.set ADC_DelSig_1_DEC__TRIM__M4, CYREG_FLSHID_CUST_TABLES_DEC_M4
.set ADC_DelSig_1_DEC__TRIM__M5, CYREG_FLSHID_CUST_TABLES_DEC_M5
.set ADC_DelSig_1_DEC__TRIM__M6, CYREG_FLSHID_CUST_TABLES_DEC_M6
.set ADC_DelSig_1_DEC__TRIM__M7, CYREG_FLSHID_CUST_TABLES_DEC_M7
.set ADC_DelSig_1_DEC__TRIM__M8, CYREG_FLSHID_CUST_TABLES_DEC_M8
.set ADC_DelSig_1_DSM__BUF0, CYREG_DSM0_BUF0
.set ADC_DelSig_1_DSM__BUF1, CYREG_DSM0_BUF1
.set ADC_DelSig_1_DSM__BUF2, CYREG_DSM0_BUF2
.set ADC_DelSig_1_DSM__BUF3, CYREG_DSM0_BUF3
.set ADC_DelSig_1_DSM__CLK, CYREG_DSM0_CLK
.set ADC_DelSig_1_DSM__CR0, CYREG_DSM0_CR0
.set ADC_DelSig_1_DSM__CR1, CYREG_DSM0_CR1
.set ADC_DelSig_1_DSM__CR10, CYREG_DSM0_CR10
.set ADC_DelSig_1_DSM__CR11, CYREG_DSM0_CR11
.set ADC_DelSig_1_DSM__CR12, CYREG_DSM0_CR12
.set ADC_DelSig_1_DSM__CR13, CYREG_DSM0_CR13
.set ADC_DelSig_1_DSM__CR14, CYREG_DSM0_CR14
.set ADC_DelSig_1_DSM__CR15, CYREG_DSM0_CR15
.set ADC_DelSig_1_DSM__CR16, CYREG_DSM0_CR16
.set ADC_DelSig_1_DSM__CR17, CYREG_DSM0_CR17
.set ADC_DelSig_1_DSM__CR2, CYREG_DSM0_CR2
.set ADC_DelSig_1_DSM__CR3, CYREG_DSM0_CR3
.set ADC_DelSig_1_DSM__CR4, CYREG_DSM0_CR4
.set ADC_DelSig_1_DSM__CR5, CYREG_DSM0_CR5
.set ADC_DelSig_1_DSM__CR6, CYREG_DSM0_CR6
.set ADC_DelSig_1_DSM__CR7, CYREG_DSM0_CR7
.set ADC_DelSig_1_DSM__CR8, CYREG_DSM0_CR8
.set ADC_DelSig_1_DSM__CR9, CYREG_DSM0_CR9
.set ADC_DelSig_1_DSM__DEM0, CYREG_DSM0_DEM0
.set ADC_DelSig_1_DSM__DEM1, CYREG_DSM0_DEM1
.set ADC_DelSig_1_DSM__MISC, CYREG_DSM0_MISC
.set ADC_DelSig_1_DSM__OUT0, CYREG_DSM0_OUT0
.set ADC_DelSig_1_DSM__OUT1, CYREG_DSM0_OUT1
.set ADC_DelSig_1_DSM__REF0, CYREG_DSM0_REF0
.set ADC_DelSig_1_DSM__REF1, CYREG_DSM0_REF1
.set ADC_DelSig_1_DSM__REF2, CYREG_DSM0_REF2
.set ADC_DelSig_1_DSM__REF3, CYREG_DSM0_REF3
.set ADC_DelSig_1_DSM__RSVD1, CYREG_DSM0_RSVD1
.set ADC_DelSig_1_DSM__SW0, CYREG_DSM0_SW0
.set ADC_DelSig_1_DSM__SW2, CYREG_DSM0_SW2
.set ADC_DelSig_1_DSM__SW3, CYREG_DSM0_SW3
.set ADC_DelSig_1_DSM__SW4, CYREG_DSM0_SW4
.set ADC_DelSig_1_DSM__SW6, CYREG_DSM0_SW6
.set ADC_DelSig_1_DSM__TR0, CYREG_NPUMP_DSM_TR0
.set ADC_DelSig_1_DSM__TST0, CYREG_DSM0_TST0
.set ADC_DelSig_1_DSM__TST1, CYREG_DSM0_TST1
.set ADC_DelSig_1_Ext_CP_Clk__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set ADC_DelSig_1_Ext_CP_Clk__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set ADC_DelSig_1_Ext_CP_Clk__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set ADC_DelSig_1_Ext_CP_Clk__CFG2_SRC_SEL_MASK, 0x07
.set ADC_DelSig_1_Ext_CP_Clk__INDEX, 0x00
.set ADC_DelSig_1_Ext_CP_Clk__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set ADC_DelSig_1_Ext_CP_Clk__PM_ACT_MSK, 0x01
.set ADC_DelSig_1_Ext_CP_Clk__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set ADC_DelSig_1_Ext_CP_Clk__PM_STBY_MSK, 0x01
.set ADC_DelSig_1_IRQ__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set ADC_DelSig_1_IRQ__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set ADC_DelSig_1_IRQ__INTC_MASK, 0x20000000
.set ADC_DelSig_1_IRQ__INTC_NUMBER, 29
.set ADC_DelSig_1_IRQ__INTC_PRIOR_NUM, 7
.set ADC_DelSig_1_IRQ__INTC_PRIOR_REG, CYREG_NVIC_PRI_29
.set ADC_DelSig_1_IRQ__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set ADC_DelSig_1_IRQ__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set ADC_DelSig_1_theACLK__CFG0, CYREG_CLKDIST_ACFG0_CFG0
.set ADC_DelSig_1_theACLK__CFG1, CYREG_CLKDIST_ACFG0_CFG1
.set ADC_DelSig_1_theACLK__CFG2, CYREG_CLKDIST_ACFG0_CFG2
.set ADC_DelSig_1_theACLK__CFG2_SRC_SEL_MASK, 0x07
.set ADC_DelSig_1_theACLK__CFG3, CYREG_CLKDIST_ACFG0_CFG3
.set ADC_DelSig_1_theACLK__CFG3_PHASE_DLY_MASK, 0x0F
.set ADC_DelSig_1_theACLK__INDEX, 0x00
.set ADC_DelSig_1_theACLK__PM_ACT_CFG, CYREG_PM_ACT_CFG1
.set ADC_DelSig_1_theACLK__PM_ACT_MSK, 0x01
.set ADC_DelSig_1_theACLK__PM_STBY_CFG, CYREG_PM_STBY_CFG1
.set ADC_DelSig_1_theACLK__PM_STBY_MSK, 0x01

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 26
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E161069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 26
.set CYDEV_CHIP_MEMBER_4AA, 25
.set CYDEV_CHIP_MEMBER_4AB, 30
.set CYDEV_CHIP_MEMBER_4AC, 14
.set CYDEV_CHIP_MEMBER_4AD, 15
.set CYDEV_CHIP_MEMBER_4AE, 16
.set CYDEV_CHIP_MEMBER_4D, 20
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 27
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 24
.set CYDEV_CHIP_MEMBER_4I, 32
.set CYDEV_CHIP_MEMBER_4J, 21
.set CYDEV_CHIP_MEMBER_4K, 22
.set CYDEV_CHIP_MEMBER_4L, 31
.set CYDEV_CHIP_MEMBER_4M, 29
.set CYDEV_CHIP_MEMBER_4N, 11
.set CYDEV_CHIP_MEMBER_4O, 8
.set CYDEV_CHIP_MEMBER_4P, 28
.set CYDEV_CHIP_MEMBER_4Q, 17
.set CYDEV_CHIP_MEMBER_4R, 9
.set CYDEV_CHIP_MEMBER_4S, 12
.set CYDEV_CHIP_MEMBER_4T, 10
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_4V, 23
.set CYDEV_CHIP_MEMBER_4W, 13
.set CYDEV_CHIP_MEMBER_4X, 7
.set CYDEV_CHIP_MEMBER_4Y, 18
.set CYDEV_CHIP_MEMBER_4Z, 19
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 33
.set CYDEV_CHIP_MEMBER_FM3, 37
.set CYDEV_CHIP_MEMBER_FM4, 38
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 34
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 35
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 36
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4AA_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AB_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AC_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AD_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AE_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4T_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4V_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4W_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4X_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Y_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Z_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_ES, 17
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 33
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 33
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000000
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
