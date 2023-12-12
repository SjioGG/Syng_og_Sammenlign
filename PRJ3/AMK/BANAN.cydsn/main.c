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

#include "project.h"
#include "adc.h"
#include "spi.h"

#define BUFFER_SIZE 512
volatile uint16_t adcBuffer[BUFFER_SIZE];
volatile int bufferIndex = 0;

int main(void) {
    CyGlobalIntEnable; // Aktiverer globale interrupts
    InitADC();         // Initialiserer ADC
    InitSPI();         // Initialiserer SPI

    for (;;) {
        if (bufferIndex < BUFFER_SIZE) {                 // Hvis buffer ikke er fyldt
            adcBuffer[bufferIndex++] = ReadADC();        // Læser data fra ADC og gemmer i buffer
            HandleADCConversion();                       // Håndterer ADC konvertering
        } else {
            SendHandshakeSignal();                       // Sender handshake signal
            for (int i = 0; i < BUFFER_SIZE; i++) {      // Sender buffer over SPI
                if (!SendSPI(adcBuffer[i])) {            // Hvis fejl
                    LED_Write(0);                        // Slukker LED
                    break;                               // Stopper for loop
                }
            }
            bufferIndex = 0;                             // Nulstiller buffer index
        }
    }
}

/* [] END OF FILE */
