/*******************************************************************************************/
/*  Module       :   TIMER2                                                                */
/*  File Name    :   Timer2.c                                                              */
/*  Description  :   Source File of the Timer2                                             */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   21/08/2023                                                            */
/*******************************************************************************************/
#include "..\DIO_DRIVER\Dio_Interface.h"
#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "Timer2.h"

#include "Timer2_Registers.h"
/* Global Pointer to function for the overflow mode */
static void (*TIMER2_pfTimer2OVF) (void)=NULL_PTR;
/* Global Pointer to function for the Compare match mode */
static void (*TIMER2_pfTimer2CMP) (void)=NULL_PTR;

/* This function responsible for choose the mode and oc0 selection type */
void TIMER2_voidTimer2_Init(void){
	/* When AS2 is written to zero, Timer/Counter 2 is clocked from the I/O clock,
	 * clkI/O. When AS2 is written to one, Timer/Counter2 is clocked from a Crystal
	 * Oscillator connected to the Timer Oscillator 1 (TOSC1) pin.
	 * */
	switch(Timer2_configuration.clockSource){
	case TIMER_2_INTERNAL_CLOCK_SOURCE:
		CLEAR_BIT(ASSR,AS2);
		break;
	case TIMER_2_EXTERNAL_CLOCK_SOURCE:
		SET_BIT(ASSR,AS2);
		break;
	}
	/* Select the mode of the Timer0 */
	/* Normal mode   :  0b0000 0000  */
	/* PHASE_CORRECT :  0b0000 0001  */
	/* CTC MODE      :  0b0000 0010  */
	/* FAST PWM      :  0b0000 0011  */
	/* TCCR2 :  WGM20    BIT 6 */
	/*          WGM21    BIT 3 */
	switch(Timer2_configuration.mode){
	case TIMER2_NORMAL_MODE:
		CLEAR_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		/* FOC2 is 1 with non PWM Mode */
		SET_BIT(TCCR2,FOC2);
		/* Select the compare match output mode (OC2) */
		TCCR2 = (TCCR2 & 0xCF) | (Timer2_configuration.oc2_nonPwm << COM20);
		break;
	case TIMER2_PWM_PHASE_CORRECT:
		SET_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		/* FOC2 is 1 with non PWM Mode */
		CLEAR_BIT(TCCR2,FOC2);
		/* Select the compare match output mode (OC2) */
		TCCR2 = (TCCR2 & 0xCF) | (Timer2_configuration.oc2_phaseCorrectPwm << COM20);
		break;
	case TIMER2_CTC_MODE:
		SET_BIT(TCCR2,WGM21);
		CLEAR_BIT(TCCR2,WGM20);
		/* FOC2 is 0 with PWM Mode */
		SET_BIT(TCCR2,FOC2);
		/* Select the compare match output mode (OC2) */
		TCCR2 = (TCCR2 & 0xCF) | (Timer2_configuration.oc2_nonPwm << COM20);
		break;
	case TIMER2_FAST_PWM:
		SET_BIT(TCCR2,WGM21);
		SET_BIT(TCCR2,WGM20);
		/* FOC0 is 0 with PWM Mode */
		CLEAR_BIT(TCCR2,FOC2);
		/* Select the compare match output mode (OC2) */
		TCCR2 = (TCCR2 & 0xCF) | (Timer2_configuration.oc2_fastPwm << COM20);
		break;
		/* Wrong mode */
	}

}

/* Function Responsible for Adjusting the Pre-scaler to start the timer */
void TIMER2_voidEnable(Timer2_PrescalerType PreScaler){
	if(PreScaler <= TIMER2_CLK_1024){
		/* 0xF8  => To mask the first 3 bits to be zero then or-ing with the pre-scaler*/
		TCCR2 =(TCCR2 & 0xF8) | (PreScaler & 0x07);
	}
	else
	{
		/* Out of range */
	}
}

/* Function Responsible for disable the Pre-scaler to stop the timer */
void TIMER2_voidDisable(){
	/* Zeros for the first 3-bits */
	TCCR2 = TCCR2 & 0xF8;
}

/* Function to set the pre-load value of the TCNT0 */
void TIMER2_voidSetTCNTValue(uint8 u8TcntReg)
{
	TCNT2 = u8TcntReg;
}

/* Function to return the TCNT0 value */
uint8 TIMER2_u8ReadTcntReg()
{
	return TCNT2 ;
}

/* Function to set the OCR0 value */
void TIMER2_voidSetOCRValue(uint8 Copy_u8OCRValue){
	OCR2=Copy_u8OCRValue;
}


