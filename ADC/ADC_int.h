/*
 * ADC_int.h
 *
 *  Created on: 21 September, 2018
 *      Author: Amr Elzawawy
 */

#ifndef ADC_INT
#define ADC_INT
/* This enum is for function validation, holds the possible states of the ADC */
typedef enum ADC_enuState {
    ADC_enuNormalState= 0,
    ADC_enuNullPointerException,
}ADC_enuState;

/* Initalization Method*/
void ADC_voidInit(void);

/*Polling the ADC, 
The Function returns 0 "ADC_enuNormalState" when the ADC is ready for the user 
and the ADC is functioning in normal state. 
Otherwise, returns any other state type from the ADC_enuState enum */
u8 ADC_u8PollADC(void);

/* Get ADC value, This Functions returns the value converted by the ADC ( directly from ADCH ) */
u8 ADC_u8GetADCValue(u16 * u16PtrToVal);




#endif