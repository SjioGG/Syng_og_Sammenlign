/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "spi.h"

// Initialiserer SPI
void InitSPI(void) {
    SPIS_1_Start(); // Starter SPI
}

// Sender data over SPI
int SendSPI(uint16_t data) {
    while (!(SPIS_1_ReadTxStatus() & SPIS_1_STS_TX_FIFO_NOT_FULL)); // Venter på at TX FIFO ikke er fuld
    SPIS_1_WriteTxData(data);                                       // Skriver data til TX FIFO
    while (!(SPIS_1_ReadTxStatus() & SPIS_1_STS_SPI_DONE));         // Venter på at SPI er færdig
    return (SPIS_1_ReadTxStatus() & SPIS_1_STS_SPI_DONE) ? 1 : 0;   // Returnerer 1 hvis succesfuld, 0 hvis fejl
}

// Sender handshake signal over SPI
void SendHandshakeSignal(void) {
    SendSPI(HANDSHAKE_SIGNAL);  // Sender handshake signal
    CyDelay(5);                 // Lille forsinkelse for at sikre RPI er klar
}

/* [] END OF FILE */
