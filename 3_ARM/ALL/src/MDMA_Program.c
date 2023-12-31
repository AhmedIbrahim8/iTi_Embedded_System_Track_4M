/*******************************************************************************************/
/*  Module       :   DMA                                                                  */
/*  File Name    :   MDMA_Program.c                                                       */
/*  Description  :   Source File of the DMA Driver                                        */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   17/09/2023                                                            */
/*******************************************************************************************/


/*******************************************************************************************/
/*********************************** Included  Files ***************************************/
/*******************************************************************************************/
/* Standard Types File */
#include "..\include\STD_Types.h"
/* Bit Math File */
#include "..\include\BIT_MATH.h"


#include "..\include\MDMA_Private.h"
#include "..\include\MDMA_Interface.h"
#include "..\include\MDMA_Config.h"


static void (*DMA2_S_ptr[8])(void)={0};

/********************************************************************************************/
/************************************** APIs Definition *************************************/
/********************************************************************************************/



void DMA2_Init(void)
{
	/* Enable bit equal zero */
	CLEAR_BIT(DMA2->s[DMA2_STREAM_0_SELECTED].SCR,EN);
	/* Adjust the Interrupt Enable for the stream 0 */
	DMA2->s[DMA2_STREAM_0_SELECTED].SCR = ((DMA2->s[DMA2_STREAM_0_SELECTED].SCR) & DMA2_INTERRUPT_MASK)\
			                              |(DMA2_STREAM_0_TRANSFER_COMPLETE_INTERRUPT << TCIE)\
										  |(DMA2_STREAM_0_HALF_TRANSFER_COMPLETE_INTERRUPT << HTIE)\
										  |(DMA2_STREAM_0_TRANSFER_ERROR_INTERRUPT << TEIE)\
										  |(DMA2_STREAM_0_DIRECT_MODE_ERROR_INTERRUPT << DMEIE);
	/* Adjust: - Peripheral flow controller    */
	/*         - Data transfer direction       */
	/*         - Circular mode                 */
	/*         - Peripheral increment mode     */
	/*         - Memory increment mode         */
	DMA2->s[DMA2_STREAM_0_SELECTED].SCR = ((DMA2->s[DMA2_STREAM_0_SELECTED].SCR &  DMA2_SCR_MASK_2))\
			                              |(DMA2_STREAM_0_PERIPHERAL_FLOW_CONTROLLER << PFCTRL)\
										  |(DMA2_STREAM_0_DATA_TRANSFER_DIRECTION << DIR0)\
										  |(DMA2_STREAM_0_CIRCULAR_MODE << CIRC)\
										  |(DMA2_STREAM_0_PERIPHERAL_INCREMENT_MODE << PINC)\
										  |(DMA2_STREAM_0_MEMORY_INCREMENT_MODE << MINC);
	/* Adjust: - FIFO error interrupt enable */
	/*         - Direct mode disable         */
	/*         - FIFO threshold selection*/
	DMA2->s[DMA2_STREAM_0_SELECTED].SFCR = ((DMA2->s[DMA2_STREAM_0_SELECTED].SFCR & DMA2_FCR_MASK_1))\
			                               |(DMA2_STREAM_0_FIFO_ERROR_INTERRUPT << FEIE)\
										   |(DMA2_STREAM_0_DIRECT_MODE_TYPE << DMDIS)\
										   |(DMA2_STREAM_0_FIFI_THRESHOLD_SELECTION << FTH0);
}

void DMA2_SetStreamConfiguration(DMA2_StreamType  Copy_u8StreamID,
		                          DMA2_ChannelType Copy_u8ChannelID,
								  u32 *Copy_pu32SourceAddress,
								  u32 *Copy_pu32DestinationAddress,
							      u8 Copy_u8ElementSize,
								  u16 Copy_u16BlockSize)
{
	DMA2->s[Copy_u8StreamID].SCR = ((DMA2->s[Copy_u8StreamID].SCR & 0x000007FE))\
			                       |(DMA2_STREAM_0_PERIPHERAL_DATA_SIZE << PSIZE0)\
								   |(DMA2_STREAM_0_MEMORY_DATA_SIZE << MSIZE0)\
								   |(DMA2_STREAM_0_PERIPHERAL_INCREMENT_OFFSET_SIZE << PINCOS)\
								   |(DMA2_STREAM_0_PRIORITY_LEVEL << PL0)\
								   |(DMA2_STREAM_0_DOUBLE_BUFFER_MODE << DBM)\
								   |(DMA2_STREAM_0_CURRENT_TARGET << CT)\
								   |(DMA2_STREAM_0_PERIPHERAL_BURST_TRANSFER_CONFIGURATION << PBURST0)\
								   |(DMA2_STREAM_0_MEMORY_BURST_TRANSFER_CONFIGURATION << MBURST0)\
								   |(Copy_u8ChannelID << CHSEL0);

	DMA2->s[Copy_u8StreamID].SNDTR = Copy_u16BlockSize;
#if (DMA2_STREAM_0_DATA_TRANSFER_DIRECTION == DMA2_MEMORY_TO_MEMORY)
	DMA2->s[Copy_u8StreamID].SPAR  = Copy_pu32SourceAddress;
	DMA2->s[Copy_u8StreamID].SM0AR = Copy_pu32DestinationAddress;
#elif (DMA2_STREAM_0_DATA_TRANSFER_DIRECTION == DMA2_PERIPHERAL_TO_MEMORY)
	DMA2->s[Copy_u8StreamID].SPAR  = Copy_pu32SourceAddress;
	DMA2->s[Copy_u8StreamID].SM0AR = Copy_pu32DestinationAddress;
#elif (DMA2_STREAM_0_DATA_TRANSFER_DIRECTION == DMA2_MEMORY_TO_PERIPHERAL)
	DMA2->s[Copy_u8StreamID].SPAR  = Copy_pu32DestinationAddress;
	DMA2->s[Copy_u8StreamID].SM0AR = Copy_pu32SourceAddress;
#endif

}

