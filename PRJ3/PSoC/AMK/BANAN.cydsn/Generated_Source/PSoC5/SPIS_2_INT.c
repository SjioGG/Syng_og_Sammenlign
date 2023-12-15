/*******************************************************************************
* File Name: SPIS_2_INT.c
* Version 2.70
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Slave
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIS_2_PVT.h"
#include "cyapicallbacks.h"

/* User code required at start of ISR */
/* `#START SPIS_2_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPIS_2_TX_ISR
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Slave.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIS_2_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIS_2_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  SPIS_2_txBuffer[SPIS_2_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIS_2_TX_ISR)
{

    #if(SPIS_2_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (SPIS_2_TX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPIS_2_TX_ISR_ENTRY_CALLBACK
        SPIS_2_TX_ISR_EntryCallback();
    #endif /* SPIS_2_TX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPIS_2_ISR_TX_START` */

    /* `#END` */

    #if(SPIS_2_TX_SOFTWARE_BUF_ENABLED)
        /* Component interrupt service code */

        /* See if TX data buffer is not empty and there is space in TX FIFO */
        while(SPIS_2_txBufferRead != SPIS_2_txBufferWrite)
        {
            tmpStatus = SPIS_2_GET_STATUS_TX(SPIS_2_swStatusTx);
            SPIS_2_swStatusTx = tmpStatus;

            if ((SPIS_2_swStatusTx & SPIS_2_STS_TX_FIFO_NOT_FULL) != 0u)
            {
                if(SPIS_2_txBufferFull == 0u)
                {
                   SPIS_2_txBufferRead++;

                    if(SPIS_2_txBufferRead >= SPIS_2_TX_BUFFER_SIZE)
                    {
                        SPIS_2_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPIS_2_txBufferFull = 0u;
                }

                /* Put data element into the TX FIFO */
                CY_SET_REG8(SPIS_2_TXDATA_PTR, 
                                             SPIS_2_txBuffer[SPIS_2_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        /* If Buffer is empty then disable TX FIFO status interrupt until there is data in the buffer */
        if(SPIS_2_txBufferRead == SPIS_2_txBufferWrite)
        {
            SPIS_2_TX_STATUS_MASK_REG &= ((uint8)~SPIS_2_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* SPIS_2_TX_SOFTWARE_BUF_ENABLED */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIS_2_ISR_TX_END` */

    /* `#END` */
    
    #ifdef SPIS_2_TX_ISR_EXIT_CALLBACK
        SPIS_2_TX_ISR_ExitCallback();
    #endif /* SPIS_2_TX_ISR_EXIT_CALLBACK */
   }


/*******************************************************************************
* Function Name: SPIS_2_RX_ISR
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Slave.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIS_2_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPIS_2_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPIS_2_rxBuffer[SPIS_2_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIS_2_RX_ISR)
{
    #if(SPIS_2_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint8 rxData;
    #endif /* (SPIS_2_TX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPIS_2_RX_ISR_ENTRY_CALLBACK
        SPIS_2_RX_ISR_EntryCallback();
    #endif /* SPIS_2_RX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPIS_2_RX_ISR_START` */

    /* `#END` */
    
    #if(SPIS_2_RX_SOFTWARE_BUF_ENABLED)
        tmpStatus = SPIS_2_GET_STATUS_RX(SPIS_2_swStatusRx);
        SPIS_2_swStatusRx = tmpStatus;
        /* See if RX data FIFO has some data and if it can be moved to the RX Buffer */
        while((SPIS_2_swStatusRx & SPIS_2_STS_RX_FIFO_NOT_EMPTY) != 0u)
        {
            rxData = CY_GET_REG8(SPIS_2_RXDATA_PTR);

            /* Set next pointer. */
            SPIS_2_rxBufferWrite++;
            if(SPIS_2_rxBufferWrite >= SPIS_2_RX_BUFFER_SIZE)
            {
                SPIS_2_rxBufferWrite = 0u;
            }

            if(SPIS_2_rxBufferWrite == SPIS_2_rxBufferRead)
            {
                SPIS_2_rxBufferRead++;
                if(SPIS_2_rxBufferRead >= SPIS_2_RX_BUFFER_SIZE)
                {
                    SPIS_2_rxBufferRead = 0u;
                }
                SPIS_2_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            SPIS_2_rxBuffer[SPIS_2_rxBufferWrite] = rxData;

            tmpStatus = SPIS_2_GET_STATUS_RX(SPIS_2_swStatusRx);
            SPIS_2_swStatusRx = tmpStatus;
        }
    #endif /* SPIS_2_RX_SOFTWARE_BUF_ENABLED */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIS_2_RX_ISR_END` */

    /* `#END` */

    #ifdef SPIS_2_RX_ISR_EXIT_CALLBACK
        SPIS_2_RX_ISR_ExitCallback();
    #endif /* SPIS_2_RX_ISR_EXIT_CALLBACK */
}

/* [] END OF FILE */
