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

#ifndef SPI_H
#define SPI_H

#include "project.h"

void InitSPI(void);
int SendSPI(uint16_t data);
void SendHandshakeSignal(void);
#define HANDSHAKE_SIGNAL 0xFFFF // Handshake signal

#endif /* SPI_H */

/* [] END OF FILE */
