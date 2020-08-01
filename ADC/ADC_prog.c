/*
 * ADC_prog.c
 *
 *  Created on: 21 September, 2018
 *      Author: Amr Elzawawy
 */

#include "../libs/STD_TYPES.h"
#include "../utils/BIT_LIB.h"
#include "ADC_int.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit(void)
{
    /************ ADMUX *************/
    ASSIGN_BIT(ADMUX, REFS1, REFS1_VAL);
    ASSIGN_BIT(ADMUX, REFS0, REFS0_VAL);
    ASSIGN_BIT(ADMUX, ADLAR, ADLAR_VAL);
    ASSIGN_BIT(ADMUX, MUX4, MUX4_VAL);
    ASSIGN_BIT(ADMUX, MUX3, MUX3_VAL);
    ASSIGN_BIT(ADMUX, MUX2, MUX2_VAL);
    ASSIGN_BIT(ADMUX, MUX1, MUX1_VAL);
    ASSIGN_BIT(ADMUX, MUX0, MUX0_VAL);
    /************ ADCSRA *************/
    ASSIGN_BIT(ADCSRA, ADPS2, ADPS2_VAL);
    ASSIGN_BIT(ADCSRA, ADPS1, ADPS1_VAL);
    ASSIGN_BIT(ADCSRA, ADPS0, ADPS0_VAL);
    //Enable ADC
    SET_BIT(ADCSRA, ADEN);
    //Clear Interrupt Flag
    SET_BIT(ADCSRA, ADIF);
    /************ SFIOR *************/
    ASSIGN_BIT(SFIOR, ADTS2, ADTS2_VAL);
    ASSIGN_BIT(SFIOR, ADTS1, ADTS1_VAL);
    ASSIGN_BIT(SFIOR, ADTS0, ADTS0_VAL);
}

u8 ADC_u8PollADC(void)
{
    //Start Conversion
    SET_BIT(ADCSRA, ADSC);
    //Poll the ADC untill the value is ready
    while (GET_BIT(ADCSRA, ADIF) == LOW_VAL)
        ;
    //Clear Interrupt Flag Manually.
    SET_BIT(ADCSRA, ADIF);
    
    return ADC_enuNormalState;
}

u8 ADC_u8GetADCValue(u16 *u16PtrToVal)
{
    ADC_enuState Local_ADCstate ;
    if (u16PtrToVal != NULL)
    {
        //Left Adjustment of Data Registers.
        if (GET_BIT(ADMUX, ADLAR) == HIGH_VAL)
        {
            ADCL = ADCL>>6;
            *u16PtrToVal = ADCH;
            *u16PtrToVal = *u16PtrToVal << 2;
            *u16PtrToVal += ADCL;
        }
        else 
        {
            *u16PtrToVal = ADCH;
            *u16PtrToVal = *u16PtrToVal << 8;
            *u16PtrToVal += ADCL;
        }
        Local_ADCstate = ADC_enuNormalState;
    }
    else 
        Local_ADCstate = ADC_enuNullPointerException;

    return Local_ADCstate;
}
