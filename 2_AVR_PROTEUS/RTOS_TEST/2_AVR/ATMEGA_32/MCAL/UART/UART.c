/*******************************************************************************************/
/*  Module       :   UART                                                                  */
/*  File Name    :   UART.c                                                                */
/*  Description  :   Source File of the UART                                               */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   23/08/2023                                                            */
/*******************************************************************************************/


#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "UART.h"
#include "UART_Registers.h"
#define  F_CPU                8000000UL
void UART_voidInit(void)
{
	uint16 UBRR_value;
	/* - Adjust the baud rate
	 * - Adjust the speed which are : Normal or Double Speed or UART Synch */
#if UART_SPEED_SELECTION ==UART_ASYNCHRONOUS_NORMAL_MODE
	UBRR_value=(uint16)((F_CPU/(16*UART_BAUD_RATE_SELECTION))-1);
	/* Adjust Normal Speed Mode */
	CLEAR_BIT(UCSRA,U2X);
#elif UART_SPEED_SELECTION ==UART_ASYNCHRONOUS_DOUBLE_SPEED_MODE
	UBRR_value=(uint16)((F_CPU/(8*UART_BAUD_RATE_SELECTION))-1);
	/* Adjust Double Speed Mode */
	SET_BIT(UCSRA,U2X);
#elif UART_SPEED_SELECTION ==UART_SYNCHRONOUS_MASTER_MODE
	UBRR_value=(uint16)((F_CPU/(2*UART_BAUD_RATE_SELECTION))-1);
	/* Adjust the clock type of the synch mode */
	/* Choose UCRSC Register by set bit URSEL
	 * Adjust the clock by oring the value in bit 0 */
	UCSRC = (UCSRC | 0x80) | (UCSRC & 0xFE) | UART_SYNCH_CLOCK_TYPE;
#endif
	UBRRL = (uint8)UBRR_value;
	UBRRH = (uint8)(UBRR_value>>8);

	/* Adjust the :
	 *         - Transmitter Circuit
	 *         - Receiver Circuit
	 *         - UART receiver interrupt
	 *         - UART transmitter interrupt
	 *         - UART data register empty interrupt
	 *                                            */
	UCSRB =  (UCSRB & 0x07) | (UART_RX_INTERRUPT << RXCIE) \
			|(UART_TX_INTERRUPT << TXCIE)\
			|(UART_DATA_REGISTER_EMPTY_INTERRUPT <<  UDRIE)\
			|(UART_RECEIVER_CIRCUIT << RXEN)\
			|(UART_TRANSMITTER_CIRCUIT << TXEN);


	/* Adjust the UART :
	 *        - Mode
	 *        - Parity
	 *        - Stop Bit
	 *        - Character Size */
	UCSRC = (UCSRC | 0x80) | (UCSRC & 0x81) | (UART_MODE_SELECTION <<UMSEL)\
			|(UART_PARITY_SELECTION<<UPM0)\
			|(UART_STOP_BIT_SELECTION<<USBS)\
			|((UART_DATA_SELECTION & 0x03 )<<UCSZ0);
	UCSRB = (UCSRB & 0xFB) | (UART_DATA_SELECTION & 0x04);



}

void UART_voidSendDataByte(uint8 Copy_u8DataByte)
{
	/* Check if tx buffer is empty */
	/* 1 : Empty
	 * 0 : Not Empty */
	/* Code will be stuced if flag = 0*/
	while((GET_BIT(UCSRA,UDRE) )==0);
	UDR = Copy_u8DataByte;
}

void UART_voidReceiveDataByte(uint8 *Copy_u8DataByte)
{
	/* Check if rx buffer = 1 */
	while((GET_BIT(UCSRA,RXC))==0);
	*Copy_u8DataByte = UDR;
}


void UART_voidSendDataString(uint8 *Copy_u8DataString){
	uint8 counter=0;
	while(Copy_u8DataString[counter]!='\0'){
		UART_voidSendDataByte(Copy_u8DataString[counter]);
		counter++;
	}
}


void UART_voidReceiveDataString(uint8 *Copy_u8DataString){
	uint8 counter=0;
	while(Copy_u8DataString[counter]!='\0'){
		UART_voidReceiveDataByte(&Copy_u8DataString[counter]);
		counter++;
	}

}


/* Send Byte Asynch */
tenuErrorStatus UART_voidSendDataByteAsynch(uint8 Copy_u8DataByte){
	tenuErrorStatus enuErrorState=ENOK;
	/* We can only send byte if this flag equal 1 */
	if((GET_BIT(UCSRA,UDRE) )==1){
		UDR=Copy_u8DataByte;
		enuErrorState = EOK;
	}
	else{
		enuErrorState = ENOK;
	}
	return enuErrorState;
}

tenuErrorStatus UART_voidReceiveDataByteAsynch(uint8 *Copy_u8DataByte){
	tenuErrorStatus enuErrorState=ENOK;
	if((GET_BIT(UCSRA,RXC) )==1){
		/* Here, UART receive completed*/
		*Copy_u8DataByte = UDR;
		enuErrorState=EOK;
	}
	else{
		enuErrorState=ENOK;
	}
	return enuErrorState;
}


void UART_voidEnableIntRxComp(void){
	SET_BIT(UCSRB,RXCIE);
}
void UART_voidDisableIntRxComp(void){
	CLEAR_BIT(UCSRB,RXCIE);
}
void UART_voidEnableIntTxComp(void){
	SET_BIT(UCSRB,TXCIE);
}
void UART_voidDisableIntTxComp(void){
	CLEAR_BIT(UCSRB,TXCIE);
}
void UART_voidEnableIntTxEmpty(void){
	SET_BIT(UCSRB,UDRIE);
}
void UART_voidDisableIntTxEmpty(void){
	CLEAR_BIT(UCSRB,UDRIE);
}
