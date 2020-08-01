/*
 * Keypad_int.h
 *
 *  Created on: 27 September, 2018
 *      Author: Amr Elzawawy
 */

/* State of the Keypad , for return valdiation of the function*/
typedef enum Keypad_enuState {
    Keypad_enuNormalState=0,
    Keypad_enuNullPointerException
}Keypad_enuState;

void Keypad_voidInit(void);
u8 Keypad_u8GetPressedButtonValue(u8 * u8PtrToVal);