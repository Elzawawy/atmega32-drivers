/*
 * ADC_reg.h
 *
 *  Created on: 21 September, 2018
 *      Author: Amr Elzawawy
 */

#ifndef ADC_REG
#define ADC_REG
//#define SREG *((volatile u8 *)0X5F)
#define ADMUX *((volatile u8 *)0X27)
#define ADCSRA *((volatile u8 *)0X26)
#define ADCH *((volatile u8*)0X25)
#define ADCL  *((volatile u8*)0X24)
#define SFIOR  *((volatile u8*)0X24)
/************ ADMUX *************/
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0
/************ ADCSRA *************/
#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0
/************ SFIOR *************/
#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

#endif