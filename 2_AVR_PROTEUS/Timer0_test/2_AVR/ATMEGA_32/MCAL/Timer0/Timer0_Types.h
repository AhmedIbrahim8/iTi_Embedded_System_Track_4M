/*******************************************************************************************/
/*  Module       :   TIMER0                                                                */
/*  File Name    :   Timer0_Types.h                                                        */
/*  Description  :   Header File of the Timer0 types                                       */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   18/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TIMER0_TIMER0_TYPES_H_
#define MCAL_TIMER0_TIMER0_TYPES_H_

/* Enumeration for the mode selection */
typedef enum{
	TIMER0_NORMAL_MODE,
	TIMER0_PWM_PHASE_CORRECT,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM
}Timer0_ModeType;

/* Enumeration for the pre-scaler selection*/
typedef enum{
	TIMER0_NO_CLOCK_SOURCE,
	TIMER0_CLK_NO_PRESCALER,
	TIMER0_CLK_8,
	TIMER0_CLK_64,
	TIMER0_CLK_256,
	TIMER0_CLK_1024,
	TIMER0_EXT_CLK_FALLING_EDGE,
	TIMER0_EXT_CLK_RISING_EDGE,
}Timer0_PrescalerType;

typedef enum{
	NORMAL_PORT_NON_PWM,
	TOGGLE_OC0_ON_COMAPRE_MATCH,
	CLEAR_OCO_ON_COMPARE_MATCH,
	SET_OCO_ON_COMPARE_MATCH
}Timer0_OC0Mode_NonPwm;


typedef enum{
	NORMAL_PORT_FAST_PWM,
	RESERVED_FAST_PWM,
	CLEAR_OCO_ON_COMPARE_MATCH_NON_INVERTING,
	SET_OCO_ON_COMPARE_MATCH_INVERTING
}Timer0_OC0Mode_FastPwm;


typedef enum{
	NORMAL_PORT_PHASE_CORRECT_PWM,
	RESERVED_PHASE_CORRECT_PWM,
	CLEAR_OCO_ON_COMPARE_MATCH_UP_COUNTING,
	SET_OCO_ON_COMPARE_MATCH_DOWN_COUNTING
}Timer0_OC0Mode_PhaseCorrectPwm;

typedef struct{
	Timer0_ModeType mode;
	Timer0_OC0Mode_NonPwm oc0_nonPwm;
	Timer0_OC0Mode_FastPwm oc0_fastPwm;
	Timer0_OC0Mode_PhaseCorrectPwm oc0_phaseCorrectPwm;
}Timer0_ConfigType;

#endif /* MCAL_TIMER0_TIMER0_TYPES_H_ */
