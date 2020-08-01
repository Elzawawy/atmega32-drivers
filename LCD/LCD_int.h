/*
 * LCD_int.h
 *
 *  Created on: 16 September, 2018
 *      Author: Amr Elzawawy
 */

#ifndef LCD_INT
#define LCD_INT
/*********** Utils and libs needed ******/
#include "../libs/STD_TYPES.h"
#include "../utils/BIT_LIB.h"
/* This enum is the Special Features that can be set to the LCD */
typedef enum LCD_enuFeature {
    LCD_enuOneLineDisplay=0,
    LCD_enuTwoLineDispaly,
    LCD_enuFourBitData,
    LCD_enuEightBitData,
    LCD_enuFontTypeOne,
    LCD_enuFontTypeTwo,

}LCD_enuFeature;
/* This enum is the States the LCD can be in at any given moment */
/* It provides validation of API calls */
typedef enum LCD_enuState {
    LCD_enuNormalState=0,
    LCD_enuInvalidPinConfig,
    LCD_enuNotDefinedFeature,
    LCD_enuNullPointerException,


}LCD_enuState;

/* Initialize Method */
void LCD_voidInit(void);
/* Write Data Method */
u8 LCD_u8WriteData(u8 Copy_u8Data);
/* Write String Data Method */
u8 LCD_u8WriteString(u8 * Copy_u8String);
/* Sets a Special Feature from the LCD_enuFeature */
u8 LCD_u8SetFeature(u8 Copy_u8Feature);
/* Clears entire display and sets DDRAM address to 00H*/
u8 LCD_u8ClearDisplay(void);
/* Return Home Sets DDRAM address to 00H in AC and returns shifted display to its original position.
The contents of DDRAM remain unchanged. */
u8 LCD_u8ReturnHome(void);
/*Shifts the entire display to the left, cursor follows the display shift*/
u8 LCD_u8ShiftDisplayLeft(void);
/*Shifts the entire display to the right, cursor follows the display shift*/
u8 LCD_u8ShiftDisplayRight(void);

#endif
