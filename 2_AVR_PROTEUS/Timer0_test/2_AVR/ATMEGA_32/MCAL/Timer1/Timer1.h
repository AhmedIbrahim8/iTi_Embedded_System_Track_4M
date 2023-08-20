
#ifndef TIMER1_H_
#define TIMER1_H_
#include "Timer1_Types.h"
extern Timer1_ConfigType Timer1_configuration;


/* Function responsible of :
 *     1 -  Adjust the mode of the Timer 1
 *     2 -  Adjust OCR1A and OCR1B Pins incase of
 *          NON-Pwm or Fast pwm or PHase correct Pwm   */
void TIMER1_voidInit(void);


#endif /* TIMER1_H_ */
