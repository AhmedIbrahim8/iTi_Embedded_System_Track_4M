/*******************************************************************************************/
/*  Module       :   TIMER2                                                                */
/*  File Name    :   Timer2_Cfg.h                                                          */
/*  Description  :   Header File of the Configuration of Timer2                            */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   21/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TIMER2_TIMER2_CFG_H_
#define MCAL_TIMER2_TIMER2_CFG_H_

#define    TIMER2_CLOCK_SOURCE                   TIMER_2_EXTERNAL_CLOCK_SOURCE
#define    TIMER2_MODE                           TIMER2_FAST_PWM
#define    TIMER2_OC2_NON_PWM   		         TOGGLE_OC2_ON_COMAPRE_MATCH
#define	   TIMER2_OC2_FAST_PWM                   CLEAR_OC2_ON_COMPARE_MATCH_NON_INVERTING
#define    TIMER2_OC2_PHASE_CORRECT_PWM	         TIMER2_NORMAL_PORT_PHASE_CORRECT_PWM



#endif /* MCAL_TIMER0_TIMER0_CFG_H_ */
