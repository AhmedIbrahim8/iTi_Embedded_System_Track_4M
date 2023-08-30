/*
 * Timer1_Types.h
 *
 *  Created on: 19 Aug 2023
 *      Author: mosam
 */

#ifndef TIMER1_TYPES_H_
#define TIMER1_TYPES_H_
/* Enumeration for the mode selection */
typedef enum{
	TIMER1_NORMAL_MODE,
	TIMER1_PWM_PHASE_CORRECT_8_BIT,
	TIMER1_PWM_PHASE_CORRECT_9_BIT,
	TIMER1_PWM_PHASE_CORRECT_10_BIT,
	TIMER1_CTC_MODE_OCR1A,
	TIMER1_FAST_PWM_8_BIT,
	TIMER1_FAST_PWM_9_BIT,
	TIMER1_FAST_PWM_10_BIT,
	TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR1,
	TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR1A,
	TIMER1_PWM_PHASE_CORRECT_ICR1,
	TIMER1_PWM_PHASE_CORRECT_OCR1A,
	TIMER1_CTC_MODE_ICR1A,
	TIMER1_RESERVED_MODE,
	TIMER1_FAST_PWM_ICR1,
	TIMER1_FAST_PWM_OCR1A,
}Timer1_ModeType;

/* Enumeration for the pre-scaler selection*/
typedef enum{
	TIMER1_NO_CLK_SOURCE,
	TIMER1_CLK_NO_PRESCALER,
	TIMER1_CLK_8,
	TIMER1_CLK_64,
	TIMER1_CLK_256,
	TIMER1_CLK_1024,
	TIMER1_EXTERNAL_CLK_FALLING_EDGE,
	TIMER1_EXTERNAL_CLK_RISING_EDGE
}Timer1_PrescalerType;


/* Enumeration for OC1A in Non PWM Mode */
typedef enum{
	NORMAL_PORT_OC1A_NON_PWM,
	TOGGLE_OC1A_ON_COMAPRE_MATCH,
	CLEAR_OC1A_ON_COMPARE_MATCH,
	SET_OC1A_ON_COMPARE_MATCH,
}Timer1_OC1AMode_NonPwm;

/* Enumeration for OC1B in Non PWM Mode */
typedef enum{
	NORMAL_PORT_OC1B_NON_PWM,
	TOGGLE_OC1B_ON_COMAPRE_MATCH,
	CLEAR_OC1B_ON_COMPARE_MATCH,
	SET_OC1B_ON_COMPARE_MATCH,
}Timer1_OC1BMode_NonPwm;




typedef enum{
	NORMAL_PORT_OC1A_FAST_PWM,
	TOGGLE_OC1A_ON_COMAPRE_MATCH_FAST_PWM,
	CLEAR_OC1A_ON_COMPARE_MATCH_NON_INVERTING_FAST_PWM,
	SET_OC1A_ON_COMPARE_MATCH_INVERTING_FAST_PWM,
}Timer1_OC1AMode_FastPwm;


typedef enum{
	NORMAL_PORT_OC1B_FAST_PWM,
	OC1B_DISCONNECTED_FAST_PWM,
	CLEAR_OC1B_ON_COMPARE_MATCH_NON_INVERTING_FAST_PWM,
	SET_OC1B_ON_COMPARE_MATCH_INVERTING_FAST_PWM,
}Timer1_OC1BMode_FastPwm;




typedef enum{
	NORMAL_PORT_OC1A_PHASE_CORRECT_PWM,
	TOGGLE_OC1A_ON_COMAPRE_MATCH_PHASE_CORRECT_PWM,
	CLEAR_OC1A_ON_COMPARE_MATCH_UP_COUNTING,
	SET_OC1A_ON_COMPARE_MATCH_DOWN_COUNTING,
}Timer1_OC1AMode_PhaseCorrectPwm;


typedef enum{
	NORMAL_PORT_OC1B_PHASE_CORRECT_PWM,
	OC1B_DISCONNECTED_PHASE_CORRECT_PWM,
	CLEAR_OC1B_ON_COMPARE_MATCH_UP_COUNTING,
	SET_OC1B_ON_COMPARE_MATCH_DOWN_COUNTING,
}Timer1_OC1BMode_PhaseCorrectPwm;



typedef struct {
	Timer1_ModeType                                  mode;
	Timer1_OC1AMode_NonPwm                           OC1A_nonPwm;
	Timer1_OC1BMode_NonPwm                           OC1B_nonPwm;
	Timer1_OC1AMode_FastPwm                          OC1A_fastPwm;
	Timer1_OC1BMode_FastPwm                          OC1B_fastPwm;
	Timer1_OC1AMode_PhaseCorrectPwm                  OC1A_phaseCorrectPwm;
	Timer1_OC1BMode_PhaseCorrectPwm                  OC1B_phaseCorrectPwm;
}Timer1_ConfigType;




#endif /* TIMER1_TYPES_H_ */