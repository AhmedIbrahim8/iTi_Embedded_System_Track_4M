/*******************************************************************************************/
/*  Module       :   ADC                                                                   */
/*  File Name    :   ADC.h                                                                 */
/*  Description  :   Header File of the ADC Driver                                         */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   15/08/2023                                                            */
/*******************************************************************************************/

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "ADC_Types.h"
#include "ADC_Cfg.h"

/* defines of reference voltage of the ADC */
#define ADC_REFERENCE_TYPE_AREF            0
#define ADC_REFERENCE_TYPE_AVCC            1
#define ADC_REFERENCE_TYPE_INTERNAL        3

/***/
#define ADC_ADJUST_TYPE_RIGHT              0
#define ADC_ADJUST_TYPE_LEFT               1

/**/
#define AUTO_TRIGGER_ENABLE                1
#define AUTO_TRIGGER_DISABLE               0

/* Channel Numbers */
#define ADC_CHANNEL_0                           0
#define ADC_CHANNEL_1                           1
#define ADC_CHANNEL_2                           2
#define ADC_CHANNEL_3                           3
#define ADC_CHANNEL_4                           4
#define ADC_CHANNEL_5                           5
#define ADC_CHANNEL_6                           6
#define ADC_CHANNEL_7                           7


/* defines  of the prescaler */
#define 	ACD_PRESCALER_DIVISION_2            1
#define 	ACD_PRESCALER_DIVISION_4            2
#define 	ACD_PRESCALER_DIVISION_8            3
#define 	ACD_PRESCALER_DIVISION_16           4
#define 	ACD_PRESCALER_DIVISION_32           5
#define 	ACD_PRESCALER_DIVISION_64           6
#define 	ACD_PRESCALER_DIVISION_128          7


/* This Function responsible of :                                         */
/*    - Adjust the voltage reference                                      */
/*    - Adjust the right and left adjust                                  */
/*    - free running or single conversion mode                            */
/*    - If auto triggered is on, it adjust the source of auto triggered   */
/*    - Adjust the clock of the ADC Module                                */
void ADC_voidInit(void);



/* Function responsible of enable the ADC */
void ADC_voidEnable(void);

/* Function responsible of disable the ADC */
void ADC_voidDisable(void);

/* Function responsible of enable the interrupt */
void ADC_voidEnableInterrupt(void);

/* Function responsible of disable the interrupt
 * In this case, you need to make polling to get the value of the digital value */
void ADC_voidDisableInterrupt(void);

/* Function Responsible of setting the call back of the ADC Driver
 * Advantages : To make the ADC Driver not dependent on the Application*/
void ADC_voidSetCallback(void (*local_Call_Back) (void));

void ADC_voidStartConversion(uint8 u8ChannelNbCpy);

void ADC_voidChangeMode(uint8 u8ModeCpy);

/* Read the value from ADC polling method*/
uint16 ADC_u16ReadSync(uint8 u8ChannelNbCpy);
/* Read the value from ADC Interrupt method*/
uint16 ADC_u16ReadAsync(void);


#endif /* MCAL_ADC_ADC_H_ */
