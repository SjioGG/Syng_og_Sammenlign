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

#include "adc.h"

// Initialiserer ADC
void InitADC(void) { 
    ADC_DelSig_1_Start();        // Starter ADC
    ADC_DelSig_1_StartConvert(); // Starter konvertering
}

// Læser data fra ADC
uint16_t ReadADC(void) {
    ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT); // Venter på konvertering
    return ADC_DelSig_1_GetResult16();                          // Returnerer resultat
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

/* [] END OF FILE */
