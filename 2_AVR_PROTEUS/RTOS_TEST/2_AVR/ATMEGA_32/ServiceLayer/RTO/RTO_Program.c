/*******************************************************************************************/
/*  Module       :   RTO                                                                   */
/*  File Name    :   RTO_Program.h                                                       */
/*  Description  :   Source File of the RTO Driver                                           */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   30/08/2023                                                            */
/*******************************************************************************************/


#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"



#include "..\..\MCAL\Timer1\Timer1.h"
#include "..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"


#include "RTO_Interface.h"
#include "RTO_Private.h"
#include "RTO_Cfg.h"


/* Create the Array Of TCBs */

static TCB RTO_AstrTasks [RTO_MAXIMUM_NUMER_OF_TASKS];




/*********************************************************************/
/* This Function responsible for allocating TCB for the task         */
/* Function Parameter [in] :          TCB Parameters                 */
/*                         1- Priority                               */
/*                         2- Periodicity                            */
/*                         3- First Delay                            */
/*                         4- Pointer to the function                */
/* Function Return [out]   :                                         */
/*                          Error State                              */
/*********************************************************************/
uint8 RTO_u8CreateTask(uint8 Copy_u8Priority,
		               uint16 Copy_u16Periodicity,
					   uint16 Copy_u16FirstDelay,
					   void (*Copy_Pf)(void)
					   )
{
	uint8 Local_u8ErrorState = E_OK;
	if( ( Copy_u8Priority < RTO_MAXIMUM_NUMER_OF_TASKS ) && ( Copy_Pf != NULL_PTR ) )
	{
		/* Priority : the number of element inside the structure */
		RTO_AstrTasks[Copy_u8Priority].FirstDelay  = Copy_u16FirstDelay ;
		RTO_AstrTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity ;
		RTO_AstrTasks[Copy_u8Priority].Pf          = Copy_Pf;
	}
	else
	{
		Local_u8ErrorState = E_NOT_OK;
	}
	return Local_u8ErrorState;
}

/*********************************************************************/
/* Function has the implementation of the scheduler                  */
/* Scheduler + Dispatcher                                            */
/* This function is called every timer tick to schedule the task and */
/* tells the processor which task will be implemented                */
/*********************************************************************/
static void RTO_voidScheduler(void)
{
	/* Local Variable : to move through the array of structure */
	uint8 Local_u8Priority;
	/* Static : indicating the timer tick counter */
	static uint16 counter = 0;
	/* Increase the counter every timer tick */
	counter++;

	for(Local_u8Priority=0;Local_u8Priority < RTO_MAXIMUM_NUMER_OF_TASKS ;Local_u8Priority++){
		if(RTO_AstrTasks[Local_u8Priority].FirstDelay == 0){
			RTO_AstrTasks[Local_u8Priority].Pf();
			RTO_AstrTasks[Local_u8Priority].FirstDelay = RTO_AstrTasks[Local_u8Priority].Periodicity - 1 ;
		}
		else{
			RTO_AstrTasks[Local_u8Priority].FirstDelay--;
		}

//
//		if(counter % ( RTO_AstrTasks[Local_u8Priority].FirstDelay + RTO_AstrTasks[Local_u8Priority].Periodicity )==0){
//			RTO_AstrTasks[Local_u8Priority].Pf();
//		}
	}


}


/*********************************************************************/
/* Function Responsible for start the RTO                            */
/*********************************************************************/
void RTO_voidInit(void){
	/* Enable the global Interrupt */
	GI_voidEnable();
	/* Set call back of the TIMER 1 */
	TIMER1_voidTimer1CMPASetCallBack(RTO_voidScheduler);
	/* Initialize Timer1 mode */
	TIMER1_voidTimer1_Init();
	/* Enable the interrupt of compare A*/
	TIMER1_voidEnableCompareAINT();
	/* Set the counter timer to 0 */
	TIMER1_voidSetTCNT1Value(0);
	/* Set the compare value of COMP A */
	TIMER1_voidSetOCR1AValue(7812);
	/* Start the timer */
	TIMER1_voidEnable(TIMER1_CLK_1024);

}
