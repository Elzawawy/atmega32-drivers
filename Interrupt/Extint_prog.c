/*
 * Extint_prog.c
 *
 *  Created on: Nov 22, 2018
 *      Author: Omar Hosny & Amr Elzawawy
 */

#include "../libs/STD_TYPES.h"
#include "../libs/Registers.h"
#include "../utils/BIT_LIB.h"
#include "Extint_int.h"
#include "Extint_private.h"
#include "Extint_config.h"

void Extint_voidInit(void)
{
    ASSIGN_BIT(MCUCR, ISC00, ISC00_INITVAL);
    ASSIGN_BIT(MCUCR, ISC01, ISC01_INITVAL);
    ASSIGN_BIT(MCUCR, ISC10, ISC10_INITVAL);
    ASSIGN_BIT(MCUCR, ISC11, ISC11_INITVAL);
    ASSIGN_BIT(MCUCSR, ISC2, ISC2_INITVAL);
}

u8 Extint_u8SetIntHanlder(u8 Copy_u8IntNum, void (*PtrToHandler)(void))
{
    Extint_enuExtintState Local_ExtintState = Extint_enuNormalState;
    if (PtrToHandler == NULL)
        Local_ExtintState = Extint_enuNullPointerException;
    else
    {
        switch (Copy_u8IntNum)
        {
        case Extint_enuInt0:
            ptrINT0 = PtrToHandler;
            break;
        case Extint_enuInt1:
            ptrINT1 = PtrToHandler;
            break;
        case Extint_enuInt2:
            ptrINT2 = PtrToHandler;
            break;
        default:
            Local_ExtintState = Extint_enuWrongIntNum;
        }
    }
    return Local_ExtintState;
}

u8 Extint_u8SetIntState(u8 Copy_u8IntNum, u8 Copy_u8IntState)
{
    Extint_enuExtintState Local_ExtintState = Extint_enuNormalState;
    switch (Copy_u8IntNum)
    {
    case Extint_enuInt0:
        switch (Copy_u8IntState)
        {
        case (Extint_enuLowLevel):
            RESET_BIT(MCUCR, ISC00);
            RESET_BIT(MCUCR, ISC01);
            break;
        case (Extint_enuAnyChange):
            SET_BIT(MCUCR, ISC00);
            RESET_BIT(MCUCR, ISC01);
            break;
        case (Extint_enuFallingEdge):
            RESET_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            break;
        case (Extint_enuRisingEdge):
            SET_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            break;
        default:
            Local_ExtintState = Extint_enuWrongIntState;
        }
        break;
    case Extint_enuInt1:
        switch (Copy_u8IntState)
        {
        case (Extint_enuLowLevel):
            RESET_BIT(MCUCR, ISC10);
            RESET_BIT(MCUCR, ISC11);
            break;
        case (Extint_enuAnyChange):
            SET_BIT(MCUCR, ISC10);
            RESET_BIT(MCUCR, ISC11);
            break;
        case (Extint_enuFallingEdge):
            RESET_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            break;
        case (Extint_enuRisingEdge):
            SET_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            break;
        default:
            Local_ExtintState = Extint_enuWrongIntState;
        }
        break;
    case Extint_enuInt2:
        switch (Copy_u8IntState)
        {
        case (Extint_enuFallingEdge):
//            //Disable Interrupt.
//            RESET_BIT(GICR,INT2);
            //Change State.
            RESET_BIT(MCUCSR, ISC2);
//            //Clear Flag.
//            SET_BIT(GIFR,INTF2);
//            //Re-Enable Interrupt.
//            SET_BIT(GICR,INT2);
            break;
        case (Extint_enuRisingEdge):
//            RESET_BIT(GICR,INT2);
            SET_BIT(MCUCSR, ISC2);
//            SET_BIT(GIFR,INTF2);
//            SET_BIT(GICR,INT2);
            break;
        default:
            Local_ExtintState = Extint_enuWrongIntState;
        }
        break;
    default:
        Local_ExtintState = Extint_enuWrongIntNum;
    }
    return Local_ExtintState;
}

u8 Extint_u8EnableInt(u8 Copy_u8IntNum)
{
    Extint_enuExtintState Local_ExtintState = Extint_enuNormalState;
    switch (Copy_u8IntNum)
    {
    case Extint_enuInt0:
        if (ptrINT0 == NULL)
            Local_ExtintState = Extint_enuNullPointerException;
        else
        {
            SET_BIT(SREG, I);
            SET_BIT(GICR, INT0);
        }
        break;
    case Extint_enuInt1:
        if (ptrINT1 == NULL)
            Local_ExtintState = Extint_enuNullPointerException;
        else
        {
            SET_BIT(SREG, I);
            SET_BIT(GICR, INT1);
        }
        break;
    case Extint_enuInt2:
        if (ptrINT2 == NULL)
            Local_ExtintState = Extint_enuNullPointerException;
        else
        {
            SET_BIT(SREG, I);
            SET_BIT(GICR, INT2);
        }
        break;
    }
    return Local_ExtintState;
}

u8 Extint_u8DisableInt(u8 Copy_u8IntNum)
{
    Extint_enuExtintState Local_ExtintState = Extint_enuNormalState;
    switch (Copy_u8IntNum)
    {
    case Extint_enuInt0:
        if (ptrINT0 == NULL)
            Local_ExtintState = Extint_enuNullPointerException;
        else
            RESET_BIT(GICR, INT0);
        break;
    case Extint_enuInt1:
        if (ptrINT1 == NULL)
            Local_ExtintState = Extint_enuNullPointerException;
        else
            RESET_BIT(GICR, INT1);
        break;
    case Extint_enuInt2:
        if (ptrINT2 == NULL)
            Local_ExtintState = Extint_enuNullPointerException;
        else
            SET_BIT(GICR, INT2);
        break;
    }
    return Local_ExtintState;
}

ISR(__vector_1)
{
    ptrINT0();
}
ISR(__vector_2)
{
    ptrINT1();
}
ISR(__vector_3)
{
    ptrINT2();
}
