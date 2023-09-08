#include "..\..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include <util/delay.h>
//
//int main(){
//	sint8 counter;
//	DIO_Init();
//	while(1){
//		int value=0;
//		DIO_enuReadPort(DIO_PORTC_INDEX ,&value);
//		switch(value){
//		case 0:
//			DIO_enuWritePort(DIO_PORTA_INDEX,0xFF);
//			_delay_ms(500);
//			DIO_enuWritePort(DIO_PORTA_INDEX,0x00);
//			_delay_ms(500);
//			break;
//		case 1:
//			for(counter=0;counter<8;counter++){
//				DIO_enuWritePort(DIO_PORTA_INDEX,1<<counter);
//				_delay_ms(250);
//			}
//			break;
//		case 2:
//			for(counter=7;counter>=0;counter--){
//				DIO_enuWritePort(DIO_PORTA_INDEX,1<<counter);
//				_delay_ms(250);
//			}
//			break;
//			/* Converging */
//		case 3:
//			for(counter=0;counter<4;counter++){
//				DIO_enuWritePort(DIO_PORTA_INDEX,1<<(8-counter-1));
//				DIO_enuWritePin(DIO_PIN_NUM_A0+counter,1);
//				_delay_ms(300);
//			}
//			break;
//			/* Diverging */
//		case 4:
//			for(counter=4;counter>0;counter--){
//				DIO_enuWritePort(DIO_PORTA_INDEX,1<<(8-counter));
//				DIO_enuWritePin(DIO_PIN_NUM_A0+counter-1,1);
//				_delay_ms(300);
//			}
//			break;
//		case 5:
//			for(counter=0;counter<8;counter++){
//				DIO_enuWritePort(DIO_PORTA_INDEX,1<<counter);
//				_delay_ms(250);
//			}
//			for(counter=7;counter>=0;counter--){
//				DIO_enuWritePort(DIO_PORTA_INDEX,1<<counter);
//				_delay_ms(250);
//			}
//			break;
//		case 6:
//			for(counter=0;counter<8;counter++){
//				DIO_enuWritePin(DIO_PIN_NUM_A0+counter,1);
//				_delay_ms(300);
//			}
//			DIO_enuWritePort(DIO_PORTA_INDEX,0x0);
//			break;
//		case 7:
//			DIO_enuWritePort(DIO_PORTA_INDEX,0x99);
//			_delay_ms(300);
//			DIO_enuWritePort(DIO_PORTA_INDEX,0x66);
//			_delay_ms(300);
//			DIO_enuWritePort(DIO_PORTA_INDEX,0x18);
//			_delay_ms(300);
//			DIO_enuWritePort(DIO_PORTA_INDEX,0x00);
//			_delay_ms(300);
//			break;
//		}
//
//
//	}
//}
