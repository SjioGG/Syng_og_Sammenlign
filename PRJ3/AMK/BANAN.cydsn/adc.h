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

#ifndef ADC_H
#define ADC_H

#include "project.h"

void InitADC(void);
uint16_t ReadADC(void);
void HandleADCConversion(void);

#endif /* ADC_H */

/* [] END OF FILE */
