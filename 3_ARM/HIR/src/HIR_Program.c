/*******************************************************************************************/
/*  Module       :   Infrared                                                              */
/*  File Name    :   HIR_Program.c                                                         */
/*  Description  :   Source File of the HIR Driver                                         */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   18/09/2023                                                            */
/*******************************************************************************************/

#include "..\include\STD_Types.h"
#include "..\include\BIT_MATH.h"

#include "..\include\MRCC_Interface.h"
#include "..\include\MEXTI_Interface.h"
#include "..\include\MNVIC_Interface.h"
#include "..\include\MSYSTICK_Interface.h"
#include "..\include\MGPIO_Interface.h"

#include "..\include\HIR_Interface.h"
#include "..\include\HIR_Private.h"
#include "..\include\HIR_Config.h"


/********************************************************************************************/
/************************************** Global Variables ************************************/
/********************************************************************************************/
/* Variable to indicate the start of the IR Protocol */
volatile u8 flag=HIR_NUMBER_0;

/* Variable as a counter to count through the array  */
volatile u8 counter=HIR_NUMBER_0;
/* Protocol Time Frame */
static volatile u32 ProtocolFrame[50]={HIR_NUMBER_0};
/* Variable for the data received */
volatile u8 data;






/********************************************************************************************/
/************************************** APIs Definition *************************************/
/********************************************************************************************/
/* This Function will be called when the external interrupt happened */
void GetFrame(void)
{
	/* If it is the start of the protocol */
	if(flag == HIR_NUMBER_0)
	{
		SYSTICK_voidCtrlIntState(1);
		/* Start the timer to get the time between each bit in the frame */
		SYSTICK_voidStart(SYSTICK_TIME_START);
		/* Start of the protocol is happened so, flag value will be changed */
		flag=HIR_NUMBER_1;
	}
	/* In case it is not the start of the frame  */
	else
	{
		/* Get the time value and put it into the protocol variable at specific counter value */
		ProtocolFrame[counter]=SYSTICK_u32GetElapsedTime();
		/* Start the systick again to get the time between the next bit in the frame */
		SYSTICK_voidStart(SYSTICK_TIME_START);
		/* Increment the counter to the next location in the protocol array variable */
		counter++;
	}
}


/* This Function will be called when the systick interrupt happened */
/* indicating the end of the protocol frame  */
void GetData(void)
{
	/* i is a counter */
	u8 i;
	/* Zero to the flag for the next start of the frame */
	flag=HIR_NUMBER_0;
	/* Zero to the counter to the next start of the frame */
	counter=HIR_NUMBER_0;
	/* Here, we interested in the data bit of the frame which starts at*/
	for(i=HIR_NUMBER_0;i<HIR_NUMBER_8;i++)
	{
		/* In case of the zero bit */
		if((ProtocolFrame[HIR_NUMBER_24-i]>=HIR_START_TIME_OF_LOGIC_0) && (ProtocolFrame[HIR_NUMBER_24-i]<=HIR_END_TIME_OF_LOGIC_0))
		{
			CLEAR_BIT(data,i);
		}
		/* Incase of the one bit */
		else if((ProtocolFrame[HIR_NUMBER_24-i]>=HIR_START_TIME_OF_LOGIC_1) && (ProtocolFrame[HIR_NUMBER_24-i]<=HIR_END_TIME_OF_LOGIC_1))
		{
			SET_BIT(data,i);
		}
	}
	/* Disable the SYSTICK Timer */
	SYSTICK_voidCtrlIntState(0);
	SYSTICK_voidDisableCounter();
}
