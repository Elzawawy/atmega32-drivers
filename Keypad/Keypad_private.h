/*
 * Keypad_private.h
 *
 *  Created on: 27 September, 2018
 *      Author: Amr Elzawawy
 */

#define NULL (void *) 0x00
#define KEYPADSIZE 4
u8 u8ColArr[4] = {C1, C2, C3, C4};
u8 u8RowArr[4] = {R1, R2, R3, R4};
u8 u8buttonArr[4][4]=
{   //column 1
    {BUTTON1_VAL, BUTTON5_VAL, BUTTON9_VAL, BUTTON13_VAL},
    //column 2
    {BUTTON2_VAL, BUTTON6_VAL, BUTTON10_VAL, BUTTON14_VAL},
    //column 3
    {BUTTON3_VAL, BUTTON7_VAL, BUTTON11_VAL, BUTTON15_VAL},
    //column 4
    {BUTTON4_VAL, BUTTON8_VAL, BUTTON12_VAL, BUTTON16_VAL}
}