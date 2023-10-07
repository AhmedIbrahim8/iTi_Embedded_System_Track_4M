#include "..\include\STD_Types.h"
#include "..\include\BIT_MATH.h"

#include "..\include\MGPIO_Interface.h"
#include "..\include\MRCC_Interface.h"
#include "..\include\MSYSTICK_Interface.h"

int main(){
	MRCC_Init();
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MGPIO_SetMode(PORTA,PIN6,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN6,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	SYSTICK_voidInit();
	while(1)
	{
		MGPIO_SetPinValue(PORTA,PIN6,PIN_LEVEL_HIGH);
		SYSTICK_voidDelayUs(1000000);
		MGPIO_SetPinValue(PORTA,PIN6,PIN_LEVEL_LOW);
		SYSTICK_voidDelayUs(1000000);
	}


	return 0;
}
