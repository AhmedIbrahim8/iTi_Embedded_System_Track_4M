#include<util/delay.h>
#include"DIO_Interface.h"

int main(){
	DIO_Init();

	while(1){
		DIO_enuWritePin(DIO_PIN_NUM_A0,LEVEL_HIGH);
		_delay_ms(1000);
		DIO_enuWritePin(DIO_PIN_NUM_A0,LEVEL_LOW);
		_delay_ms(1000);
	}
}
