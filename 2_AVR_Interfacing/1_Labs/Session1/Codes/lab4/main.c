#include<util/delay.h>
#include"DIO_Interface.h"

int main(){
	uint8 counter=1;
	DIO_Init();

	while(1){

		for(counter=0;counter<8;counter++){
			DIO_enuWritePort(DIO_PORTA_INDEX,(1<<counter));
			_delay_ms(500);
		}

	}
}
