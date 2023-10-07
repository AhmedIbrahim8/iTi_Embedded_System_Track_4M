/*******************************************************************************************/
/*  Module       :   DMA                                                                   */
/*  File Name    :   MDMA_Interface.h                                                      */
/*  Description  :   Header File of the DMA Interface Driver                               */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   17/09/2023                                                            */
/*******************************************************************************************/

#ifndef MDMA_INTERFACE_H_
#define MDMA_INTERFACE_H_


/********************************************************************************************/
/************************************** Mask and #s Used ************************************/
/********************************************************************************************/
#define     DMA2_INTERRUPT_MASK                       0xFFFFFFE0

#define     DMA2_SCR_MASK_2                           0xFFFFF81F

#define     DMA2_FCR_MASK_1                           0xFFFFFF78

#define     CLEAR_STREAM_0_FLAG                       0x0000003D

#define     CLEAR_STREAM_1_FLAG                       0x00000F40


/********************************************************************************************/
/************************************** Typedef Used ****************************************/
/********************************************************************************************/
typedef enum{
	DMA2_CHANNEL_0_SELECTED,
	DMA2_CHANNEL_1_SELECTED,
	DMA2_CHANNEL_2_SELECTED,
	DMA2_CHANNEL_3_SELECTED,
	DMA2_CHANNEL_4_SELECTED,
	DMA2_CHANNEL_5_SELECTED,
	DMA2_CHANNEL_6_SELECTED,
	DMA2_CHANNEL_7_SELECTED
}DMA2_ChannelType;

typedef enum{
	DMA2_STREAM_0_SELECTED,
	DMA2_STREAM_1_SELECTED,
	DMA2_STREAM_2_SELECTED,
	DMA2_STREAM_3_SELECTED,
	DMA2_STREAM_4_SELECTED,
	DMA2_STREAM_5_SELECTED,
	DMA2_STREAM_6_SELECTED,
	DMA2_STREAM_7_SELECTED
}DMA2_StreamType;

typedef enum{
	DMA2_MEMORY_SINGLE_TRANSFER,
	DMA2_MEMORY_INCR4_BURST,
	DMA2_MEMORY_INCR8_BURST,
	DMA2_MEMORY_INCR16_BURST
}DMA2_MemoryBurstTransferType;


typedef enum{
	DMA2_PERIPHERAL_SINGLE_TRANSFER,
	DMA2_PERIPHERAL_INCR4_BURST,
	DMA2_PERIPHERAL_INCR8_BURST,
	DMA2_PERIPHERAL_INCR16_BURST
}DMA2_PeripheralBurstTransferType;
/* This bit can be written only if EN is ‘0’ to indicate the
 * target memory area of the first transfer. Once the stream
 * is enabled, this bit operates as a status flag indicating
 * which memory area is the current target. */
typedef enum{
	DMA2_MEMORY_M0AR,
	DMA2_MEMORY_M1AR
}DMA2_CurrentTargetType;

typedef enum{
	DMA2_NO_BUFFER_SWITCHING,
	DMA2_MEMORY_TARGET_SWITCHED
}DMA2_DoubleBufferModeType;

typedef enum{
	DMA2_STREAM_PRIORITY_LOW,
	DMA2_STREAM_PRIORITY_MEDIUM,
	DMA2_STREAM_PRIORITY_HIGH,
	DMA2_STREAM_PRIORITY_VERY_HIGH
}DMA2_StreamPriorityType;
/* This bit has no meaning if bit PINC = '0'.                      */
/* This bit is protected and can be written only if EN = '0'.      */
/* This bit is forced low by hardware when the stream is enabled   */
/* (bit EN = '1') if the direct mode is selected or if PBURST are  */
/*  different from “00”                                            */
typedef enum{
	DMA2_OFFSET_LINKED_TO_PSIZE,
	DMA2_OFFSET_FIXED_TO_4
}DMA2_PeripheralIncrementOffsetSizeType;


typedef enum{
	DMA2_MEMORY_BYTE,
	DMA2_MEMORY_HALF_WORD,
	DMA2_MEMORY_WORD
}DMA2_MemoryDataSizeType;

typedef enum{
	DMA2_PERIPHERAL_BYTE,
	DMA2_PERIPHERAL_HALF_WORD,
	DMA2_PERIPHERAL_WORD
}DMA2_PeripheralDataSizeType;


typedef enum{
	DMA2_FIXED_MEMORY_ADDRESS,
	DMA2_INCREMENT_MEMORY_ADDRESS
}DMA2_MemoryIncrementModeType;


typedef enum{
	DMA2_FIXED_PERIPHERAL_ADDRESS,
	DMA2_INCREMENT_PERIPHERAL_ADDRESS
}DMA2_PeripheralIncrementModeType;


typedef enum{
	DMA2_CIRCULAR_MODE_DISABLED,
	DMA2_CIRCULAR_MODE_ENABLED,
}DMA2_CircularModeType;


typedef enum{
	DMA2_PERIPHERAL_TO_MEMORY,
	DMA2_MEMORY_TO_PERIPHERAL,
	DMA2_MEMORY_TO_MEMORY
}DMA2_DataDirectionType;


typedef enum{
	DMA2_DMA_FLOW_CONTROLLER,
	DMA2_PERIPHERAL_FLOW_CONTROLLER
}DMA2_PeripheralFlowControllerType;



typedef enum{
	DMA2_TC_DISABLED,
	DMA2_TC_ENABLED
}DMA2_TransferCompleteInterruptType;


typedef enum{
	DMA2_HC_DISABLED,
	DMA2_HC_ENABLED
}DMA2_HalfTransferInterruptType;


typedef enum{
	DMA2_TE_DISABLED,
	DMA2_TE_ENABLED
}DMA2_TransferErrorInterruptType;


typedef enum{
	DMA2_DME_DISABLED,
	DMA2_DME_ENABLED
}DMA2_DirectModeErrorInterruptType;


typedef enum{
	DMA2_STREAM_DISABLED,
	DMA2_STREAM_ENABLED
}DMA2_STREAMType;

typedef enum{
	DMA2_FIFO_INTERRUPT_DISABLE,
	DMA2_FIFO_INTERRUPT_ENABLE
}DMA2_FIFIInterruptType;


typedef enum{
	DMA2_DIRECT_MODE_ENABLED,
	DMA2_DIRECT_MODE_DISABLED
}DMA2_DirectModeType;


typedef enum{
	DMA2_1_4_FULL_FIFO,
	DMA2_1_2_FULL_FIFO,
	DMA2_3_4_FULL_FIFO,
	DMA2_FULL_FIFO
}DMA2_FIFIThresholdType;

/********************************************************************************************/
/************************************** APIs Proto-Types ************************************/
/********************************************************************************************/


void DMA2_Init(void);

void DMA2_SetStreamConfiguration(u8 Copy_u8StreamID,
								 u8 Copy_u8ChannelID,
								 u32 *Copy_pu32SourceAddress,
								 u32 *Copy_pu32DestinationAddress,
							     u8 Copy_u8ElementSize,
								 u16 Copy_u16BlockSize);

void DMA2_SetCallBack(u8 Copy_u8StreamID,void (*ptr)(void));

void DMA2_EnbaleStream(u8 Copy_u8StreamID);

#endif /* MDMA_INTERFACE_H_ */
