/*******************************************************************************************/
/*  Module       :   TIMER2                                                                */
/*  File Name    :   Timer2_Types.h                                                        */
/*  Description  :   Header File of the Timer2 types                                       */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   21/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TIMER2_TIMER2_TYPES_H_
#define MCAL_TIMER2_TIMER2_TYPES_H_

/* Enumeration for the mode selection */
typedef enum{
	TIMER2_NORMAL_MODE,
	TIMER2_PWM_PHASE_CORRECT,
	TIMER2_CTC_MODE,
	TIMER2_FAST_PWM
}Timer2_ModeType;

/* Enumeration for the pre-scaler selection*/
typedef enum{
	TIMER2_NO_CLOCK_SOURCE,
	TIMER2_CLK_NO_PRESCALER,
	TIMER2_CLK_8,
	TIMER2_CLK_32,
	TIMER2_CLK_64,
	TIMER2_CLK_128,
	TIMER2_CLK_256,
	TIMER2_CLK_1024,
}Timer2_PrescalerType;

typedef enum{
	TIMER2_NORMAL_PORT_NON_PWM,
	TOGGLE_OC2_ON_COMAPRE_MATCH,
	CLEAR_OC2_ON_COMPARE_MATCH,
	SET_OC2_ON_COMPARE_MATCH
}Timer2_OC2Mode_NonPwm;



typedef enum{
	TIMER2_NORMAL_PORT_FAST_PWM,
	TIMER2_RESERVED_FAST_PWM,
	CLEAR_OC2_ON_COMPARE_MATCH_NON_INVERTING,
	SET_OC2_ON_COMPARE_MATCH_INVERTING
}Timer2_OC2Mode_FastPwm;





typedef enum{
	TIMER2_NORMAL_PORT_PHASE_CORRECT_PWM,
	TIMER2_RESERVED_PHASE_CORRECT_PWM,
	CLEAR_OC2_ON_COMPARE_MATCH_UP_COUNTING,
	SET_OC2_ON_COMPARE_MATCH_DOWN_COUNTING
}Timer2_OC2Mode_PhaseCorrectPwm;

typedef enum{
	TIMER_2_INTERNAL_CLOCK_SOURCE,
	TIMER_2_EXTERNAL_CLOCK_SOURCE
}Timer2_ClockSourceType;


typedef struct{
	Timer2_ClockSourceType clockSource;
	Timer2_ModeType mode;
	Timer2_OC2Mode_NonPwm oc2_nonPwm;
	Timer2_OC2Mode_FastPwm oc2_fastPwm;
	Timer2_OC2Mode_PhaseCorrectPwm oc2_phaseCorrectPwm;
}Timer2_ConfigType;




#endif /* MCAL_TIMER0_TIMER0_TYPES_H_ */
