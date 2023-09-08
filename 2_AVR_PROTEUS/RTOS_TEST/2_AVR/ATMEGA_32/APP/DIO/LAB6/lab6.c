#include "..\..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include "..\..\..\MCAL\DIO_DRIVER\Dio_Registers.h"
#include <util/delay.h>
/*
int main(){
	DIO_Init();
	while(1){
		if((PINC & (1<<2))){
			DIO_enuWritePort( DIO_PORTA_INDEX,0xFF);
			_delay_ms(500);
			DIO_enuWritePort( DIO_PORTA_INDEX,0x00);
			_delay_ms(500);
		}

	}
}
*/