/* Function to enable the overflow interrupt */
void TIMER2_voidEnableOvfINT(){
	SET_BIT(TIMSK,TOIE2);
}
/* Function to disable the overflow interrupt */
void TIMER2_voidDisableOvfINT(){
	CLEAR_BIT(TIMSK,TOIE2);
}
/* Function to enable the compare match interrupt */
void TIMER2_voidEnableCompareINT(){
	SET_BIT(TIMSK,OCIE2);
}
/* Function to disable the compare match interrupt */
void TIMER2_voidDisableCompareINT(){
	CLEAR_BIT(TIMSK,OCIE2);
}

/* Function to change the mode */
void TIM2_voidChangMode(Timer2_ConfigType *new_Config)
{
	/* When AS2 is written to zero, Timer/Counter 2 is clocked from the I/O clock,
	 * clkI/O. When AS2 is written to one, Timer/Counter2 is clocked from a Crystal
	 * Oscillator connected to the Timer Oscillator 1 (TOSC1) pin.
	 * */
	switch(new_Config->clockSource){
	case TIMER_2_INTERNAL_CLOCK_SOURCE:
		CLEAR_BIT(ASSR,AS2);
		break;
	case TIMER_2_EXTERNAL_CLOCK_SOURCE:
		SET_BIT(ASSR,AS2);
		break;
	}
	/* New mode so, we will make TCCR0 equal 0 */
	TCCR2=0;
	/* Select the mode of the Timer0 */
	/* Normal mode   :  0b0000 0000  */
	/* PHASE_CORRECT :  0b0000 0001  */
	/* CTC MODE      :  0b0000 0010  */
	/* FAST PWM      :  0b0000 0011  */
	/* TCCR0 :  WGM00    BIT 6 */
	/*          WGM01    BIT 3 */
	switch(new_Config->mode){
	case TIMER2_NORMAL_MODE:
		CLEAR_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		/* FOC2 is 1 with non PWM Mode */
		SET_BIT(TCCR2,FOC2);
		/* Select the compare match output mode (OC2) */
		TCCR2 = (TCCR2 & 0xCF) | (new_Config->oc2_nonPwm << COM20);
		break;
	case TIMER2_PWM_PHASE_CORRECT:
		SET_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		/* FOC2 is 1 with non PWM Mode */
		SET_BIT(TCCR2,FOC2);
		/* Select the compare match output mode (OC2) */
		TCCR2 = (TCCR2 & 0xCF) | (new_Config->oc2_phaseCorrectPwm << COM20);
		break;
	case TIMER2_CTC_MODE:
		SET_BIT(TCCR2,WGM21);
		CLEAR_BIT(TCCR2,WGM20);
		/* FOC2 is 0 with PWM Mode */
		SET_BIT(TCCR2,FOC2);
		/* Select the compare match output mode (OC0) */
		TCCR2 = (TCCR2 & 0xCF) | (new_Config->oc2_nonPwm << COM20);
		break;
	case TIMER2_FAST_PWM:
		SET_BIT(TCCR2,WGM21);
		SET_BIT(TCCR2,WGM20);
		/* FOC2 is 0 with PWM Mode */
		CLEAR_BIT(TCCR2,FOC2);
		/* Select the compare match output mode (OC2) */
		TCCR2 = (TCCR2 & 0xCF) | (new_Config->oc2_fastPwm << COM20);
		break;
	}
}



void TIMER2_voidTimer2OVFSetCallBack(void (*local_pf) (void))
{
	if(local_pf != NULL_PTR){
		TIMER2_pfTimer2OVF=local_pf;
	}
	else{
		/* Do No thing*/
	}
}

void TIMER2_voidTimer2CMPSetCallBack(void (*local_pf) (void))
{
	if(local_pf != NULL_PTR){
		TIMER2_pfTimer2CMP=local_pf;
	}
	else{
		/* Do No thing*/
	}

}


/* Interrupt handling Of the Compare Match*/
void __vector_4  (void)          __attribute__ ((signal,used));
void __vector_4  (void)
{

	if(TIMER2_pfTimer2CMP != NULL_PTR){
		TIMER2_pfTimer2CMP();
	}
	else{

	}
}


/* Interrupt handling Of the Overflow*/
void __vector_5  (void)           __attribute__ ((signal,used));
void __vector_5  (void)
{

	if(TIMER2_pfTimer2OVF != NULL_PTR){
		TIMER2_pfTimer2OVF();
	}
	else{

	}
}

