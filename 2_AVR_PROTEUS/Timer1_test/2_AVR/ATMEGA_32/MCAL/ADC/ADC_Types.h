/*******************************************************************************************/
/*  Module       :   ADC                                                                   */
/*  File Name    :   ADC_Types.h                                                           */
/*  Description  :   Header File of the ADC Driver Types                                   */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   15/08/2023                                                            */
/*******************************************************************************************/

#ifndef MCAL_ADC_ADC_TYPES_H_
#define MCAL_ADC_ADC_TYPES_H_





/* Type of the auto triggered sources */
typedef enum{
	FREE_RUNNING_MODE,
	ANALOG_COMPARATOR,
	EXTERNAL_INTERRUPT_0,
	TIMER0_COMPARE_MATCH,
	TIMER0_OVERFLOW,
	TIMER1_COMAPRE_MATCH_B,
	TIMER1_OVERFLOW,
	TIMER1_CAPTURE_EVENT
}ADC_AutoTriggerType;


#endif /* MCAL_ADC_ADC_TYPES_H_ */
