
#include"DIO_Interface.h"

int main(){
	DIO_Init();

	while(1){
		DIO_enuWritePin(DIO_PIN_NUM_A0,LEVEL_HIGH);
	}
}
