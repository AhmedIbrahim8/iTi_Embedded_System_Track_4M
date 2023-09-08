/*******************************************************************************************/
/*  Module       :   TIMER0                                                                */
/*  File Name    :   Timer0.h                                                              */
/*  Description  :   Header File of the Timer0                                             */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   18/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_
#include "..\..\LIB\Std_Types.h"
#include "Timer0_Types.h"
#include "Timer0_Cfg.h"
/* Extern the configuration of Timer 0 */
extern Timer0_ConfigType Timer0_configuration;

/* #s for the overflow interrupt enable      */
#define TIMER0_OVF_INTERRUPT_ENABLE      1
#define TIMER0_OVF_INTERRUPT_DISABLE     0
/* #s for the compare match interrupt enable */
#define TIMER0_CMP_INTERRUPT_ENABLE      1
#define TIMER0_CMP_INTERRUPT_DISABLE     0

/* This function responsible for choose the mode and oc0 selection type */
void TIMER0_voidTimer0_Init(void);

/* Function Responsible for Adjusting the Pre-scaler to start the timer */
void TIMER0_voidEnable(Timer0_PrescalerType PreScaler);

/* Function Responsible for disable the Pre-scaler to stop the timer */
void TIMER0_voidDisable(void);

/* Function to set the pre-load value of the TCNT0 */
void TIMER0_voidSetTCNTValue(uint8 u8TcntReg);

/* Function to return the TCNT0 value */
uint8 TIMER0_u8ReadTcntReg(void);

/* Function to set the OCR0 value */
void TIMER0_voidSetOCRValue(uint8 Copy_u8OCRValue);

/* Function to enable the overflow interrupt */
void TIMER0_voidEnableOvfINT(void);

/* Function to disable the overflow interrupt */
void TIMER0_voidDisableOvfINT(void);

/* Function to enable the compare match interrupt */
void TIMER0_voidEnableCompareINT(void);

/* Function to disable the compare match interrupt */
void TIMER0_voidDisableCompareINT(void);




void TIMER0_voidTimer0OVFSetCallBack(void (*local_pf) (void));

void TIMER0_voidTimer0CMPSetCallBack(void (*local_pf) (void));



//
//
//void TIMER1_voidTimer1Init(void);
//
//void TIMER1_voidTimer1SetCompareMatchValueChannelA(uint16 Copy_u16OCR1AValue);

#endif /* MCAL_TIMER0_TIMER0_H_ */
