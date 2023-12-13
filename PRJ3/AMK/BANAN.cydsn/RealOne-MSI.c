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

/* ========================================
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 * ========================================
*/
#include "project.h"
#include <stdlib.h> // Include for abs function

// Constants
#define SAMPLE_RATE 44100 // Sample rate in Hz
#define BUFFER_SIZE 512 // Buffer size for audio samples

// Function Prototypes
void InitADC(void);
uint16 ReadADC(void);
void InitSPI(void);
void SendSPI(uint16 data);

// Global Variables
volatile int16 audioBuffer[BUFFER_SIZE]; // Buffer for audio samples
volatile uint16 bufferIndex = 0; // Index for the buffer
volatile uint8 spiTxBuffer[2 * BUFFER_SIZE]; // SPI transmit buffer

// Function Definitions
void InitADC(void) {
    ADC_SAR_1_Start(); // Start the Delta-Sigma ADC
    ADC_SAR_1_StartConvert(); // Start conversion
}

uint16 ReadADC(void) {
    // Wait for ADC conversion to complete
    ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);
    return ADC_SAR_1_GetResult16(); // Get the result
}

void InitSPI(void) {
    SPIS_1_Start(); // Start the SPI Slave component
}

void SendSPI(uint16 data) {
    // Send the high byte
    SPIS_1_WriteTxData((uint8)(data >> 8)); 
    // Send the low byte
    SPIS_1_WriteTxData((uint8)(data & 0xFF)); 
}

// Main Function
int main(void) {
    CyGlobalIntEnable; // Enable global interrupts
    InitADC(); // Initialize ADC
    InitSPI(); // Initialize SPI

    while (1) {
        // Read audio sample from ADC
        audioBuffer[bufferIndex] = ReadADC();
        // Increment buffer index
        bufferIndex++;
        // Check if buffer is full
        if (bufferIndex >= BUFFER_SIZE) {
            // Calculate volume (max absolute value)
            int16 maxVolume = 0;
            for (uint16 i = 0; i < BUFFER_SIZE; i++) {
                int16 absValue = abs(audioBuffer[i]);
                if (absValue > maxVolume) {
                    maxVolume = absValue;
                }
            }
            // Output volume and send it to RPi via SPI
            spiTxBuffer[0] = (maxVolume >> 8) & 0xFF; // MSB
            spiTxBuffer[1] = maxVolume & 0xFF;        // LSB
            SendSPI(spiTxBuffer[0]);
            SendSPI(spiTxBuffer[1]);
            // Reset buffer index to 0
            bufferIndex = 0;
        }
    }
}



/* [] END OF FILE */

