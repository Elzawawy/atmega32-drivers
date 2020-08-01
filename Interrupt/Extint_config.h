/*
 * Extint_config.h
 *
 *  Created on: Nov 22, 2018
 *      Author: Omar Hosny & Amr Elzawawy
 */

#ifndef EXTINT_CONFIG_H_
#define EXTINT_CONFIG_H_
/*
 * Interrupt 0 Sense Control
ISC01 ISC00 Description
  0     0   The low level of INT0 generates an interrupt request.
  0     1   Any logical change on INT0 generates an interrupt request.
  1     0   The falling edge of INT0 generates an interrupt request.
  1     1   The rising edge of INT0 generates an interrupt request.
 * 
 */

#define ISC00_INITVAL  1
#define ISC01_INITVAL  0

/*
 * Interrupt 1 Sense Control
ISC11 ISC10 Description
  0     0   The low level of INT1 generates an interrupt request.
  0     1   Any logical change on INT1 generates an interrupt request.
  1     0   The falling edge of INT1 generates an interrupt request.
  1     1   The rising edge of INT1 generates an interrupt request.
 *
 */

#define ISC10_INITVAL  1
#define ISC11_INITVAL  0

/* INT2_State
	falling=0
	rising=1
*/
#define ISC2_INITVAL 1 

#endif 