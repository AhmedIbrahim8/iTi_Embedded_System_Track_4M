/*******************************************************************************************/
/*  Module       :   USART                                                                 */
/*  File Name    :   MUSART_Config.h                                                       */
/*  Description  :   Header File of the USART Configuration Driver                         */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   19/09/2023                                                            */
/*******************************************************************************************/

#ifndef MUSART_CONFIG_H_
#define MUSART_CONFIG_H_

#define          USART_OVERSAMPLE         USART_OVERSAMPLE_16
#define          USART_MANTISSA           USART_16MHZ_16SAMPLE_BR_9600_MANTISSA
#define          USART_FRACTION           USART_16MHZ_16SAMPLE_BR_9600_FRACTION
#define          USART_DATA_BITS          USART_8_DATA_BITS
#define          USART_PARITY_CONTROL     USART_PARITY_CONTROL_DISABLE
#define          USART_PARITY_SELECTION   USART_EVEN_PARITY_SELECTION

#define          USART_STOP_BIT           USART_1_STOP_BIT


#define  USART_TRANSMITTER                USART_TRANSMITTER_ENABLE

#define  USART_RECEIVER                   USART_RECEIVER_ENABLE

#define  USART_RX_INTERRUPT               USART_RX_INTERRUPT_DISABLE


#endif /* MUSART_CONFIG_H_ */
