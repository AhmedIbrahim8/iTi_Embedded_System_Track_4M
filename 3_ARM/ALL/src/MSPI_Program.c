/*******************************************************************************************/
/*  Module       :   MSPI                                                                  */
/*  File Name    :   MSPI_Program.c                                                        */
/*  Description  :   Source File of the SPI Driver                                         */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   20/09/2023                                                            */
/*******************************************************************************************/

/*************************************************************************************/
/****************************** Included Libraries ***********************************/
/*************************************************************************************/
#include "..\include\STD_Types.h"
#include "..\include\BIT_MATH.h"

/*************************************************************************************/
/******************************** Included Drivers ***********************************/
/*************************************************************************************/
#include "..\include\MSPI_Interface.h"
#include "..\include\MSPI_Private.h"
#include "..\include\MSPI_Config.h"

#include "..\include\MGPIO_Interface.h"
/*************************************************************************************/
/******************************** Gloabl Variables ***********************************/
/*************************************************************************************/
void (*MSPI1_CallBack) (void);





/********************************************************************************************/
/************************************** APIs Definitions ************************************/
/********************************************************************************************/
void MSPI1_voidInit        (void)
{
	/* Adjust the configuration in the CR1 Register */
	SPI1->CR1 = (SPI1_BIDIRECTIONAL_DATA_MODE     << BIDIMODE )\
			   |(SPI1_OUTPUT_BIDIRECTIONAL_MODE   << BIDIOE   )\
			   |(SPI1_HW_CRC_CALCULATION          << CRCEN    )\
			   |(SPI1_CRC_TRANSFER                << CRCNEXT  )\
			   |(SPI1_DATA_FRAME_FORMAT           << DFF      )\
			   |(SPI1_RECEIVE_ONLY_ENABLE_DISABLE << RXONLY   )\
			   |(SPI1_SW_SLAVE_MANAGEMENT         << SSM      )\
			   |(1                                << SSI      )\
			   |(SPI1_FRAME_FORMAT                << LSBFIRST )\
			   |(SPI1_PERIPHERAL_STATE            << SPE      )\
			   |(SPI1_BAUD_RATE                   << BR0      )\
			   |(SPI1_MASTER_SELECTION            << MSTR     )\
			   |(SPI1_CLOCK_POLARITY              << CPOL     )\
			   |(SPI1_CLOCK_PHASE                 << CPHA);
	/* Adjust the interrupt enable or disable */
	SPI1->CR2 = (SPI1->CR2 & INTERRUPT_MASK)\
			  | (SPI1_TX_BUFFER_EMPTY_INTERRUPT     << TXEIE  )\
			  | (SPI1_RX_BUFFER_NOT_EMPTY_INTERRUPT << RXNEIE );
}

u8   MSPI1_u8SendDataU8    (u8 Copy_u8Data)
{
	/* Select the chip    ( select the slave ) */
	MGPIO_SetPinValue(MSPI_NSS_PORT_INDEX,MSPI_NSS_PIN_INDEX,PIN_LEVEL_LOW);

	/* Send the data                           */
	SPI1->DR = Copy_u8Data;

	/* Wait till Busy Flag equal zero          */
	while((GET_BIT(SPI1->SR,BSY))==1);

	/* Un-select the chip (un-select the slave )*/
	MGPIO_SetPinValue(MSPI_NSS_PORT_INDEX,MSPI_NSS_PIN_INDEX,PIN_LEVEL_HIGH);


	return (u8)(SPI1->DR);
}



void MSPI1_voidSetCallBack( void (*ptr) (void) )
{
	if(ptr != NULL_PTR)
	{
		MSPI1_CallBack = ptr;
	}
	else
	{
		/* Do Nothing */
	}
}




void SPI1_IRQHandler(void)
{
	if(MSPI1_CallBack == NULL_PTR)
	{
		MSPI1_CallBack();
	}
	else
	{
		/* Do No thing */
	}
}


