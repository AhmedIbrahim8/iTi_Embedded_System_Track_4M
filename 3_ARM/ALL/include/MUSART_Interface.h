/*******************************************************************************************/
/*  Module       :   USART                                                                 */
/*  File Name    :   MUSART_Interface.h                                                    */
/*  Description  :   Header File of the USART Interface Driver                             */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   19/09/2023                                                            */
/*******************************************************************************************/



#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_


/********************************************************************************************/
/************************************** Mask and #s Used ************************************/
/********************************************************************************************/
#define      USART_STOP_BIT_MASK                0xFFFFCFFF
#define      USART_NUMBER_0                          0
/*******************************************************************************/
/******************* Control Register 1 Configuration #s************************/
/*******************************************************************************/
#define  USART_OVERSAMPLE_16                     0
#define  USART_OVERSAMPLE_8                      1

#define  USART_DISABLE_PERIPHERAL                0
#define  USART_ENABLE_PERIPHERAL                 1

#define  USART_8_DATA_BITS                       0
#define  USART_9_DATA_BITS                       1

#define  USART_IDLE_LINE_WAKE_UP_METHOD          0
#define  USART_ADDRESS_MARK_WAKE_UP_METHOD       1

#define  USART_PARITY_CONTROL_DISABLE            0
#define  USART_PARITY_CONTROL_ENABLE             1

#define  USART_EVEN_PARITY_SELECTION             0
#define  USART_ODD_PARITY_SELECTION              1

#define  USART_PE_INTERRUPT_DISABLE              0
#define  USART_PE_INTERRUPT_ENABLE               1

#define  USART_TXE_INTERRUPT_DISABLE             0
#define  USART_TXE_INTERRUPT_ENABLE              1

#define  USART_TC_INTERRUPT_DISABLE              0
#define  USART_TC_INTERRUPT_ENABLE               1

#define  USART_RX_INTERRUPT_DISABLE              0
#define  USART_RX_INTERRUPT_ENABLE               1

#define  USART_IDLE_INTERRUPT_DISABLE            0
#define  USART_IDLE_INTERRUPT_ENABLE             1

#define  USART_TRANSMITTER_DISABLE               0
#define  USART_TRANSMITTER_ENABLE                1

#define  USART_RECEIVER_DISABLE                  0
#define  USART_RECEIVER_ENABLE                   1

#define  USART_RECEIVER_WAKE_UP_ACTIVE_MODE      0
#define  USART_RECEIVER_WAKE_UP_MUTE_MODE        1

#define  USART_BREAK_CHARACTER_NO_TRANSMITT      0
#define  USART_BREAK_CHARACTER__TRANSMITT        1

/*******************************************************************************/
/******************* Control Register 2 Configuration #s************************/
/*******************************************************************************/
#define  USART_LIN_MODE_DISABLE                        0
#define  USART_LIN_MODE_ENABLE                         1

#define  USART_CLOCK_PIN_DISABLE                       0
#define  USART_CLOCK_PIN_ENABLE                        1

#define  USART_CLOCK_POLARITY_STEADY_LOW               0
#define  USART_CLOCK_POLARITY_STEADY_HIGH              1

#define  USART_CLOCK_PHASE_FIRST_CLOCK                 0
#define  USART_CLOCK_PHASE_SECOND_CLOCK                1

#define  USART_LAST_BIT_CLOCK_PULSE_NOT_OUTPUT         0
#define  USART_LAST_BIT_CLOCK_PULSE_OUTPUT             1

#define  USART_LIN_BREAK_DETECTION_INTERRUPT_DISABLE   0
#define  USART_LIN_BREAK_DETECTION_INTERRUPT_ENABLE    1

#define  USART_LIN_BREAK_LENGTH_10_BIT                 0
#define  USART_LIN_BREAK_LENGTH_11_BIT                 1

/***************************************************************/
/**** Value of Mantissa and Fraction incase of 16 samples   ****/
/**** and 8 MHZ Clock for Multiple Baud Rate                ****/
/***************************************************************/
#define 	USART_8MHZ_16SAMPLE_BR_1200_MANTISSA               0X1A0
#define 	USART_8MHZ_16SAMPLE_BR_1200_FRACTION               0xB

#define 	USART_8MHZ_16SAMPLE_BR_2400_MANTISSA               0xD0
#define 	USART_8MHZ_16SAMPLE_BR_2400_FRACTION               0x5

#define 	USART_8MHZ_16SAMPLE_BR_9600_MANTISSA               0x34
#define 	USART_8MHZ_16SAMPLE_BR_9600_FRACTION               0x1

#define 	USART_8MHZ_16SAMPLE_BR_19200_MANTISSA              0x1A
#define 	USART_8MHZ_16SAMPLE_BR_19200_FRACTION              0x1

#define 	USART_8MHZ_16SAMPLE_BR_38400_MANTISSA              0xD
#define 	USART_8MHZ_16SAMPLE_BR_38400_FRACTION              0x0

