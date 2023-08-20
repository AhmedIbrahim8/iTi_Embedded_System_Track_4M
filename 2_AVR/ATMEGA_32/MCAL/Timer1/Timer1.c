/*******************************************************************************************/
/*  Module       :   TIMER1                                                                */
/*  File Name    :   Timer1.c                                                              */
/*  Description  :   Source File of the Timer1                                             */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   18/08/2023                                                            */
/*******************************************************************************************/
#include "..\DIO_DRIVER\Dio_Interface.h"
#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "Timer1.h"
#include "Timer1_Registers.h"

static void (*TIMER1_pfTimer1OVF)(void);
static void (*TIMER1_pfTimer1CMPA)(void);
static void (*TIMER1_pfTimer1CMPB)(void);
/* Function responsible of :
 *     1 -  Adjust the mode of the Timer 1
 *     2 -  Adjust OCR1A and OCR1B Pins incase of
 *          NON-Pwm or Fast pwm or PHase correct Pwm   */
void TIMER1_voidTimer1_Init(void){
	TCCR1A = (TCCR1A & 0xFC) | (Timer1_configuration.mode & 0x03);
	TCCR1B = (TCCR1B & 0xE7) | ((Timer1_configuration.mode & 0x0C)<<1);
	switch(Timer1_configuration.mode){
	/* In case of Non PWM Mode which is :   */
	/*       1 - Normal  Mode               */
	/*       2 - Compare Mode               */
	/*           * Top = OCR1A              */
	/*           * Top = ICR1               */
	case TIMER1_NORMAL_MODE:
	case TIMER1_CTC_MODE_OCR1A:
	case TIMER1_CTC_MODE_ICR1A:
		/* Adjust the Channel A & B of the Timer based on the
		 * configuration which user choose      */
		TCCR1A = (TCCR1A & 0x3F) | (Timer1_configuration.OC1A_nonPwm << COM1A0);
		TCCR1A = (TCCR1A & 0xCF) | (Timer1_configuration.OC1B_nonPwm << COM1B0);
		SET_BIT(TCCR1A,FOC1A);
		SET_BIT(TCCR1A,FOC1B);
		break;
	case TIMER1_FAST_PWM_8_BIT:
	case TIMER1_FAST_PWM_9_BIT:
	case TIMER1_FAST_PWM_10_BIT:
	case TIMER1_FAST_PWM_ICR1:
	case TIMER1_FAST_PWM_OCR1A:
		/* Adjust the Channel A & B of the Timer based on the
		 * configuration which user choose      */
		TCCR1A = (TCCR1A & 0x3F) | (Timer1_configuration.OC1A_fastPwm << COM1A0);
		TCCR1A = (TCCR1A & 0xCF) | (Timer1_configuration.OC1B_fastPwm << COM1B0);
		CLEAR_BIT(TCCR1A,FOC1A);
		CLEAR_BIT(TCCR1A,FOC1B);
		break;
	case TIMER1_PWM_PHASE_CORRECT_8_BIT:
	case TIMER1_PWM_PHASE_CORRECT_9_BIT:
	case TIMER1_PWM_PHASE_CORRECT_10_BIT:
	case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR1:
	case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR1A:
	case TIMER1_PWM_PHASE_CORRECT_ICR1:
	case TIMER1_PWM_PHASE_CORRECT_OCR1A:
		/* Adjust the Channel A & B of the Timer based on the
		 * configuration which user choose      */
		TCCR1A = (TCCR1A & 0x3F) | (Timer1_configuration.OC1A_phaseCorrectPwm << COM1A0);
		TCCR1A = (TCCR1A & 0xCF) | (Timer1_configuration.OC1B_phaseCorrectPwm << COM1B0);
		CLEAR_BIT(TCCR1A,FOC1A);
		CLEAR_BIT(TCCR1A,FOC1B);
		break;
	}

}


/* Function Responsible for Adjusting the Pre-scaler to start the timer */
void TIMER1_voidEnable(Timer1_PrescalerType PreScaler){
	if(PreScaler < TIMER1_EXTERNAL_CLK_RISING_EDGE){
		/* 0xF8  => To mask the first 3 bits to be zero then or-ing with the pre-scaler*/
		TCCR1B = (TCCR1B & 0xF8) | (PreScaler & 0x07);
	}
	else{
		/* Out of range */
	}

}

/* Function Responsible for disable the Pre-scaler to stop the timer */
void TIMER1_voidDisable(){
	/* Zeros for the first 3-bits */
	TCCR1B = TCCR1B & 0xF8;
}



/* Function to set the pre-load value of the TCNT1 */
void TIMER1_voidSetTCNT1Value(uint16 u16TcntReg)
{
	TCNT1 = u16TcntReg;
}

/* Function to return the TCNT1 value */
uint16 TIMER1_u16ReadTcnt1Reg()
{
	return TCNT1 ;
}

/* Function to set the OCR1A value */
void TIMER1_voidSetOCR1AValue(uint16 Copy_u16OCRAValue){
	OCR1A=Copy_u16OCRAValue;
}

/* Function to set the OCR1B value */
void TIMER1_voidSetOCR1BValue(uint16 Copy_u16OCRBValue){
	OCR1B=Copy_u16OCRBValue;
}

/* Function to set the ICR1 value */
void TIMER1_voidSetICR1Value(uint16 Copy_u16ICR1Value){
	ICR1=Copy_u16ICR1Value;
}

