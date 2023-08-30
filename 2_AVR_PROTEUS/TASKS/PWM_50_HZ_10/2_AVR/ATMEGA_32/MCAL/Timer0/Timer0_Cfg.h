/*******************************************************************************************/
/*  Module       :   TIMER0                                                                */
/*  File Name    :   Timer0_Cfg.h                                                          */
/*  Description  :   Header File of the Configuration of Timer0                            */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   18/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TIMER0_TIMER0_CFG_H_
#define MCAL_TIMER0_TIMER0_CFG_H_

#define    TIMER0_MODE                           TIMER0_FAST_PWM
#define    TIMER0_OC0_NON_PWM   		         TOGGLE_OC0_ON_COMAPRE_MATCH
#define	   TIMER0_OC0_FAST_PWM                   NORMAL_PORT_FAST_PWM
#define    TIMER0_OC0_PHASE_CORRECT_PWM	         NORMAL_PORT_PHASE_CORRECT_PWM


#endif /* MCAL_TIMER0_TIMER0_CFG_H_ */
