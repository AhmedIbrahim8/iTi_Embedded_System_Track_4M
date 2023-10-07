/*******************************************************************************************/
/*  Module       :   Systick Timer                                                         */
/*  File Name    :   MSYSTICK_Program.c                                                    */
/*  Description  :   Source File of the Systick Timer Driver                               */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   12/09/2023                                                            */
/*******************************************************************************************/


/*******************************************************************************************/
/*********************************** Included  Files ***************************************/
/*******************************************************************************************/
/* Standard Type File */
#include "..\include\STD_Types.h"
/* Bit Math File */
#include "..\include\BIT_MATH.h"


#include "..\include\MSYSTICK_Interface.h"
#include "..\include\MSYSTICK_Private.h"
#include "..\include\MSYSTICK_Config.h"



/********************************************************************************************/
/************************************** Global Variables ************************************/
/********************************************************************************************/



/********************************************************************************************/
/************************************** APIs Definition *************************************/
/********************************************************************************************/

void SYSTICK_voidInit(void)
{
	/* Adjust the clock of the Systick timer */
	/* Bit 2 CLKSOURCE: Clock source selection
        Selects the clock source.
            0: AHB/8
            1: Processor clock (AHB)
     */
	/* SYSTICK_CLOCK_SOURCE_TYPE is #define inside the configuration.h */
	SYSTICK->STK_CTRL = ( SYSTICK->STK_CTRL & SYSTICK_CLOCK_SOURCE_MASK ) |\
			            ( SYSTICK_CLOCK_SOURCE_TYPE << SYSTICK_CLKSOURCE_BIT);

}

void SYSTICK_voidCtrlIntState(u8 Copy_u8State)
{
	/* Adjust the exception Request of the Systick Timer                                    */
	/* TICKINT: SysTick exception request enable                                            */
    /*       0: Counting down to zero does not assert the SysTick exception request         */
    /*       1: Counting down to zero to asserts the SysTick exception request.             */
    /*   Note: Software can use COUNTFLAG to determine if SysTick has ever counted to zero. */
	/* Copy_u8State either 0 or 1 */
	SYSTICK->STK_CTRL = (SYSTICK->STK_CTRL & SYSTICK_TICK_INT_MASK) | (Copy_u8State<<SYSTICK_TICKINT_BIT);
}

void SYSTICK_voidStart(u32 Copy_u32LoadValue)
{

	/* Adjust the reload register before clearing the value register */
	SYSTICK->STK_LOAD = Copy_u32LoadValue & SYSTICK_LOAD_REGISTER_MASK;
	SYSTICK->STK_VAL  = 0;
	/* Enable the Systick Timer                                                                       */
	/* Enables the counter. When ENABLE is set to 1, the counter loads the RELOAD value from the      */
    /* LOAD register and then counts down. On reaching 0, it sets the COUNTFLAG to 1 and              */
    /* optionally asserts the SysTick depending on the value of TICKINT. It then loads the RELOAD     */
    /* value again, and begins counting.                                                              */
    /*       0: Counter disabled                                                                      */
    /*       1: Counter enabled                                                                       */
	SET_BIT(SYSTICK->STK_CTRL,SYSTICK_ENABLE_BIT);
}

u8 SYSTICK_u8ReadFlag(void)
{
	/* Returns 1 if timer counted to 0 since last time this was read */
	return (GET_BIT(SYSTICK->STK_LOAD,SYSTICK_COUNTFLAG_BIT));
}



/* Time(usec) ---------> Load value / F_timer(MHz)        */
/* Time(msec) ---------> Load Value / F_timer(KHz)        */

/* So, Load Value = Delay_time(usec) * F_timer(MHz)       */
/* So, Load Value = Delay_time(msec) * F_timer(MHz)*1000  */

void SYSTICK_voidDelayUs(u32 Copy_u32DelayValue)
{
	u32 Copy_u32LoadValue;
#if(SYSTICK_CLOCK_SOURCE_TYPE == SYSTICK_PROCESSOR_CLOCK_AHB)
	Copy_u32LoadValue = Copy_u32DelayValue*16UL;
	SYSTICK_voidStart(Copy_u32LoadValue);
#elif (SYSTICK_CLOCK_SOURCE_TYPE == SYSTICK_PROCESSOR_CLOCK_AHB_8)
	Copy_u32LoadValue = Copy_u32DelayValue*2UL;
	SYSTICK_voidStart(Copy_u32LoadValue);
#endif
	/* Wait till the flag is 1       */
	/* The flag will be zero if read */
	while((GET_BIT(SYSTICK->STK_CTRL,SYSTICK_COUNTFLAG_BIT))==0);
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL=0;

}

void SYSTICK_voidDelayMs(u32 Copy_u32DelayValue)
{
	u32 Copy_u32LoadValue;
#if(SYSTICK_CLOCK_SOURCE_TYPE == SYSTICK_PROCESSOR_CLOCK_AHB)
	Copy_u32LoadValue = Copy_u32DelayValue*16000UL;
	SYSTICK_voidStart(Copy_u32LoadValue);
#elif (SYSTICK_CLOCK_SOURCE_TYPE == SYSTICK_PROCESSOR_CLOCK_AHB_8)
	Copy_u32LoadValue = Copy_u32DelayValue*2000UL;
	SYSTICK_voidStart(Copy_u32LoadValue);
#endif
	while((GET_BIT(SYSTICK->STK_CTRL,SYSTICK_COUNTFLAG_BIT))==0);
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL=0;
}



u32 SYSTICK_u32GetElapsedTime(void)
{
	return SYSTICK->STK_LOAD-SYSTICK->STK_VAL;
}

u32 SYSTICK_u32GetRemainingTime(void)
{
	return SYSTICK->STK_VAL;
}





