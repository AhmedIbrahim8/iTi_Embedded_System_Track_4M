/*******************************************************************************************/
/*  Module       :   USART                                                                 */
/*  File Name    :   MUSART_Program.c                                                      */
/*  Description  :   Source File of the USART Driver                                       */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   19/09/2023                                                            */
/*******************************************************************************************/

/*************************************************************************************/
/****************************** Included Libraries ***********************************/
/*************************************************************************************/
#include "..\include\STD_Types.h"
#include "..\include\BIT_MATH.h"

/*************************************************************************************/
/******************************** Included Drivers ***********************************/
/*************************************************************************************/
#include "..\include\MUSART_Interface.h"
#include "..\include\MUSART_Private.h"
#include "..\include\MUSART_Config.h"



/*************************************************************************************/
/******************************** Gloabl Variables ***********************************/
/*************************************************************************************/
static void (*global_ptr) (void)=NULL_PTR;







/********************************************************************************************/
/************************************** APIs Definitions ************************************/
/********************************************************************************************/
void MUSART_voidInit(void)
{
	/* Adjust the mantissa and the fraction based on the configuration */
	USART1->BRR = ( USART_MANTISSA << DIV_MANTISSA0 )|(USART_FRACTION << DIV_FRACTION0);
	/* Adjust the Sample based on the configuration  */
	/* UART can sample 16 or 8                       */
	USART1->CR1.OVER8=USART_OVERSAMPLE;

	/* Adjust the data bit based on the configuration */
	/* Uart can transmit 8 or 9 data bits */
	USART1->CR1.M=USART_DATA_BITS;

	/* Adjust the Parity control selection   */
	/* -Enable or Disable                    */
	USART1->CR1.PCE=USART_PARITY_CONTROL;
/* Adjust the parity selection (even or odd) incase user enable */
/* the parity control                                           */
#if(USART_PARITY_CONTROL == USART_PARITY_CONTROL_ENABLE)
	USART1->CR1.PS = USART_PARITY_SELECTION ;
#endif

	/* Adjust the stop bit */
	USART1->CR2 = (USART1->CR2 & USART_STOP_BIT_MASK) | (USART_STOP_BIT << STOP0);

	/* Adjust the transmitter and receiver (Enable or Disable) */
	USART1->CR1.TE=USART_RECEIVER;
	USART1->CR1.RE=USART_RECEIVER ;

	/* Adjust Receive interrupt enable     */
	USART1->CR1.RXNEIE=USART_RX_INTERRUPT;
}



void MUSART_voidTransmit(u8* Copy_u8Data,u8 Copy_u8Length)
{
	/* Variable for the counting */
	u8 Copy_u8Counter;
	/* Looping till reach the end of the data */
	for(Copy_u8Counter=USART_NUMBER_0;Copy_u8Counter<Copy_u8Length;Copy_u8Length++)
	{
		/* Put the data in the USART DATA Register */
		USART1->DR = Copy_u8Data[Copy_u8Counter];
		/* Wait till the flag equal 1 */
		while(GET_BIT(USART1->SR,TXE)==USART_NUMBER_0);
	}
}

u8 MUSART_u8Receive()
{
	/* Wait till the receive flag is equal 1 */
	while(GET_BIT(USART1->SR,RXNE)==USART_NUMBER_0);
	/* Return the data received from the data register of the usart */
	return (u8)(USART1->DR);
}


/* Function Responsible for Enabling the UART Peripheral */
void MUSART_voidEnable()
{
	USART1->CR1.UE=USART_ENABLE_PERIPHERAL;
}

/* Function Responsible for disabling the UART Peripheral */
void MUSART_voidDisable()
{
	USART1->CR1.UE=USART_DISABLE_PERIPHERAL;
}


/* In case you use the USART with the interrupt method, This Function */
/* will the set the function that will be called after the interrupt  */
void MUSART_voidSetCallBack(void (*ptr) (void))
{
	if(ptr!=NULL_PTR)
	{
		global_ptr = ptr;
	}
	else
	{
		/* Do No thing */
	}
}

/* ISR of the UART Driver */
void USART1_IRQHandler(void)
{
	(*global_ptr)();
}
