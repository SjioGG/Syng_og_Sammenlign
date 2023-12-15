/*******************************************************************************
* File Name: SPIS_2_PM.c
* Version 2.70
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIS_2_PVT.h"

static SPIS_2_BACKUP_STRUCT SPIS_2_backup = 
{
    SPIS_2_DISABLED,
    SPIS_2_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIS_2_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIS_2_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIS_2_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIS_2_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIS_2_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPI Slave Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIS_2_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_Sleep(void) 
{
    /* Save components enable state */
    if ((SPIS_2_TX_STATUS_ACTL_REG & SPIS_2_INT_ENABLE) != 0u)
    {
        SPIS_2_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        SPIS_2_backup.enableState = 0u;
    }

    SPIS_2_Stop();

}


/*******************************************************************************
* Function Name: SPIS_2_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIS_2_backup - used when non-retention registers are restored.
*  SPIS_2_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_2_txBufferRead - modified every function call - resets to
*  zero.
*  SPIS_2_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_2_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_2_Wakeup(void) 
{
    #if (SPIS_2_TX_SOFTWARE_BUF_ENABLED)
        SPIS_2_txBufferFull = 0u;
        SPIS_2_txBufferRead = 0u;
        SPIS_2_txBufferWrite = 0u;
    #endif /* SPIS_2_TX_SOFTWARE_BUF_ENABLED */

    #if (SPIS_2_RX_SOFTWARE_BUF_ENABLED)
        SPIS_2_rxBufferFull = 0u;
        SPIS_2_rxBufferRead = 0u;
        SPIS_2_rxBufferWrite = 0u;
    #endif /* SPIS_2_RX_SOFTWARE_BUF_ENABLED */

    SPIS_2_ClearFIFO();

    /* Restore components block enable state */
    if (SPIS_2_backup.enableState != 0u)
    {
         /* Components block was enabled */
         SPIS_2_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
