/*******************************************************************************************/
/*  Module       :   UART                                                                   */
/*  File Name    :   UART_private.h                                                         */
/*  Description  :   Private Header File of the UART                                         */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   32/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_UART_UART_TYPES_H_
#define MCAL_UART_UART_TYPES_H_

#define  UART_RX_INTERRUPT_ENABLE                            1
#define  UART_RX_INTERRUPT_DISABLE                           0


#define  UART_TX_INTERRUPT_ENABLE                            1
#define  UART_TX_INTERRUPT_DISABLE                           0

#define  UART_DATA_REGISTER_EMPTY_INTERRUPT_ENABLE           1
#define  UART_DATA_REGISTER_EMPTY_INTERRUPT_DISABLE          0

#define  UART_RECEIVER_CIRCUIT_ENABLE                        1
#define  UART_RECEIVER_CIRCUIT_DISABLE                       0

#define  UART_TRANSMITTER_CIRCUIT_ENABLE                     1
#define  UART_TRANSMITTER_CIRCUIT_DISABLE                    0


#define 	UART_ASYNCHRONOUS                                0
#define 	UART_SYNCHRONOUS                                 1



#define 	UART_ASYNCHRONOUS_NORMAL_MODE                    0
#define     UART_ASYNCHRONOUS_DOUBLE_SPEED_MODE              1
#define 	UART_SYNCHRONOUS_MASTER_MODE                     2


#define 	UART_BAUD_RATE_2400                              2400UL
#define 	UART_BAUD_RATE_4800                              4800UL
#define 	UART_BAUD_RATE_9600                              9600UL
#define 	UART_BAUD_RATE_14400                             14400UL
#define 	UART_BAUD_RATE_19200                             19200UL
#define     UART_BAUD_RATE_28800                             28800UL
#define 	UART_BAUD_RATE_38400                             38400UL
#define 	UART_BAUD_RATE_57600                             57600UL
#define 	UART_BAUD_RATE_76800                             76800UL
#define 	UART_BAUD_RATE_115200                            115200UL
#define 	UART_BAUD_RATE_230400                            230400UL
#define 	UART_BAUD_RATE_250000                            250000UL
#define 	UART_BAUD_RATE_500000                            500000UL
#define 	UART_BAUD_RATE_1000000                           1000000UL



#define 	UART_ONE_STOP_BIT                  0
#define 	UART_TWO_STOP_BIT                  1



#define 	UART_DATA_5_BIT                 0
#define 	UART_DATA_6_BIT                 1
#define 	UART_DATA_7_BIT                 2
#define 	UART_DATA_8_BIT                 3
#define 	UART_DATA_9_BIT                 7




#define 	UART_PARITY_DISABLED       0
#define 	UART_EVEN_PARITY           2
#define 	UART_ODD_PARITY            3




#define 	UART_SYNCH_CLOCK_RISING_FALLING         0
#define 	UART_SYNCH_CLOCK_FALLING_RISING         1



#endif /* MCAL_UART_UART_TYPES_H_ */
