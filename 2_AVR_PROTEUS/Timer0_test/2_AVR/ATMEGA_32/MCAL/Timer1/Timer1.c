//#include "STD_TYPES.h"
//#include "Timer1.h"
//#include "Timer1_Register.h"
///* Function responsible of :
// *     1 -  Adjust the mode of the Timer 1
// *     2 -  Adjust OCR1A and OCR1B Pins incase of
// *          NON-Pwm or Fast pwm or PHase correct Pwm   */
//void TIMER1_voidInit(void){
//	/*         0000  1101*/
//	TCCR1A = (TCCR1A & 0xFC) | (Timer1_configuration.mode & 0x03);
//	TCCR1B = (TCCR1B & 0xE7) | ((Timer1_configuration.mode & 0x0C)<<1);
//	switch(Timer1_configuration.mode){
//	/* In case of Non PWM Mode which is :   */
//	/*       1 - Normal  Mode               */
//	/*       2 - Compare Mode               */
//	/*           * Top = OCR1A              */
//	/*           * Top = ICR1               */
//	case TIMER1_NORMAL_MODE:
//	case TIMER1_CTC_MODE_OCR1A:
//	case TIMER1_CTC_MODE_ICR1A:
//		/* Adjust the Channel A of the Timer based on the
//		 * configuration which user choose      */
//		TCCR1A = (TCCR1A & 0x3F) | (Timer1_configuration.OC1A_nonPwm << COM1A0);
//		break;
//	case:
//		break;
//	}
//
//}
