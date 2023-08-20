/*******************************************************************************************/
/*  Module       :   TIMER0                                                                */
/*  File Name    :   Timer0.c                                                              */
/*  Description  :   Source File of the Timer0                                             */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   18/08/2023                                                            */
/*******************************************************************************************/
#include "..\DIO_DRIVER\Dio_Interface.h"
#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "Timer0.h"
#include "Timer0_Registers.h"
/* Global Pointer to function for the overflow mode */
static void (*TIMER0_pfTimer0OVF) (void)=NULL_PTR;
/* Global Pointer to function for the Compare match mode */
static void (*TIMER0_pfTimer0CMP) (void)=NULL_PTR;

/* This function responsible for choose the mode and oc0 selection type */
void TIMER0_voidTimer0_Init(void){
	/* Select the mode of the Timer0 */
	/* Normal mode   :  0b0000 0000  */
	/* PHASE_CORRECT :  0b0000 0001  */
	/* CTC MODE      :  0b0000 0010  */
	/* FAST PWM      :  0b0000 0011  */
	/* TCCR0 :  WGM00    BIT 6 */
	/*          WGM01    BIT 3 */
	switch(Timer0_configuration.mode){
	case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		/* FOC0 is 1 with non PWM Mode */
		SET_BIT(TCCR0,FOC0);
		/* Select the compare match output mode (OC0) */
		TCCR0 = (TCCR0 & 0xCF) | (Timer0_configuration.oc0_nonPwm << COM00);
		break;
	case TIMER0_PWM_PHASE_CORRECT:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		/* FOC0 is 1 with non PWM Mode */
		CLEAR_BIT(TCCR0,FOC0);
		/* Select the compare match output mode (OC0) */
		TCCR0 = (TCCR0 & 0xCF) | (Timer0_configuration.oc0_phaseCorrectPwm << COM00);
		break;
	case TIMER0_CTC_MODE:
		SET_BIT(TCCR0,WGM01);
		CLEAR_BIT(TCCR0,WGM00);
		/* FOC0 is 0 with PWM Mode */
		SET_BIT(TCCR0,FOC0);
		/* Select the compare match output mode (OC0) */
		TCCR0 = (TCCR0 & 0xCF) | (Timer0_configuration.oc0_nonPwm << COM00);
		break;
	case TIMER0_FAST_PWM:
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
		/* FOC0 is 0 with PWM Mode */
		CLEAR_BIT(TCCR0,FOC0);
		/* Select the compare match output mode (OC0) */
		TCCR0 = (TCCR0 & 0xCF) | (Timer0_configuration.oc0_fastPwm << COM00);
		break;
		/* Wrong mode */
	}

}

/* Function Responsible for Adjusting the Pre-scaler to start the timer */
void TIMER0_voidEnable(Timer0_PrescalerType PreScaler){
	if(PreScaler < TIMER0_EXT_CLK_RISING_EDGE){
		/* 0xF8  => To mask the first 3 bits to be zero then or-ing with the pre-scaler*/
		TCCR0 =(TCCR0 & 0xF8) | (PreScaler & 0x07);
	}
	else
	{
		/* Out of range */
	}
}

/* Function Responsible for disable the Pre-scaler to stop the timer */
void TIMER0_voidDisable(){
	/* Zeros for the first 3-bits */
	TCCR0 = TCCR0 & 0xF8;
}

/* Function to set the pre-load value of the TCNT0 */
void TIMER0_voidSetTCNTValue(uint8 u8TcntReg)
{
	TCNT0 = u8TcntReg;
}

/* Function to return the TCNT0 value */
uint8 TIMER0_u8ReadTcntReg()
{
	return TCNT0 ;
}

/* Function to set the OCR0 value */
void TIMER0_voidSetOCRValue(uint8 Copy_u8OCRValue){
	OCR0=Copy_u8OCRValue;
}


/* Function to enable the overflow interrupt */
void TIMER0_voidEnableOvfINT(){
	SET_BIT(TIMSK,TOIE0);
}
/* Function to disable the overflow interrupt */
void TIMER0_voidDisableOvfINT(){
	CLEAR_BIT(TIMSK,TOIE0);
}
/* Function to enable the compare match interrupt */
void TIMER0_voidEnableComparINT(){
	SET_BIT(TIMSK,OCIE0);
}
/* Function to disable the compare match interrupt */
void TIMER0_voidDisableCompareINT(){
	CLEAR_BIT(TIMSK,OCIE0);
}