void DMA2_SetCallBack(DMA2_StreamType Copy_u8StreamID,void (*ptr)(void))
{
	if(ptr != 	NULL_PTR){
		DMA2_S_ptr[Copy_u8StreamID]=ptr;
	}
}

void DMA2_EnbaleStream(DMA2_StreamType Copy_u8StreamID)
{
	switch(Copy_u8StreamID)
	{
	case DMA2_STREAM_0_SELECTED:
		/* Clear the flags of the first stream */
		DMA2->LIFCR = CLEAR_STREAM_0_FLAG;
		break;
	case DMA2_STREAM_1_SELECTED:
		DMA2->LIFCR = CLEAR_STREAM_1_FLAG;
		break;
	case DMA2_STREAM_2_SELECTED:
		DMA2->LIFCR = CLEAR_STREAM_0_FLAG;
		break;
	case DMA2_STREAM_3_SELECTED:
		DMA2->LIFCR = CLEAR_STREAM_1_FLAG;
		break;
	case DMA2_STREAM_4_SELECTED:
		DMA2->LIFCR = CLEAR_STREAM_0_FLAG;
		break;
	case DMA2_STREAM_5_SELECTED:
		DMA2->LIFCR = CLEAR_STREAM_1_FLAG;
		break;
	case DMA2_STREAM_6_SELECTED:
		DMA2->LIFCR = CLEAR_STREAM_0_FLAG;
		break;
	case DMA2_STREAM_7_SELECTED:
		DMA2->LIFCR = CLEAR_STREAM_1_FLAG;
		break;
	}

	SET_BIT(DMA2->s[Copy_u8StreamID].SCR,EN);
}

void DMA2_Stream0_IRQHandler(void)
{
	if(DMA2_S_ptr[DMA2_STREAM_0_SELECTED] != NULL_PTR)
	{
		DMA2_S_ptr[DMA2_STREAM_0_SELECTED]();
		DMA2->LIFCR = CLEAR_STREAM_0_FLAG;

	}
	else
	{

	}
}


void DMA2_Stream1_IRQHandler(void)
{
	if(DMA2_S_ptr[DMA2_STREAM_1_SELECTED] != NULL_PTR)
	{
		DMA2_S_ptr[DMA2_STREAM_1_SELECTED]();
	}
	else
	{

	}
}



void DMA2_Stream2_IRQHandler(void)
{
	if(DMA2_S_ptr[DMA2_STREAM_2_SELECTED] != NULL_PTR)
	{
		DMA2_S_ptr[DMA2_STREAM_2_SELECTED]();
	}
	else
	{

	}
}




void DMA2_Stream3_IRQHandler(void)
{
	if(DMA2_S_ptr[DMA2_STREAM_3_SELECTED] != NULL_PTR)
	{
		DMA2_S_ptr[DMA2_STREAM_3_SELECTED]();
	}
	else
	{

	}
}




void DMA2_Stream4_IRQHandler(void)
{
	if(DMA2_S_ptr[DMA2_STREAM_4_SELECTED] != NULL_PTR)
	{
		DMA2_S_ptr[DMA2_STREAM_4_SELECTED]();
	}
	else
	{

	}
}

void DMA2_Stream5_IRQHandler(void)
{
	if(DMA2_S_ptr[DMA2_STREAM_5_SELECTED] != NULL_PTR)
	{
		DMA2_S_ptr[DMA2_STREAM_5_SELECTED]();
	}
	else
	{

	}
}

void DMA2_Stream6_IRQHandler(void)
{
	if(DMA2_S_ptr[DMA2_STREAM_6_SELECTED] != NULL_PTR)
	{
		DMA2_S_ptr[DMA2_STREAM_6_SELECTED]();
	}
	else
	{

	}
}
void DMA2_Stream7_IRQHandler(void)
{
	if(DMA2_S_ptr[DMA2_STREAM_7_SELECTED] != NULL_PTR)
	{
		DMA2_S_ptr[DMA2_STREAM_7_SELECTED]();
	}
	else
	{

	}
}