#define 	USART_8MHZ_16SAMPLE_BR_57600_MANTISSA              0x8
#define 	USART_8MHZ_16SAMPLE_BR_57600_FRACTION              0xB

#define 	USART_8MHZ_16SAMPLE_BR_115200_MANTISSA             0x4
#define 	USART_8MHZ_16SAMPLE_BR_115200_FRACTION             0x5

#define 	USART_8MHZ_16SAMPLE_BR_230400_MANTISSA             0x2
#define 	USART_8MHZ_16SAMPLE_BR_230400_FRACTION             0x3

#define 	USART_8MHZ_16SAMPLE_BR_460800_MANTISSA             0x1
#define 	USART_8MHZ_16SAMPLE_BR_460800_FRACTION             0x1

/***************************************************************/
/**** Value of Mantissa and Fraction incase of 16 samples   ****/
/**** and 12 MHZ Clock for Multiple Baud Rate               ****/
/***************************************************************/
#define 	USART_12MHZ_16SAMPLE_BR_1200_MANTISSA               0x271
#define 	USART_12MHZ_16SAMPLE_BR_1200_FRACTION               0x0

#define 	USART_12MHZ_16SAMPLE_BR_2400_MANTISSA               0x138
#define 	USART_12MHZ_16SAMPLE_BR_2400_FRACTION               0x8

#define 	USART_12MHZ_16SAMPLE_BR_9600_MANTISSA               0X4E
#define 	USART_12MHZ_16SAMPLE_BR_9600_FRACTION               0x2

#define 	USART_12MHZ_16SAMPLE_BR_19200_MANTISSA              0X27
#define 	USART_12MHZ_16SAMPLE_BR_19200_FRACTION              0x1

#define 	USART_12MHZ_16SAMPLE_BR_38400_MANTISSA              0X13
#define 	USART_12MHZ_16SAMPLE_BR_38400_FRACTION              0x9

#define 	USART_12MHZ_16SAMPLE_BR_57600_MANTISSA              0xD
#define 	USART_12MHZ_16SAMPLE_BR_57600_FRACTION              0x0

#define 	USART_12MHZ_16SAMPLE_BR_115200_MANTISSA             0x6
#define 	USART_12MHZ_16SAMPLE_BR_115200_FRACTION             0x8

#define 	USART_12MHZ_16SAMPLE_BR_230400_MANTISSA             0x3
#define 	USART_12MHZ_16SAMPLE_BR_230400_FRACTION             0x4

#define 	USART_12MHZ_16SAMPLE_BR_460800_MANTISSA             0x1
#define 	USART_12MHZ_16SAMPLE_BR_460800_FRACTION             0xA


/***************************************************************/
/**** Value of Mantissa and Fraction incase of 8 samples    ****/
/**** and 8 MHZ Clock for Multiple Baud Rate                ****/
/***************************************************************/
#define 	USART_8MHZ_8SAMPLE_BR_1200_MANTISSA               0x341
#define 	USART_8MHZ_8SAMPLE_BR_1200_FRACTION               0x3

#define 	USART_8MHZ_8SAMPLE_BR_2400_MANTISSA               0x1A0
#define 	USART_8MHZ_8SAMPLE_BR_2400_FRACTION               0x5

#define 	USART_8MHZ_8SAMPLE_BR_9600_MANTISSA               0x68
#define 	USART_8MHZ_8SAMPLE_BR_9600_FRACTION               0x1

#define 	USART_8MHZ_8SAMPLE_BR_19200_MANTISSA              0x34
#define 	USART_8MHZ_8SAMPLE_BR_19200_FRACTION              0x1

#define 	USART_8MHZ_8SAMPLE_BR_38400_MANTISSA              0x1A
#define 	USART_8MHZ_8SAMPLE_BR_38400_FRACTION              0x0

#define 	USART_8MHZ_8SAMPLE_BR_57600_MANTISSA              0x11
#define 	USART_8MHZ_8SAMPLE_BR_57600_FRACTION              0x3

#define 	USART_8MHZ_8SAMPLE_BR_115200_MANTISSA             0x8
#define 	USART_8MHZ_8SAMPLE_BR_115200_FRACTION             0x5

#define 	USART_8MHZ_8SAMPLE_BR_230400_MANTISSA             0x4
#define 	USART_8MHZ_8SAMPLE_BR_230400_FRACTION             0x3

#define 	USART_8MHZ_8SAMPLE_BR_460800_MANTISSA             0x2
#define 	USART_8MHZ_8SAMPLE_BR_460800_FRACTION             0x1

#define 	USART_8MHZ_8SAMPLE_BR_921600_MANTISSA             0x1
#define 	USART_8MHZ_8SAMPLE_BR_921600_FRACTION             0x1