/* Function to change the mode */
void TIM0_voidChangMode(Timer0_ConfigType *new_Config)
{
	/* New mode so, we will make TCCR0 equal 0 */
	TCCR0=0;
	/* Select the mode of the Timer0 */
	/* Normal mode   :  0b0000 0000  */
	/* PHASE_CORRECT :  0b0000 0001  */
	/* CTC MODE      :  0b0000 0010  */
	/* FAST PWM      :  0b0000 0011  */
	/* TCCR0 :  WGM00    BIT 6 */
	/*          WGM01    BIT 3 */
	switch(new_Config->mode){
	case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		/* FOC0 is 1 with non PWM Mode */
		SET_BIT(TCCR0,FOC0);
		/* Select the compare match output mode (OC0) */
		TCCR0 = (TCCR0 & 0xCF) | (new_Config->oc0_nonPwm << COM00);
		break;
	case TIMER0_PWM_PHASE_CORRECT:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		/* FOC0 is 1 with non PWM Mode */
		SET_BIT(TCCR0,FOC0);
		/* Select the compare match output mode (OC0) */
		TCCR0 = (TCCR0 & 0xCF) | (new_Config->oc0_phaseCorrectPwm << COM00);
		break;
	case TIMER0_CTC_MODE:
		SET_BIT(TCCR0,WGM01);
		CLEAR_BIT(TCCR0,WGM00);
		/* FOC0 is 0 with PWM Mode */
		SET_BIT(TCCR0,FOC0);
		/* Select the compare match output mode (OC0) */
		TCCR0 = (TCCR0 & 0xCF) | (new_Config->oc0_nonPwm << COM00);
		break;
	case TIMER0_FAST_PWM:
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
		/* FOC0 is 0 with PWM Mode */
		CLEAR_BIT(TCCR0,FOC0);
		/* Select the compare match output mode (OC0) */
		TCCR0 = (TCCR0 & 0xCF) | (new_Config->oc0_fastPwm << COM00);
		break;
	}
}



void TIMER0_voidTimer0OVFSetCallBack(void (*local_pf) (void))
{
	if(local_pf != NULL_PTR){
		TIMER0_pfTimer0OVF=local_pf;
	}
	else{
		/* Do No thing*/
	}
}

void TIMER0_voidTimer0CMPSetCallBack(void (*local_pf) (void))
{
	if(local_pf != NULL_PTR){
		TIMER0_pfTimer0CMP=local_pf;
	}
	else{
		/* Do No thing*/
	}

}


/* Interrupt handling Of the Compare Match*/
void __vector_10  (void)          __attribute__ ((signal,used));
void __vector_10  (void)
{

	if(TIMER0_pfTimer0CMP != NULL_PTR){
		TIMER0_pfTimer0CMP();
	}
	else{

	}
}


/* Interrupt handling Of the Overflow*/
void __vector_11  (void)           __attribute__ ((signal,used));
void __vector_11  (void)
{

	if(TIMER0_pfTimer0OVF != NULL_PTR){
		TIMER0_pfTimer0OVF();
	}
	else{

	}
}




//
///* To run the servo motor */
//void TIMER1_voidTimer1Init(void){
//	/* Timer 1 select mode 14 => ICR1 top value */
//	SET_BIT(TCCR1A,1);
//	CLEAR_BIT(TCCR1A,0);
//	SET_BIT(TCCR1B,4);
//	CLEAR_BIT(TCCR1B,3);
//	/* Channel A with Non Inverting */
//	SET_BIT(TCCR1A,7);
//	CLEAR_BIT(TCCR1A,6);
//	/* Set the maximum value  */
//	ICR1=19999;
//	/* Set the pre-scaler to be 8 */
//	CLEAR_BIT(TCCR1B,2);
//	SET_BIT(TCCR1B,1);
//	CLEAR_BIT(TCCR1B,0);
//
//}
//
//void TIMER1_voidTimer1SetCompareMatchValueChannelA(uint16 Copy_u16OCR1AValue){
//	OCR1A=Copy_u16OCR1AValue;
//}
