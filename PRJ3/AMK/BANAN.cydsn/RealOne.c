#include "project.h" // Indeholder alle biblioteker
#include <stdio.h>   // Indeholder standard biblioteker

#define SAMPLE_RATE 44100       // Samplerate sat til 44.1 kHz
#define BUFFER_SIZE 512         // Buffer størrelse sat til 512
#define HANDSHAKE_SIGNAL 0xFFFF // Handshake signal

volatile uint16_t adcBuffer[BUFFER_SIZE]; // ADC buffer
volatile int bufferIndex = 0;             // Buffer index

// Prototyper
void InitADC(void);                 // Initialiserer ADC
void InitSPI(void);                 // Initialiserer SPI
int SendSPI(uint16_t data);         // Sender data over SPI 
uint16_t ReadADC(void);             // Læser data fra ADC
void HandleADCConversion(void);     // Håndterer ADC konvertering 
void SendHandshakeSignal(void);     // Sender handshake signal over SPI

// Initialiserer ADC
void InitADC(void) { 
    ADC_DelSig_1_Start();        // Starter ADC
    ADC_DelSig_1_StartConvert(); // Starter konvertering
}

// Initialiserer SPI
void InitSPI(void) {
    SPIS_1_Start(); // Starter SPI
}

// Læser data fra ADC
uint16_t ReadADC(void) {
    ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT); // Venter på konvertering
    return ADC_DelSig_1_GetResult16();                          // Returnerer resultat
}

// Sender data over SPI
int SendSPI(uint16_t data) {
    while (!(SPIS_1_ReadTxStatus() & SPIS_1_STS_TX_FIFO_NOT_FULL)); // Venter på at TX FIFO ikke er fuld
    SPIS_1_WriteTxData(data);                                       // Skriver data til TX FIFO
    while (!(SPIS_1_ReadTxStatus() & SPIS_1_STS_SPI_DONE));         // Venter på at SPI er færdig
    return (SPIS_1_ReadTxStatus() & SPIS_1_STS_SPI_DONE) ? 1 : 0;   // Returnerer 1 hvis succesfuld, 0 hvis fejl
}

// Håndterer ADC konvertering
void HandleADCConversion(void) {
    uint32 status = ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_RETURN_STATUS); // Tjekker status på konvertering
    if (status == ADC_DelSig_1_RETURN_STATUS) {                               // Hvis succesfuld
        LED_Write(1);                                                         // Tænder LED ved succesfuld konvertering
    } else {
        LED_Write(0);                                                         // Slukker LED hvis fejl
    }
}

// Sender handshake signal over SPI
void SendHandshakeSignal(void) {
    SendSPI(HANDSHAKE_SIGNAL);  // Sender handshake signal
    CyDelay(5);                 // Lille forsinkelse for at sikre RPI er klar
}

// Main funktion
int main(void) {
    CyGlobalIntEnable; // Aktiverer globale interrupts
    InitADC();         // Initialiserer ADC
    InitSPI();         // Initialiserer SPI

    // Uendelig løkke
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