/*
 * DIO_prog.c
 *
 *  Created on: 13 September, 2018
 *      Author: Amr Elzawawy
 */
#include "../libs/STD_TYPES.h"
#include "../utils/BIT_LIB.h"
#include "DIO_private.h"
#include "DIO_int.h"

/* Arrays to define port according to it's index extracted from the pin num*/
volatile u8* const DIO_u8ArrPORT[DIO_u8NumOfPorts] = {&PORTA,&PORTB,&PORTC,&PORTD};
volatile u8* const DIO_u8ArrDDR[DIO_u8NumOfPorts] = {&DDRA,&DDRB,&DDRC,&DDRD};
volatile u8* const DIO_u8ArrPIN[DIO_u8NumOfPorts] = {&PINA,&PINB,&PINC,&PIND};

/* Init Method */
extern void DIO_voidInit(void){
    DDRA = DDRA_INITVAL;
    DDRB = DDRB_INITVAL;
    DDRC = DDRC_INITVAL;
    DDRD = DDRD_INITVAL;
    PORTA = PORTA_INITVAL;
    PORTB = PORTB_INITVAL;
    PORTC = PORTC_INITVAL;
    PORTD = PORTD_INITVAL;
	/*DDRA=DDRB=DDRC=DDRD=0xFF;
	PORTA=PORTB=PORTC=PORTD=0x00;*/
}

/* Set Pin Value */
extern u8 DIO_u8SetPinValue (u8 Copy_u8PinNum, u8 Copy_u8PinVal) {
    u8 Local_u8PortNum, Local_u8PinInPortNum;
    DIO_enuDioState Local_DioState;
    if( Copy_u8PinNum < DIO_u8NumOfPins ) {
        Local_u8PortNum = Copy_u8PinNum / DIO_u8NumOfPinsPerPort;
        Local_u8PinInPortNum = Copy_u8PinNum % DIO_u8NumOfPinsPerPort;
        if( Copy_u8PinVal == DIO_u8HIGHVAL ) { 
            SET_BIT(*DIO_u8ArrPORT[Local_u8PortNum], Local_u8PinInPortNum);
            Local_DioState = DIO_enuNormal;
        }
        else if( Copy_u8PinVal == DIO_u8LOWVAL ) {
            RESET_BIT(*DIO_u8ArrPORT[Local_u8PortNum], Local_u8PinInPortNum);
            Local_DioState = DIO_enuNormal;
        }      
        else 
            Local_DioState = DIO_enuWrongPinVal;
    }
    else {
       Local_DioState = DIO_enuWrongPinNum; 
    }

    return Local_DioState;
}

/* Get Pin Value */
extern u8 DIO_u8GetPinValue (u8 Copy_u8PinNum,u8* u8PtrtoVal){
    u8 Local_u8PortNum, Local_u8PinInPortNum;
    DIO_enuDioState Local_DioState;
    if( Copy_u8PinNum < DIO_u8NumOfPins ) {
        Local_u8PortNum = Copy_u8PinNum / DIO_u8NumOfPinsPerPort;
        Local_u8PinInPortNum = Copy_u8PinNum % DIO_u8NumOfPinsPerPort;
        *u8PtrtoVal = GET_BIT(*DIO_u8ArrPIN[Local_u8PortNum], Local_u8PinInPortNum);
        Local_DioState = DIO_enuNormal;
    }
    else {
        Local_DioState = DIO_enuWrongPinNum;
    }

    return Local_DioState;
}

