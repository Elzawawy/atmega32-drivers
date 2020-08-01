/*
 * Registers.h
 *
 *  Created on: Nov 27, 2018
 *      Author: ENG A
 */

#ifndef REGISTERS_REGISTERS_H_
#define REGISTERS_REGISTERS_H_

//DIO_Registers
#define PORTA *(( volatile u8*)0x3B)
#define PORTB *(( volatile u8*)0x38)
#define PORTC *(( volatile u8*)0x35)
#define PORTD *(( volatile u8*)0x32)

#define DDRA *(( volatile u8*)0x3A)
#define DDRB *(( volatile u8*)0x37)
#define DDRC *(( volatile u8*)0x34)
#define DDRD *(( volatile u8*)0x31)

#define PINA *(( volatile u8*)0x39)
#define PINB *(( volatile u8*)0x36)
#define PINC *(( volatile u8*)0x33)
#define PIND *(( volatile u8*)0x30)

//TIMER0_Registers
#define  TCCR0 	(*(volatile u8 *) 0x53 )
#define  TCNT0 	(*(volatile u8 *) 0x52 )
#define  OCR0	(*(volatile u8 *) 0x5C )
#define  TIMSK	(*(volatile u8 *) 0x59 )
#define  TIFR	(*(volatile u8 *) 0x58 )
//#define  SREG   (*(volatile u8 *) 0x5F )

//TIMER0_Registers
#define TCCR1A     *((u8*)0X4F)
#define TCCR1B     *((u8*)0X4E)
#define TCNT1H     *((u8*)0X4D)
#define TCNT1L     *((u8*)0X4C)
#define TCNT1      *((u16*)0X4C)
#define OCR1AH     *((u8*)0X4B)
#define OCR1AL     *((u8*)0X4A)
#define OCR1BH     *((u8*)0X49)
#define OCR1BL     *((u8*)0X48)
#define ICR1H      *((u8*)0X47)
#define ICR1L      *((u8*)0X46)

//INT_Registers
#define SREG *((volatile u8*) 0x5F)
#define GICR *((volatile u8*) 0x5B)
#define GIFR *((volatile u8*) 0x5A)
#define MCUCR *((volatile u8*) 0x55)
#define MCUCSR *((volatile u8*) 0x54)

#endif /* REGISTERS_REGISTERS_H_ */
