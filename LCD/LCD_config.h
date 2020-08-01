/*
 * LCD_config.h
 *
 *  Created on: 16 September, 2018
 *      Author: Amr Elzawawy
 */

#ifndef LCD_CONFIG
#define LCD_CONFIG
#include "../DIO/DIO_int.h"
/************ Data Bits ****************/
#define D0 DIO_enuPin0
#define D1 DIO_enuPin1
#define D2 DIO_enuPin2
#define D3 DIO_enuPin3
#define D4 DIO_enuPin4
#define D5 DIO_enuPin5
#define D6 DIO_enuPin6
#define D7 DIO_enuPin7
/*********** Register Select Bit ***********/
#define RS DIO_enuPin8
/*********** Read Write Bit ***************/
#define RW DIO_enuPin9
/*********** Enable Bit ******************/
#define EN DIO_enuPin10

#endif