/***************************************************************/
/**** Value of Mantissa and Fraction incase of 8 samples    ****/
/**** and 12 MHZ Clock for Multiple Baud Rate               ****/
/***************************************************************/
#define 	USART_12MHZ_8SAMPLE_BR_1200_MANTISSA               0x4E2
#define 	USART_12MHZ_8SAMPLE_BR_1200_FRACTION               0x0

#define 	USART_12MHZ_8SAMPLE_BR_2400_MANTISSA               0x271
#define 	USART_12MHZ_8SAMPLE_BR_2400_FRACTION               0x0

#define 	USART_12MHZ_8SAMPLE_BR_9600_MANTISSA               0x9C
#define 	USART_12MHZ_8SAMPLE_BR_9600_FRACTION               0x2

#define 	USART_12MHZ_8SAMPLE_BR_19200_MANTISSA              0x4E
#define 	USART_12MHZ_8SAMPLE_BR_19200_FRACTION              0x1

#define 	USART_12MHZ_8SAMPLE_BR_38400_MANTISSA              0x27
#define 	USART_12MHZ_8SAMPLE_BR_38400_FRACTION              0x1

#define 	USART_12MHZ_8SAMPLE_BR_57600_MANTISSA              0x1A
#define 	USART_12MHZ_8SAMPLE_BR_57600_FRACTION              0x0

#define 	USART_12MHZ_8SAMPLE_BR_115200_MANTISSA             0xD
#define 	USART_12MHZ_8SAMPLE_BR_115200_FRACTION             0x0

#define 	USART_12MHZ_8SAMPLE_BR_230400_MANTISSA             0x6
#define 	USART_12MHZ_8SAMPLE_BR_230400_FRACTION             0x4

#define 	USART_12MHZ_8SAMPLE_BR_460800_MANTISSA             0x3
#define 	USART_12MHZ_8SAMPLE_BR_460800_FRACTION             0x2

#define 	USART_12MHZ_8SAMPLE_BR_921600_MANTISSA             0x1
#define 	USART_12MHZ_8SAMPLE_BR_921600_FRACTION             0x5




/***************************************************************/
/**** Value of Mantissa and Fraction incase of 16 samples   ****/
/**** and 16 MHZ Clock for Multiple Baud Rate               ****/
/***************************************************************/
#define 	USART_16MHZ_16SAMPLE_BR_1200_MANTISSA               0x341
#define 	USART_16MHZ_16SAMPLE_BR_1200_FRACTION               0x5

#define 	USART_16MHZ_16SAMPLE_BR_2400_MANTISSA               0x1A0
#define 	USART_16MHZ_16SAMPLE_BR_2400_FRACTION               0xB

#define 	USART_16MHZ_16SAMPLE_BR_9600_MANTISSA               0x68
#define 	USART_16MHZ_16SAMPLE_BR_9600_FRACTION               0x3

#define 	USART_16MHZ_16SAMPLE_BR_19200_MANTISSA              0x34
#define 	USART_16MHZ_16SAMPLE_BR_19200_FRACTION              0x1

#define 	USART_16MHZ_16SAMPLE_BR_38400_MANTISSA              0x1A
#define 	USART_16MHZ_16SAMPLE_BR_38400_FRACTION              0x1

#define 	USART_16MHZ_16SAMPLE_BR_57600_MANTISSA              0x11
#define 	USART_16MHZ_16SAMPLE_BR_57600_FRACTION              0x6

#define 	USART_16MHZ_16SAMPLE_BR_115200_MANTISSA             0x8
#define 	USART_16MHZ_16SAMPLE_BR_115200_FRACTION             0xB

#define 	USART_16MHZ_16SAMPLE_BR_230400_MANTISSA             0x4
#define 	USART_16MHZ_16SAMPLE_BR_230400_FRACTION             0x5

#define 	USART_16MHZ_16SAMPLE_BR_460800_MANTISSA             0x2
#define 	USART_16MHZ_16SAMPLE_BR_460800_FRACTION             0x3

#define 	USART_16MHZ_16SAMPLE_BR_921600_MANTISSA             0x1
#define 	USART_16MHZ_16SAMPLE_BR_921600_FRACTION             0x1



/********************************************************************************************/
/************************************** Typedef Used ****************************************/
/********************************************************************************************/
/* Stop Bit type */
typedef enum{
	USART_1_STOP_BIT,
	USART_0_5_STOP_BIT,
	USART_2_STOP_BIT,
	USART_1_5_STOP_BIT
}USART_StopBitType;





/********************************************************************************************/
/************************************** APIs Proto-Types ************************************/
/********************************************************************************************/
void MUSART_voidInit(void);

void MUSART_voidTransmit(u8* Copy_u8Data,u8 Copy_u8Length);

u8 MUSART_u8Receive();

void MUSART_voidEnable();

void MUSART_voidDisable();


void MUSART_voidSetCallBack(void (*ptr) (void));


#endif /* MUSART_INTERFACE_H_ */
