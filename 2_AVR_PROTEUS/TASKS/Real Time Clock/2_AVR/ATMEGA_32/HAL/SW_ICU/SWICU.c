/*******************************************************************************************/
/*  Module       :   SW ICU                                                                */
/*  File Name    :   SWICU.c                                                              */
/*  Description  :   Source File of the Software ICU                                    */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   20/08/2023                                                            */
/*******************************************************************************************/
       /* Include Used Libraries*/
#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
       /* Include the used MCAL Drivers */
#include "..\..\MCAL\External_Interrupt_Driver\EXT_INT.h"
#include "..\..\MCAL\Timer1\Timer1.h"
#include "..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
       /* Include Driver self Files */
#include  "SWICU.h"
#include  "SWICU_Cfg.h"

static uint16 SWICU_u16OnPeriod=0;
static uint16 SWICU_u16OffPeriod=0;
static void SWICU_voidEXTICallBack(void);

void SWICU_voidEnable(void){
	/* Set the call back function of the interrupt */
	EXT_INT_SetCallBack(&SWICU_voidEXTICallBack,EXTERNAL_INT_0_INDEX);

	/* Enable the External Interrupt */
	EXT_INT_Enable(EXTERNAL_INT_0_INDEX,RISING_EDGE);


}

void SWICU_voidDisable(void){
	EXT_INT_Disable(EXTERNAL_INT_0_INDEX);
}

void SWICU_u8GetTotalPeriod(uint32 *Copy_u32TotalPeriod){
	*Copy_u32TotalPeriod=SWICU_u16OffPeriod+SWICU_u16OnPeriod;

}

void SWICU_u8GetDutyCycle(uint8 *Copy_u8DutyCycle){
	*Copy_u8DutyCycle=(uint8)((SWICU_u16OnPeriod*100UL)/(SWICU_u16OnPeriod+SWICU_u16OffPeriod));
}

void SWICU_u8GetOnPeriod(uint8 *Copy_u8OnPeriod){
	*Copy_u8OnPeriod=SWICU_u16OnPeriod;
}

void SWICU_u8GetOffPeriod(uint8 *Copy_u8OffPeriod){
	*Copy_u8OffPeriod=SWICU_u16OffPeriod;
}



static void SWICU_voidEXTICallBack(void){
	uint16 Local_u16TimerValue;
	static uint8 Local_u8Flag=0;
	/* We must save the previous value of the timer counter */
	static uint16 Local_u16ldValue=0;
	/* Read the timer1 Value */
	Local_u16TimerValue=TIMER1_u16ReadTcnt1Reg();

	/* Here, we will measure the off period */
	/* Here, we will change the mode of the interrupt to detect the
	 * falling edge                                                 */
	/* Set the flag to be 1*/
	if(0==Local_u8Flag){
		/* t(off) = New counter Value - Previous Counter Value */
		SWICU_u16OffPeriod=Local_u16TimerValue-Local_u16ldValue;
		/* Change the sense Control into Falling Edge */
		EXT_INT_Enable(EXTERNAL_INT_0_INDEX,FALLING_EDGE);
		/* Change the flag to be 1 */
		Local_u8Flag=1;
	}
	/* Here, */
	else{
		/* t(on) = New counter Value - Previous Counter Value */
		SWICU_u16OnPeriod=Local_u16TimerValue-Local_u16ldValue;
		/* Change the sense Control into rising Edge */
		EXT_INT_Enable(EXTERNAL_INT_0_INDEX,RISING_EDGE);
		/* Change the flag to be 0 */
		Local_u8Flag=0;
	}
	Local_u16ldValue=Local_u16TimerValue;
}
