/*
 * Keypad_prog.c
 *
 *  Created on: 27 September, 2018
 *      Author: Amr Elzawawy
 */

#include "../libs/STD_TYPES.h"
#include "../utils/BIT_LIB.h"
#include "Keypad_int.h"
#include "Keypad_config.h"
#include "Keypad_private.h"

void Keypad_voidInit(void)
{ /* Set Columns direction to Output */
    DIO_u8SetPinDir(C1, DIO_u8PIN_OUTPUTDIR);
    DIO_u8SetPinDir(C2, DIO_u8PIN_OUTPUTDIR);
    DIO_u8SetPinDir(C3, DIO_u8PIN_OUTPUTDIR);
    DIO_u8SetPinDir(C4, DIO_u8PIN_OUTPUTDIR);
    /* Set Rows direction to Input */
    DIO_u8SetPinDir(R1, DIO_u8PIN_INPUTDIR);
    DIO_u8SetPinDir(R2, DIO_u8PIN_INPUTDIR);
    DIO_u8SetPinDir(R3, DIO_u8PIN_INPUTDIR);
    DIO_u8SetPinDir(R4, DIO_u8PIN_INPUTDIR);
    /* Set Column Initial Values to 1111 */
    DIO_u8SetPinValue(C1, DIO_u8HIGHVAL);
    DIO_u8SetPinValue(C2, DIO_u8HIGHVAL);
    DIO_u8SetPinValue(C3, DIO_u8HIGHVAL);
    DIO_u8SetPinValue(C4, DIO_u8HIGHVAL);
    /* Enable Pull Up Resistors at Input Rows */
    DIO_u8SetPinValue(R1, DIO_u8HIGHVAL);
    DIO_u8SetPinValue(R2, DIO_u8HIGHVAL);
    DIO_u8SetPinValue(R3, DIO_u8HIGHVAL);
    DIO_u8SetPinValue(R4, DIO_u8HIGHVAL);
}

u8 Keypad_u8GetPressedButtonValue(u8 *u8PtrToVal)
{
    Keypad_enuState Local_KeypadState;
    u8 Local_ColCount, Local_RowCount;
    u8 rowVal;
    u8 flag = 0;
    if (u8PtrToVal != NULL)
    {
        for (Local_ColCount = 0; Local_ColCount < KEYPADSIZE; Local_ColCount++)
        {
            //activate current colmun
            DIO_u8SetPinValue(u8ColArr[Local_ColCount], DIO_u8LOWVAL);
            for (Local_RowCount = 0; Local_RowCount < KEYPADSIZE; Local_RowCount++)
            {
                //check row value if it is 0 then this column and row is connected
                DIO_u8GetPinValue(u8RowArr[Local_RowCount], &rowVal);
                if (rowVal == 0)
                {
                    flag = 1;
                    break;
                } 
            }
            //if the inner row loop has broken and flag is set,
            //place value in return pointer and exit outer column loop.
            if (flag == 1)
            {
                *u8PtrToVal = u8buttonArr[Local_ColCount][Local_RowCount];
                break;
            }
            //de-activate current column.
            DIO_u8SetPinValue(u8ColArr[Local_ColCount], DIO_u8HIGHVAL);
        }
        Local_KeypadState = Keypad_enuNormalState;
    }
    else
        Local_KeypadState = Keypad_enuNullPointerException;

    return Local_KeypadState;
}
