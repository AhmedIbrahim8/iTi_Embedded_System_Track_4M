/*******************************************************************************************/
/*  Module       :   UART                                                                  */
/*  File Name    :   UART_Cfg.h                                                            */
/*  Description  :   Header File of the UART Configuration                                 */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   23/08/2023                                                            */
/*******************************************************************************************/

#ifndef MCAL_UART_UART_CFG_H_
#define MCAL_UART_UART_CFG_H_
/* Baud Rate Selection */
#define  UART_BAUD_RATE_SELECTION              UART_BAUD_RATE_9600

/* Speed Selection of UART */
#define  UART_SPEED_SELECTION                  UART_ASYNCHRONOUS_NORMAL_MODE

/* Clock type in case of synch*/
#define UART_SYNCH_CLOCK_TYPE                  UART_SYNCH_CLOCK_RISING_FALLING


/* Mode Selection of the UART */
#define  UART_MODE_SELECTION                   UART_ASYNCHRONOUS

/* Parity selection */
#define UART_PARITY_SELECTION                   UART_PARITY_DISABLED

/* Stop bit numbers */
#define  UART_STOP_BIT_SELECTION               UART_TWO_STOP_BIT

/* Number of Data */
#define  UART_DATA_SELECTION                    UART_DATA_8_BIT



#define  UART_RX_INTERRUPT                     UART_RX_INTERRUPT_DISABLE

#define  UART_TX_INTERRUPT                     UART_TX_INTERRUPT_DISABLE

#define  UART_DATA_REGISTER_EMPTY_INTERRUPT    UART_DATA_REGISTER_EMPTY_INTERRUPT_DISABLE

#define  UART_RECEIVER_CIRCUIT                 UART_RECEIVER_CIRCUIT_ENABLE

#define  UART_TRANSMITTER_CIRCUIT              UART_TRANSMITTER_CIRCUIT_ENABLE


#endif /* MCAL_UART_UART_CFG_H_ */
