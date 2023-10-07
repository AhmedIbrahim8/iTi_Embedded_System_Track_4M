#include "..\include\STD_Types.h"
#include "..\include\BIT_MATH.h"

#include "..\include\MGPIO_Interface.h"
#include "..\include\MRCC_Interface.h"
#include "..\include\MSYSTCK_Interface.h"

int main(){
	u8 pin_value=0;
	u8 flag=1;
	MRCC_Init();
	MSTK_voidInit();
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	/* PORTA Pin 6 is output pin */
	MGPIO_SetMode(PORTA,PIN6,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN6,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	/* PORTB Pin 0 is output pin */
	MGPIO_SetMode(PORTB,PIN0,INPUT_RESET_STATE);
	MGPIO_SetInputPinMode(PORTB,PIN0,PULL_DOWN);
	while(1)
	{
		MGPIO_GetPinValue(PORTB,PIN0,&pin_value);
		if(pin_value==1 && flag==1){
			MGPIO_SetPinValue(PORTA,PIN6,PIN_LEVEL_HIGH);
			while(pin_value==1)
			{
				MGPIO_GetPinValue(PORTB,PIN0,&pin_value);
			}
			flag=0;
		}
		else if(pin_value==1 && flag==0 )
		{
			MGPIO_SetPinValue(PORTA,PIN6,PIN_LEVEL_LOW);
			while(pin_value==1)
			{
				MGPIO_GetPinValue(PORTB,PIN0,&pin_value);
			}

			flag=1;
		}
	}
	return 0;
}
