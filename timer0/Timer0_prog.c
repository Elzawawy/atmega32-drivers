/*
 * Timer0_prog.c
 *
 *  Created on: 26 September, 2018
 *      Author: Amr Elzawawy
 */
#include "../libs/STD_TYPES.h"
#include "../utils/BIT_LIB.h"
#include "Timer0_int.h"
#include "Timer0_config.h"
#include "Timer0_private.h"
void Timer0_voidInit(void)
{
    TCCR0 = TCCR0_INITVAL;   
    ASSIGN_BIT(TIMSK,OCIE0,OCIE0_VAL);
    ASSIGN_BIT(TIMSK,TOIE0,TOIE0_VAL);
}

u8 Timer0_u8SetRegister(u8 RegName, u8 u8RegVal)
{
    Timer0_enuState Local_TimerState;
    if(RegName == TCNT)
    {
        TCNT0 = u8RegVal;
        Local_TimerState=Timer0_enuNormalState;
    }
    else if(RegName == OCR)
    {
        OCR0 = u8RegVal;
        Local_TimerState=Timer0_enuNormalState;
    }
    else 
        Local_TimerState=Timer0_InvalidRegisterInput;
    
    return Local_TimerState;
}
