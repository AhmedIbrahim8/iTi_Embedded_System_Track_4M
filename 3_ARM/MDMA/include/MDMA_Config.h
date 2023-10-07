/*******************************************************************************************/
/*  Module       :   DMA                                                                  */
/*  File Name    :   MDMA_Congif.h                                                        */
/*  Description  :   Header File of the DMA Driver Configuration                          */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   17/09/2023                                                            */
/*******************************************************************************************/

#ifndef MDMA_CONFIG_H_
#define MDMA_CONFIG_H_

#define    DMA2_STREAM_0_TRANSFER_COMPLETE_INTERRUPT                      DMA2_TC_ENABLED
#define    DMA2_STREAM_0_HALF_TRANSFER_COMPLETE_INTERRUPT                 DMA2_HC_DISABLED
#define    DMA2_STREAM_0_TRANSFER_ERROR_INTERRUPT                         DMA2_TE_DISABLED
#define    DMA2_STREAM_0_DIRECT_MODE_ERROR_INTERRUPT                      DMA2_DME_DISABLED

#define    DMA2_STREAM_0_PERIPHERAL_FLOW_CONTROLLER                       DMA2_DMA_FLOW_CONTROLLER

#define    DMA2_STREAM_0_DATA_TRANSFER_DIRECTION                          DMA2_MEMORY_TO_MEMORY

#define    DMA2_STREAM_0_CIRCULAR_MODE                                    DMA2_CIRCULAR_MODE_DISABLED

#define    DMA2_STREAM_0_PERIPHERAL_INCREMENT_MODE                        DMA2_INCREMENT_PERIPHERAL_ADDRESS

#define    DMA2_STREAM_0_MEMORY_INCREMENT_MODE                            DMA2_INCREMENT_MEMORY_ADDRESS

#define    DMA2_STREAM_0_FIFO_ERROR_INTERRUPT                             DMA2_FIFO_INTERRUPT_DISABLE

#define    DMA2_STREAM_0_DIRECT_MODE_TYPE                                 DMA2_DIRECT_MODE_DISABLED

#define    DMA2_STREAM_0_FIFI_THRESHOLD_SELECTION                         DMA2_FULL_FIFO



/**/
#define    DMA2_STREAM_0_PERIPHERAL_DATA_SIZE                                      DMA2_PERIPHERAL_HALF_WORD

#define    DMA2_STREAM_0_MEMORY_DATA_SIZE                                          DMA2_MEMORY_HALF_WORD

#define    DMA2_STREAM_0_PERIPHERAL_INCREMENT_OFFSET_SIZE                          DMA2_OFFSET_LINKED_TO_PSIZE

#define    DMA2_STREAM_0_PRIORITY_LEVEL                                            DMA2_STREAM_PRIORITY_LOW

#define    DMA2_STREAM_0_DOUBLE_BUFFER_MODE                                        DMA2_NO_BUFFER_SWITCHING

#define    DMA2_STREAM_0_CURRENT_TARGET                                            DMA2_MEMORY_M0AR

#define    DMA2_STREAM_0_PERIPHERAL_BURST_TRANSFER_CONFIGURATION                   DMA2_PERIPHERAL_SINGLE_TRANSFER

#define    DMA2_STREAM_0_MEMORY_BURST_TRANSFER_CONFIGURATION                       DMA2_MEMORY_SINGLE_TRANSFER





#endif /* MDMA_CONFIG_H_ */
