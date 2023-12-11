#include "project.h"
#include <stdio.h>

#define SAMPLE_RATE 44100 // Definerer sample rate som 44100 Hz
#define BUFFER_SIZE 512   // Størrelsen på bufferen sat til 512
#define HANDSHAKE_SIGNAL 0xFFFF // Definerer handshake signal

volatile uint16_t adcBuffer[BUFFER_SIZE]; // Buffer til ADC data
volatile int bufferIndex = 0; // Indeks til styring af buffer

// Funktionsdeklarationer
void InitADC(void);
void InitSPI(void);
int SendSPI(uint16_t data);
uint16_t ReadADC(void);
void HandleADCConversion(void);
void SendHandshakeSignal(void);

// Initialiserer ADC
void InitADC(void) {
    ADC_DelSig_1_Start();
    ADC_DelSig_1_StartConvert();
}

// Initialiserer SPI
void InitSPI(void) {
    SPIS_1_Start();
}

// Læser data fra ADC
uint16_t ReadADC(void) {
    ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT);
    return ADC_DelSig_1_GetResult16();
}

// Sender data over SPI
int SendSPI(uint16_t data) {
    while (!(SPIS_1_ReadTxStatus() & SPIS_1_STS_TX_FIFO_NOT_FULL));
    SPIS_1_WriteTxData(data);
    while (!(SPIS_1_ReadTxStatus() & SPIS_1_STS_SPI_DONE));
    return (SPIS_1_ReadTxStatus() & SPIS_1_STS_SPI_DONE) ? 1 : 0;
}

// Håndterer ADC konvertering
void HandleADCConversion(void) {
    uint32 status = ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_RETURN_STATUS);
    if (status == ADC_DelSig_1_RETURN_STATUS) {
        LED_Write(1); // Tænder LED ved succesfuld konvertering
    } else {
        LED_Write(0); // Slukker LED hvis fejl
    }
}

// Sender handshake signal over SPI
void SendHandshakeSignal(void) {
    SendSPI(HANDSHAKE_SIGNAL);
    CyDelay(10); // Lille forsinkelse for at sikre RPI er klar
}

int main(void) {
    CyGlobalIntEnable; // Aktiverer globale interrupts
    InitADC(); // Initialiserer ADC
    InitSPI(); // Initialiserer SPI

    for (;;) {
        if (bufferIndex < BUFFER_SIZE) {
            adcBuffer[bufferIndex++] = ReadADC(); // Læser ADC og gemmer i buffer
            HandleADCConversion();
            CyDelay(1); // Forsinkelse mellem ADC aflæsninger
        } else {
            SendHandshakeSignal(); // Sender handshake signal
            for (int i = 0; i < BUFFER_SIZE; i++) {
                if (!SendSPI(adcBuffer[i])) {
                    printf("BREAD");
                }
            }
            bufferIndex = 0; // Nulstiller buffer index
        }
    }
}

/* [] END OF FILE */
