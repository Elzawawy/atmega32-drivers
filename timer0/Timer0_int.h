/*
 * Timer0_int.h
 *
 *  Created on: 26 September, 2018
 *      Author: Amr Elzawawy
 */
typedef enum  Timer0_enuState {
    Timer0_enuNormalState =0,
    Timer0_InvalidOperationMode,
    Timer0_InvalidCompareOutputMode,
    Timer0_InvalidRegisterInput
}Timer0_enuState;

#define TCNT 0
#define OCR  1
//Compare Output Modes
/*typedef enum Timer0_enuCOMode {
    Timer0_enuNormalMode1,
    Timer0_enuNormalMode2,
    Timer0_enuNormalMode3,
    Timer0_enuNormalMode4,
}Timer0_enuCOMode;*/
void Timer0_voidInit(void);
//u8 Timer0_u8SetCompareOutputMode();
u8 Timer0_u8SetRegister(u8 RegName, u8 u8RegVal);
