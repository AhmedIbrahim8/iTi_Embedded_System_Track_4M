
#include "Timer1.h"


Timer1_ConfigType Timer1_configuration={
		TIMER1_CTC_MODE_OCR1A,
		NORMAL_PORT_OC1A_NON_PWM,
		NORMAL_PORT_OC1B_NON_PWM,
		CLEAR_OC1A_ON_COMPARE_MATCH_NON_INVERTING_FAST_PWM,
		SET_OC1B_ON_COMPARE_MATCH_INVERTING_FAST_PWM,
		CLEAR_OC1A_ON_COMPARE_MATCH_UP_COUNTING,
		SET_OC1B_ON_COMPARE_MATCH_DOWN_COUNTING
};
