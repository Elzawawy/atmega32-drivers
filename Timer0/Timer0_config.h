/*
 * Timer0_config.h
 *
 *  Created on: 26 September, 2018
 *      Author: Amr Elzawawy
 */

/* Timer/Counter0 Control Register – TCCR0 
-------------------------------------------
Bit 6, 3 – WGM01:0: Waveform Generation Mode
--------------------------------------------
WGM01 WGM00 Timer/Counter Mode of Operation
  0     0               Normal 
  0     1          PWM, Phase Correct
  1     0                 CTC
  1     1               Fast PWM
--------------------------------------------
RANGE : ( HIGH_VAL "1" or LOW_VAL "0")
*/

#define WGM01_VAL 0 
#define WGM00_VAL 0

/* Bit 5:4 – COM01:0: Compare Match Output Mode 
---------------------------------------------------
Compare Output Mode, non-PWM Mode
COM01 COM00     Description
  0     0    Normal port operation, OC0 disconnected.
  0     1    Toggle OC0 on compare match
  1     0    Clear OC0 on compare match
  1     1    Set OC0 on compare match
---------------------------------------------------
Compare Output Mode, Fast PWM Mode
COM01 COM00           Description
  0     0   Normal port operation, OC0 disconnected.
  0     1              Reserved
  1     0   Clear OC0 on compare match, set OC0 at TOP
  1     1   Set OC0 on compare match, clear OC0 at TOP
---------------------------------------------------
Compare Output Mode, Phase Correct PWM Mode
COM01 COM00            Description
  0     0      Normal port operation, OC0 disconnected.
  0     1                Reserved
  1     0  Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
  1     1  Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
----------------------------------------------------
RANGE : ( HIGH_VAL "1" or LOW_VAL "0")
*/

#define COM01_VAL 0
#define COM00_VAL 0

/*
CS02 CS01 CS00 	Description
0 	  0 	0 	No clock source (Timer/Counter stopped).
0  	  0 	1 	clk/(No prescaling)
0 	  1 	0 	clk/8 (From prescaler)
0     1 	1 	clk/64 (From prescaler)
1 	  0 	0 	clk/256 (From prescaler)
1 	  0 	1   clk/1024 (From prescaler)
1 	  1 	0 	External clock source on T0 pin. Clock on falling edge.
1 	  1 	1 	External clock source on T0 pin. Clock on rising edge.

RANGE : ( HIGH_VAL "1" or LOW_VAL "0")
*/
#define CS02_VAL 1
#define CS01_VAL 0
#define CS00_VAL 1

/*Timer/Counter Interrupt Mask Register – TIMSK
--------------------------------------------------
/* Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable 
RANGE : ( HIGH_VAL "1" or LOW_VAL "0") */
#define OCIE0_VAL 0
/* Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable 
RANGE : ( HIGH_VAL "1" or LOW_VAL "0") */
#define TOIE0_VAL 0




