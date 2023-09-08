//#include <util/delay.h>
//#include "UART.h"
//#include "..\DIO_DRIVER\DIO_Interface.h"
//
//
//int main(){
//	uint8 received;
//	DIO_Init();
//	UART_voidInit();
//	while(1){
//		UART_voidSendDataByte('A');
//		_delay_ms(1000);
//		UART_voidReceiveDataByte(&received);
//		if(received=='1'){
//			DIO_enuWritePin(0,LEVEL_HIGH);
//		}
//		else if(received=='2'){
//			DIO_enuWritePin(0,LEVEL_LOW);
//		}
//		_delay_ms(1000);
//
//	}
//}
