/*******************************************************************************************/
/*  Module       :   UART                                                                  */
/*  File Name    :   UART.h                                                                */
/*  Description  :   Header File of the UART                                               */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   23/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_
#include "..\..\LIB\Std_Types.h"
#include "UART_Types.h"
#include "UART_Cfg.h"

void UART_voidInit(void);

void UART_voidSendDataByte(uint8 Copy_u8DataByte);

void UART_voidReceiveDataByte(uint8 *Copy_u8DataByte);

void UART_voidSendDataString(uint8 *Copy_u8DataString);

void UART_voidReceiveDataString(uint8 *Copy_u8DataString);


tenuErrorStatus UART_voidSendDataByteAsynch(uint8 Copy_u8DataByte);
tenuErrorStatus UART_voidReceiveDataByteAsynch(uint8 *Copy_u8DataByte);
void UART_voidSendDataStringAsynch(uint8 *Copy_u8DataString);
void UART_voidReceiveDataStringAsynch(uint8 *Copy_u8DataString);

void UART_voidEnableIntRxComp(void);
void UART_voidDisableIntRxComp(void);
void UART_voidEnableIntTxComp(void);
void UART_voidDisableIntTxComp(void);
void UART_voidEnableIntTxEmpty(void);
void UART_voidDisableIntTxEmpty(void);

#endif /* MCAL_UART_UART_H_ */