/* Set Pin Direction */
extern u8 DIO_u8SetPinDir (u8 Copy_u8PinNum, u8 Copy_u8PinDir){
    u8 Local_u8PortNum, Local_u8PinInPortNum;
    DIO_enuDioState Local_DioState;
    if( Copy_u8PinNum < DIO_u8NumOfPins ) {
        Local_u8PortNum = Copy_u8PinNum / DIO_u8NumOfPinsPerPort;
        Local_u8PinInPortNum = Copy_u8PinNum % DIO_u8NumOfPinsPerPort;
        if( Copy_u8PinDir == DIO_u8PIN_OUTPUTDIR ) {
            SET_BIT(*DIO_u8ArrDDR[Local_u8PortNum], Local_u8PinInPortNum);
            Local_DioState = DIO_enuNormal;
        }
        else if( Copy_u8PinDir == DIO_u8PIN_INPUTDIR ) {
            RESET_BIT(*DIO_u8ArrDDR[Local_u8PortNum], Local_u8PinInPortNum);
            Local_DioState = DIO_enuNormal;
        }      
        else 
            Local_DioState = DIO_enuWrongPinDir;
    }
    else {
        Local_DioState = DIO_enuWrongPinNum;
    }

    return Local_DioState;
}

/* Get Pin Direction */
extern u8 DIO_u8GetPinDir (u8 Copy_u8PinNum, u8* u8PtrtoDir){
    u8 Local_u8PortNum, Local_u8PinInPortNum;
    DIO_enuDioState Local_DioState;
    if( Copy_u8PinNum < DIO_u8NumOfPins ) {
        Local_u8PortNum = Copy_u8PinNum / DIO_u8NumOfPinsPerPort;
        Local_u8PinInPortNum = Copy_u8PinNum % DIO_u8NumOfPinsPerPort;
        *u8PtrtoDir = GET_BIT(*DIO_u8ArrDDR[Local_u8PortNum], Local_u8PinInPortNum);
        Local_DioState = DIO_enuNormal;
    }
        else {
        Local_DioState = DIO_enuWrongPinNum;
    }

    return Local_DioState;
}

/* Set Port Value */
extern u8 DIO_u8SetPortValue (u8 Copy_u8PortNum, u8 Copy_u8PortVal){
    DIO_enuDioState Local_DioState;
    if( Copy_u8PortNum < DIO_u8NumOfPorts ) {
        *DIO_u8ArrPORT[Copy_u8PortNum] = Copy_u8PortVal;  
        Local_DioState = DIO_enuNormal;
    }
    else 
        Local_DioState =  DIO_enuWrongPortNum;
    
    return Local_DioState;

}

/* Get Port Value */
extern u8 DIO_u8GetPortValue (u8 Copy_u8PortNum,u8* u8PtrtoVal){
    DIO_enuDioState Local_DioState;
    if( Copy_u8PortNum < DIO_u8NumOfPorts ) {
        *u8PtrtoVal = *DIO_u8ArrPIN[Copy_u8PortNum];
        Local_DioState = DIO_enuNormal;
    }
    else 
        Local_DioState =  DIO_enuWrongPortNum;

    return Local_DioState;

}

/* Set Port Direction */
extern u8 DIO_u8SetPortDir (u8 Copy_u8PortNum, u8 Copy_u8PortDir){
    DIO_enuDioState Local_DioState;
    if( Copy_u8PortNum < DIO_u8NumOfPorts ) {
        if(Copy_u8PortDir == DIO_u8PORT_INPUTDIR || Copy_u8PortDir == DIO_u8PORT_OUTPUTDIR ) {
            *DIO_u8ArrDDR[Copy_u8PortNum] = Copy_u8PortDir;  
            Local_DioState = DIO_enuNormal;
        }
        else
            Local_DioState = DIO_enuWrongPortDir;   
    }
    else 
        Local_DioState =  DIO_enuWrongPortNum;

    return Local_DioState;

}

/* Get Port Direction */
extern u8 DIO_u8GetPortDir (u8 Copy_u8PortNum, u8* u8PtrtoDir){
    DIO_enuDioState Local_DioState;
    if( Copy_u8PortNum < DIO_u8NumOfPorts ) {
        *u8PtrtoDir = *DIO_u8ArrDDR[Copy_u8PortNum];  
        Local_DioState = DIO_enuNormal;   
    }
    else 
        Local_DioState =  DIO_enuWrongPortNum;

    return Local_DioState;

}
