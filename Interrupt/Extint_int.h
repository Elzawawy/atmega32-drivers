/*
 * Extint_int.h
 *
 *  Created on: Nov 22, 2018
 *      Author: Omar Hosny & Amr Elzawawy
 */

#ifndef EXTINT_INT_H_
#define EXTINT_INT_H_

typedef enum {
    Extint_enuNormalState=0,
    Extint_enuNullPointerException,
    Extint_enuWrongIntNum,
    Extint_enuWrongIntState
}Extint_enuExtintState;

typedef enum {
    Extint_enuInt0=0,
    Extint_enuInt1,
    Extint_enuInt2
}Extint_enuIntNum;


typedef enum {
	Extint_enuLowLevel=0,
	Extint_enuAnyChange=1,
	Extint_enuFallingEdge=2,
	Extint_enuRisingEdge=3
}Extint_enuIntState;

void Extint_voidInit(void);
u8 Extint_u8SetIntHanlder(u8 Copy_u8IntNum, void(* PtrToHandler)(void));
u8 Extint_u8SetIntState(u8 Copy_u8IntNum, u8 Copy_u8IntState);
u8 Extint_u8EnableInt(u8 Copy_u8IntNum);
u8 Extint_u8DisableInt(u8 Copy_u8IntNum);
#endif