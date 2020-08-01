/*
 * DIO_int.h
 *
 *  Created on: 13 September, 2018
 *      Author: Amr Elzawawy
 */

#ifndef DIO_INT
#define DIO_INT
/*Digital I/O pins*/
typedef enum DIO_enuPinNum{
    DIO_enuPin0=0,
    DIO_enuPin1,
    DIO_enuPin2,
    DIO_enuPin3,
    DIO_enuPin4,
    DIO_enuPin5,
    DIO_enuPin6,
    DIO_enuPin7,
    DIO_enuPin8,
    DIO_enuPin9,
    DIO_enuPin10,
    DIO_enuPin11,
    DIO_enuPin12,
    DIO_enuPin13,
    DIO_enuPin14,
    DIO_enuPin15,
    DIO_enuPin16,
    DIO_enuPin17,
    DIO_enuPin18,
    DIO_enuPin19,
    DIO_enuPin20,
    DIO_enuPin21,
    DIO_enuPin22,
    DIO_enuPin23,
    DIO_enuPin24,
    DIO_enuPin25,
    DIO_enuPin26,
    DIO_enuPin27,
    DIO_enuPin28,
    DIO_enuPin29,
    DIO_enuPin30,
    DIO_enuPin31
} DIO_enuPinNum;

/*Digital I/O ports*/
typedef enum DIO_enuPortNum{
    DIO_enuPortA=0,
    DIO_enuPortB,
    DIO_enuPortC,
    DIO_enuPortD
}DIO_enuPortNum;

/*Digital I/O Values */
#define DIO_u8HIGHVAL   1
#define DIO_u8LOWVAL    0

/*Digital I/O Directions */
#define DIO_u8PIN_INPUTDIR   0
#define DIO_u8PIN_OUTPUTDIR  1
#define DIO_u8PORT_INPUTDIR  0x00
#define DIO_u8PORT_OUTPUTDIR 0xFF

/*Digital I/O Characteristics */
#define DIO_u8NumOfPorts         4
#define DIO_u8NumOfPins          32
#define DIO_u8NumOfPinsPerPort   8

/* Digital I/O states */
typedef enum DIO_enuDioState {
    DIO_enuNormal = 0,
    DIO_enuWrongPinVal,
    DIO_enuWrongPinNum,
    DIO_enuWrongPinDir,
    DIO_enuWrongPortNum,
    DIO_enuWrongPortDir,
}DIO_enuDioState;

/* Initialize Method*/
extern void DIO_voidInit(void);

/* IO Pins */
extern u8 DIO_u8SetPinValue (u8 Copy_u8PinNum, u8 Copy_u8PinVal);

extern u8 DIO_u8GetPinValue (u8 Copy_u8PinNum,u8* u8PtrtoVal);

extern u8 DIO_u8SetPinDir (u8 Copy_u8PinNum, u8 Copy_u8PinDir);

extern u8 DIO_u8GetPinDir (u8 Copy_u8PinNum, u8* u8PtrtoDir);

/* IO Ports */

extern u8 DIO_u8SetPortValue (u8 Copy_u8PortNum, u8 Copy_u8PortVal);

extern u8 DIO_u8GetPortValue (u8 Copy_u8PortNum,u8* u8PtrtoVal);

extern u8 DIO_u8SetPortDir (u8 Copy_u8PortNum, u8 Copy_u8PortDir);

extern u8 DIO_u8GetPortDir (u8 Copy_u8PortNum, u8* u8PtrtoDir);


#endif