/* Function to enable the overflow interrupt */
void TIMER1_voidEnableOvfINT(){
	SET_BIT(TIMSK,TOIE1);
}
/* Function to disable the overflow interrupt */
void TIMER1_voidDisableOvfINT(){
	CLEAR_BIT(TIMSK,TOIE1);
}

/* Function to enable the compare match A interrupt */
void TIMER1_voidEnableCompareAINT(){
	SET_BIT(TIMSK,OCIE1A);
}
/* Function to disable the compare match A interrupt */
void TIMER1_voidDisableCompareAINT(){
	CLEAR_BIT(TIMSK,OCIE1A);
}

/* Function to enable the compare match B interrupt */
void TIMER1_voidEnableCompareBINT(){
	SET_BIT(TIMSK,OCIE1B);
}
/* Function to disable the compare match B interrupt */
void TIMER1_voidDisableCompareBINT(){
	CLEAR_BIT(TIMSK,OCIE1B);
}


/* Function to change the mode */
void TIM1_voidChangMode(Timer1_ConfigType *Timer1_new_Config){
	TCCR1A = (TCCR1A & 0xFC) | (Timer1_new_Config->mode & 0x03);
	TCCR1B = (TCCR1B & 0xE7) | ((Timer1_new_Config->mode & 0x0C)<<1);
	switch(Timer1_new_Config->mode){
	/* In case of Non PWM Mode which is :   */
	/*       1 - Normal  Mode               */
	/*       2 - Compare Mode               */
	/*           * Top = OCR1A              */
	/*           * Top = ICR1               */
	case TIMER1_NORMAL_MODE:
	case TIMER1_CTC_MODE_OCR1A:
	case TIMER1_CTC_MODE_ICR1A:
		/* Adjust the Channel A & B of the Timer based on the
		 * configuration which user choose      */
		TCCR1A = (TCCR1A & 0x3F) | (Timer1_new_Config->OC1A_nonPwm << COM1A0);
		TCCR1A = (TCCR1A & 0xCF) | (Timer1_new_Config->OC1B_nonPwm << COM1B0);
		SET_BIT(TCCR1A,FOC1A);
		SET_BIT(TCCR1A,FOC1B);
		break;
	case TIMER1_FAST_PWM_8_BIT:
	case TIMER1_FAST_PWM_9_BIT:
	case TIMER1_FAST_PWM_10_BIT:
	case TIMER1_FAST_PWM_ICR1:
	case TIMER1_FAST_PWM_OCR1A:
		/* Adjust the Channel A & B of the Timer based on the
		 * configuration which user choose      */
		TCCR1A = (TCCR1A & 0x3F) | (Timer1_new_Config->OC1A_fastPwm << COM1A0);
		TCCR1A = (TCCR1A & 0xCF) | (Timer1_new_Config->OC1B_fastPwm << COM1B0);
		CLEAR_BIT(TCCR1A,FOC1A);
		CLEAR_BIT(TCCR1A,FOC1B);
		break;
	case TIMER1_PWM_PHASE_CORRECT_8_BIT:
	case TIMER1_PWM_PHASE_CORRECT_9_BIT:
	case TIMER1_PWM_PHASE_CORRECT_10_BIT:
	case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR1:
	case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR1A:
	case TIMER1_PWM_PHASE_CORRECT_ICR1:
	case TIMER1_PWM_PHASE_CORRECT_OCR1A:
		/* Adjust the Channel A & B of the Timer based on the
		 * configuration which user choose      */
		TCCR1A = (TCCR1A & 0x3F) | (Timer1_new_Config->OC1A_phaseCorrectPwm << COM1A0);
		TCCR1A = (TCCR1A & 0xCF) | (Timer1_new_Config->OC1B_phaseCorrectPwm << COM1B0);
		CLEAR_BIT(TCCR1A,FOC1A);
		CLEAR_BIT(TCCR1A,FOC1B);
		break;
	}

}

/* Function to set the call back of the overflow mode */
void TIMER1_voidTimer1OVFSetCallBack(void (*local_pf) (void))
{
	if(local_pf != NULL_PTR){
		TIMER1_pfTimer1OVF=local_pf;
	}
	else{
		/* Do No thing*/
	}
}
/* Function to set the call back of the Compare A mode */
void TIMER1_voidTimer1CMPASetCallBack(void (*local_pf) (void))
{
	if(local_pf != NULL_PTR){
		TIMER1_pfTimer1CMPA=local_pf;
	}
	else{
		/* Do No thing*/
	}

}
/* Function to set the call back of the Compare B mode */
void TIMER1_voidTimer1CMPBSetCallBack(void (*local_pf) (void))
{
	if(local_pf != NULL_PTR){
		TIMER1_pfTimer1CMPB=local_pf;
	}
	else{
		/* Do No thing*/
	}

}




/* Interrupt handling Of the Overflow */
void __vector_9  (void)          __attribute__ ((signal,used));
void __vector_9  (void)
{

	if(TIMER1_pfTimer1OVF != NULL_PTR){
		TIMER1_pfTimer1OVF();
	}
	else{

	}
}


/* Interrupt handling Of the Compare A */
void __vector_7  (void)          __attribute__ ((signal,used));
void __vector_7  (void)
{

	if(TIMER1_pfTimer1CMPA != NULL_PTR){
		TIMER1_pfTimer1CMPA();
	}
	else{

	}
}


/* Interrupt handling Of the Compare B */
void __vector_8  (void)          __attribute__ ((signal,used));
void __vector_8  (void)
{

	if(TIMER1_pfTimer1CMPB != NULL_PTR){
		TIMER1_pfTimer1CMPB();
	}
	else{

	}
}
