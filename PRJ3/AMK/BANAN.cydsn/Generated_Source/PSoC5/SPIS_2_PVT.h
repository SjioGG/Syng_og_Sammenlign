/*******************************************************************************
* File Name: .h
* Version 2.70
*
* Description:
*  This private header file contains internal definitions for the SPIS
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIS_PVT_SPIS_2_H)
#define CY_SPIS_PVT_SPIS_2_H

#include "SPIS_2.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/
extern volatile uint8 SPIS_2_swStatusTx;
extern volatile uint8 SPIS_2_swStatusRx;

#if (SPIS_2_RX_SOFTWARE_BUF_ENABLED)

    extern volatile uint8 SPIS_2_rxBuffer[SPIS_2_RX_BUFFER_SIZE];
    extern volatile uint8 SPIS_2_rxBufferRead;
    extern volatile uint8 SPIS_2_rxBufferWrite;
    extern volatile uint8 SPIS_2_rxBufferFull;

#endif /* SPIS_2_RX_SOFTWARE_BUF_ENABLED */

#if (SPIS_2_TX_SOFTWARE_BUF_ENABLED)

    extern volatile uint8 SPIS_2_txBuffer[SPIS_2_TX_BUFFER_SIZE];
    extern volatile uint8 SPIS_2_txBufferRead;
    extern volatile uint8 SPIS_2_txBufferWrite;
    extern volatile uint8 SPIS_2_txBufferFull;

#endif /* SPIS_2_TX_SOFTWARE_BUF_ENABLED */

#endif /* CY_SPIS_PVT_SPIS_2_H */


/* [] END OF FILE */
