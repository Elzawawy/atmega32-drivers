/*
 * LCD_prog.c
 *
 *  Created on: 16 September, 2018
 *      Author: Amr Elzawawy
 */
#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_private.h"
#define F_CPU 12000000
#include <util/delay.h>
void LCD_voidInit(void)
{
    validatePinConfiguration();
    if (VALID_PIN_CONFIGURATION)
    {
        DIO_u8SetPinDir(RS, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(RW, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(EN, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(D0, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(D1, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(D2, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(D3, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(D4, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(D5, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(D6, DIO_u8PIN_OUTPUTDIR);
        DIO_u8SetPinDir(D7, DIO_u8PIN_OUTPUTDIR);
        _delay_ms(50);
        LCD_u8WriteCommand(FUNCTION_SET);
        _delay_ms(2);
        LCD_u8WriteCommand(0b00001110);
        _delay_ms(2);
        LCD_u8WriteCommand(CLEAR_DISPLAY);
        _delay_ms(2);
        Global_u8CurrentFunctionSet = FUNCTION_SET;
    }
}
u8 LCD_u8WriteCommand(u8 Copy_u8Cmd)
{
    LCD_enuState Local_LCDstate;
    if (VALID_PIN_CONFIGURATION)
    {
        DIO_u8SetPinValue(RS, DIO_u8LOWVAL);
        DIO_u8SetPinValue(RW, DIO_u8LOWVAL);
        DIO_u8SetPinValue(D0, GET_BIT(Copy_u8Cmd, 0));
        DIO_u8SetPinValue(D1, GET_BIT(Copy_u8Cmd, 1));
        DIO_u8SetPinValue(D2, GET_BIT(Copy_u8Cmd, 2));
        DIO_u8SetPinValue(D3, GET_BIT(Copy_u8Cmd, 3));
        DIO_u8SetPinValue(D4, GET_BIT(Copy_u8Cmd, 4));
        DIO_u8SetPinValue(D5, GET_BIT(Copy_u8Cmd, 5));
        DIO_u8SetPinValue(D6, GET_BIT(Copy_u8Cmd, 6));
        DIO_u8SetPinValue(D7, GET_BIT(Copy_u8Cmd, 7));
        DIO_u8SetPinValue(EN, DIO_u8HIGHVAL);
        _delay_ms(2);
        DIO_u8SetPinValue(EN, DIO_u8LOWVAL);
        Local_LCDstate = LCD_enuNormalState;
    }
    else
        Local_LCDstate = LCD_enuInvalidPinConfig;

    return Local_LCDstate;
}
u8 LCD_u8WriteData(u8 Copy_u8Data)
{
    LCD_enuState Local_LCDstate;
    if (VALID_PIN_CONFIGURATION)
    {
        DIO_u8SetPinValue(RW, DIO_u8LOWVAL);
        DIO_u8SetPinValue(RS, DIO_u8HIGHVAL);
        DIO_u8SetPinValue(D0, GET_BIT(Copy_u8Data, 0));
        DIO_u8SetPinValue(D1, GET_BIT(Copy_u8Data, 1));
        DIO_u8SetPinValue(D2, GET_BIT(Copy_u8Data, 2));
        DIO_u8SetPinValue(D3, GET_BIT(Copy_u8Data, 3));
        DIO_u8SetPinValue(D4, GET_BIT(Copy_u8Data, 4));
        DIO_u8SetPinValue(D5, GET_BIT(Copy_u8Data, 5));
        DIO_u8SetPinValue(D6, GET_BIT(Copy_u8Data, 6));
        DIO_u8SetPinValue(D7, GET_BIT(Copy_u8Data, 7));
        DIO_u8SetPinValue(EN, DIO_u8HIGHVAL);
        _delay_ms(2);
        DIO_u8SetPinValue(EN, DIO_u8LOWVAL);
        Local_LCDstate = LCD_enuNormalState;
    }
    else
        Local_LCDstate = LCD_enuInvalidPinConfig;

    return Local_LCDstate;
}

u8 LCD_u8WriteString(u8 *Copy_u8String)
{
    LCD_enuState Local_LCDstate;
    u8 Local_u8index = 0;
    if (VALID_PIN_CONFIGURATION)
    {
        if (Copy_u8String == NULL)
        {
            Local_LCDstate = LCD_enuNullPointerException;
        }
        else
        {
            while (Copy_u8String[Local_u8index] != '\0')
            {
                LCD_u8WriteData(Copy_u8String[Local_u8index]);
                Local_u8index++;
            }
            Local_LCDstate = LCD_enuNormalState;
        }
    }
    else
        Local_LCDstate = LCD_enuInvalidPinConfig;

    return Local_LCDstate;
}

u8 LCD_u8SetFeature(u8 Copy_u8Feature)
{
    LCD_enuState Local_LCDstate;
    if (VALID_PIN_CONFIGURATION)
    {
        switch (Copy_u8Feature)
        {
            case LCD_enuOneLineDisplay :
            	RESET_BIT(Global_u8CurrentFunctionSet,3);
            	DIO_u8SetPinValue(RS,DIO_u8LOWVAL);
            	LCD_u8WriteCommand(Global_u8CurrentFunctionSet);
            	_delay_ms(2);
            	break;
        }
    }
    else
        Local_LCDstate = LCD_enuInvalidPinConfig;

    return Local_LCDstate;
}

u8 LCD_u8ClearDisplay(void) {
    LCD_enuState Local_LCDstate;
    if (VALID_PIN_CONFIGURATION)
    {
    	DIO_u8SetPinValue(RS,DIO_u8LOWVAL);
        LCD_u8WriteCommand(CLEAR_DISPLAY);
        _delay_ms(2);
    }
    else
        Local_LCDstate = LCD_enuInvalidPinConfig;

    return Local_LCDstate;
}

u8 LCD_u8ReturnHome(void) {

    LCD_enuState Local_LCDstate;
    if (VALID_PIN_CONFIGURATION)
    {
    	DIO_u8SetPinValue(RS,DIO_u8LOWVAL);
        LCD_u8WriteCommand(RETURN_HOME);
        _delay_ms(2);
    }
    else
        Local_LCDstate = LCD_enuInvalidPinConfig;

    return Local_LCDstate;

}

u8 LCD_u8ShiftDisplayLeft(void){
	LCD_enuState Local_LCDstate;
	    if (VALID_PIN_CONFIGURATION)
	    {
	    	DIO_u8SetPinValue(RS,DIO_u8LOWVAL);
	        LCD_u8WriteCommand(SHIFT_DISPLAY_LEFT);
	        _delay_ms(2);
	    }
	    else
	        Local_LCDstate = LCD_enuInvalidPinConfig;

	    return Local_LCDstate;
}

u8 LCD_u8ShiftDisplayRight(void){
	LCD_enuState Local_LCDstate;
	    if (VALID_PIN_CONFIGURATION)
	    {
	    	DIO_u8SetPinValue(RS,DIO_u8LOWVAL);
	        LCD_u8WriteCommand(SHIFT_DISPLAY_RIGHT);
	        _delay_ms(2);
	    }
	    else
	        Local_LCDstate = LCD_enuInvalidPinConfig;

	    return Local_LCDstate;
}
