/*
 * LCD_private.h
 *
 *  Created on: 16 September, 2018
 *      Author: Amr Elzawawy
 */
#include "LCD_int.h"
u8 VALID_PIN_CONFIGURATION = 0;
#define validatePinConfiguration() if(RS < DIO_u8NumOfPins && RW < DIO_u8NumOfPins && EN < DIO_u8NumOfPins && D0 < DIO_u8NumOfPins && D1 < DIO_u8NumOfPins && D2 < DIO_u8NumOfPins && D3 < DIO_u8NumOfPins && D4 < DIO_u8NumOfPins && D5 < DIO_u8NumOfPins && D6 < DIO_u8NumOfPins && D7 < DIO_u8NumOfPins) \
                                    VALID_PIN_CONFIGURATION = 1

#define NULL  (void * ) 0x00

/* Write Command Method */
u8 LCD_u8WriteCommand(u8 COPY_u8Cmd);

/******************LCD Commands******************/
#define CLEAR_DISPLAY 0b00000001
#define RETURN_HOME 0b00000010
#define FUNCTION_SET 0b00111100
#define SHIFT_DISPLAY_LEFT 0b00011000
#define SHIFT_DISPLAY_RIGHT 0b00011100
u8 Global_u8CurrentFunctionSet;
