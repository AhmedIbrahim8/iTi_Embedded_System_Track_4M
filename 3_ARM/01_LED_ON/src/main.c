#include "..\include\STD_Types.h"
#include "..\include\BIT_MATH.h"

#include "..\include\MGPIO_Interface.h"
#include "..\include\MRCC_Interface.h"


int main(){
	MRCC_Init();
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MGPIO_SetMode(PORTA,PIN0,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetPinValue(PORTA,PIN0,PIN_LEVEL_HIGH);
	while(1)
	{

	}


	return 0;
}
