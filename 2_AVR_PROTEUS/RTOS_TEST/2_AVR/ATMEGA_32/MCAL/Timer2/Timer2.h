/*******************************************************************************************/
/*  Module       :   TIMER2                                                                */
/*  File Name    :   Timer2.h                                                              */
/*  Description  :   Header File of the Timer2                                             */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   21/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_
#include "..\..\LIB\Std_Types.h"
#include "Timer2_Cfg.h"
#include "Timer2_Types.h"
/* Extern the configuration of Timer 2 */
extern Timer2_ConfigType Timer2_configuration;

/* #s for the overflow interrupt enable      */
#define TIMER2_OVF_INTERRUPT_ENABLE      1
#define TIMER2_OVF_INTERRUPT_DISABLE     0
/* #s for the compare match interrupt enable */
#define TIMER2_CMP_INTERRUPT_ENABLE      1
#define TIMER2_CMP_INTERRUPT_DISABLE     0

/* This function responsible for choose the mode and oc0 selection type */
void TIMER2_voidTimer2_Init(void);

/* Function Responsible for Adjusting the Pre-scaler to start the timer */
void TIMER2_voidEnable(Timer2_PrescalerType PreScaler);

/* Function Responsible for disable the Pre-scaler to stop the timer */
void TIMER2_voidDisable(void);

/* Function to set the pre-load value of the TCNT0 */
void TIMER2_voidSetTCNTValue(uint8 u8TcntReg);

/* Function to return the TCNT0 value */
uint8 TIMER2_u8ReadTcntReg(void);

/* Function to set the OCR0 value */
void TIMER2_voidSetOCRValue(uint8 Copy_u8OCRValue);

/* Function to enable the overflow interrupt */
void TIMER2_voidEnableOvfINT(void);

/* Function to disable the overflow interrupt */
void TIMER2_voidDisableOvfINT(void);

/* Function to enable the compare match interrupt */
void TIMER2_voidEnableCompareINT(void);

/* Function to disable the compare match interrupt */
void TIMER2_voidDisableCompareINT(void);




void TIMER2_voidTimer2OVFSetCallBack(void (*local_pf) (void));

void TIMER2_voidTimer2CMPSetCallBack(void (*local_pf) (void));



#endif /* MCAL_TIMER0_TIMER0_H_ */
