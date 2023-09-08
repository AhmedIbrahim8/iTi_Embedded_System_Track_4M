
#ifndef TIMER1_H_
#define TIMER1_H_
#include "..\..\LIB\Std_Types.h"
#include "Timer1_Types.h"
/* Extern the configuration of Timer 0 */
extern Timer1_ConfigType Timer1_configuration;

/* #s for the overflow interrupt enable      */
#define TIMER1_OVF_INTERRUPT_ENABLE                1
#define TIMER1_OVF_INTERRUPT_DISABLE               0
/* #s for the compare A match interrupt enable */
#define TIMER1_CMPA_INTERRUPT_ENABLE               1
#define TIMER1_CMPA_INTERRUPT_DISABLE              0
/* #s for the compare B match interrupt enable */
#define TIMER1_CMPB_INTERRUPT_ENABLE               1
#define TIMER1_CMPB_INTERRUPT_DISABLE              0
/* #s for the INPUT CATURE interrupt enable */
#define TIMER1_INPUT_CAPTURE_INTERRUPT_ENABLE      1
#define TIMER1_INPUT_CAPTURE_INTERRUPT_DISABLE     0


/* Function responsible of :
 *     1 -  Adjust the mode of the Timer 1
 *     2 -  Adjust OCR1A and OCR1B Pins incase of
 *          NON-Pwm or Fast pwm or PHase correct Pwm   */
void TIMER1_voidTimer1_Init(void);

/* Function Responsible for Adjusting the Pre-scaler to start the timer */
void TIMER1_voidEnable(Timer1_PrescalerType PreScaler);

/* Function Responsible for disable the Pre-scaler to stop the timer */
void TIMER1_voidDisable();

/* Function to set the pre-load value of the TCNT1 */
void TIMER1_voidSetTCNT1Value(uint16 u16TcntReg);

/* Function to return the TCNT1 value */
uint16 TIMER1_u16ReadTcnt1Reg();

/* Function to set the OCR1A value */
void TIMER1_voidSetOCR1AValue(uint16 Copy_u16OCRAValue);

/* Function to set the OCR1B value */
void TIMER1_voidSetOCR1BValue(uint16 Copy_u16OCRBValue);

/* Function to set the ICR1 value */
void TIMER1_voidSetICR1Value(uint16 Copy_u16ICR1Value);

/* Function to enable the overflow interrupt */
void TIMER1_voidEnableOvfINT();

/* Function to disable the overflow interrupt */
void TIMER1_voidDisableOvfINT();

/* Function to enable the compare match A interrupt */
void TIMER1_voidEnableCompareAINT();
/* Function to disable the compare match A interrupt */
void TIMER1_voidDisableCompareAINT();

/* Function to enable the compare match B interrupt */
void TIMER1_voidEnableCompareBINT();
/* Function to disable the compare match B interrupt */
void TIMER1_voidDisableCompareBINT();

/* Hard ware ICU Functions */
void TIMER1_voidHWICUEnable(void);
void TIMER1_voidHWICUDisable(void);
void TIMER1_voidGetPWMTotalPeriod(uint32 *Copy_pu32TotalPeriod);
void TIMER1_voidGetPWMDutyCycle(uint8 *Copy_pu8DutyCycle);
void TIMER1_voidGetPWMOnPeriod(uint16 *Copy_pu16OnPeriod);
void TIMER1_voidGetPWMOffPeriod(uint16 *Copy_pu16OffPeriod);

/* Function to set the call back of the overflow mode */
void TIMER1_voidTimer1OVFSetCallBack(void (*local_pf) (void));
/* Function to set the call back of the Compare A mode */
void TIMER1_voidTimer1CMPASetCallBack(void (*local_pf) (void));
/* Function to set the call back of the Compare B mode */
void TIMER1_voidTimer1CMPBSetCallBack(void (*local_pf) (void));

#endif /* TIMER1_H_ */
