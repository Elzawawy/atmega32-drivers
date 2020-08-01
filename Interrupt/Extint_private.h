/*
 * Extint_private.h
 *
 *  Created on: Nov 22, 2018
 *      Author: Omar Hosny & Amr Elzawawy
 */

#ifndef EXTINT_PRIV_H_
#define EXTINT_PRIV_H_

#define NULL ((void *)0x00)
#define HIGH 1
#define LOW 0

/*************** ISR *********************/
#define ISR(__vector_num)                                                      \
    void __vector_num(void) __attribute__((signal, used, externally_visible)); \
    void __vector_num(void)

void (*ptrINT0)(void) = NULL;
void (*ptrINT1)(void) = NULL;
void (*ptrINT2)(void) = NULL;

/*************** Registers Bits Definition *****************/
//Global Interrupt Enable
#define I 7
//GICR INT0 Enable
#define INT0 6
//GICR INT1 Enable
#define INT1 7
//GICR INT2 Enable
#define INT2 5
//GIFR INT0 Enable
#define INTF0 6
//GIFR INT1 Enable
#define INTF1 7
//GIFR INT2 Enable
#define INTF2 5
//MCUCR INT0 Sense Control bits.
#define ISC00 0
#define ISC01 1
//MCUCR INT1 Sense Control bits.
#define ISC10 2
#define ISC11 3
//MCUCSR INT2 Sense Control bits.
#define ISC2 6


#endif
