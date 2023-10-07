#include "..\include\STD_Types.h"
#include "..\include\BIT_MATH.h"

#include "..\include\MGPIO_Interface.h"
#include "..\include\MRCC_Interface.h"
#include "..\include\MSYSTCK_Interface.h"

int main(){
	u8 pin_value1=0;
	u8 flag1=1;
	u8 pin_value2=0;
	u8 flag2=1;

	u8 i=0;
	u8 value=0;
	MRCC_Init();
	MSTK_voidInit();
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);

	/* PORTA Pin 0 is output pin */
	MGPIO_SetMode(PORTA,PIN0,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	/* PORTA Pin 1 is output pin */
	MGPIO_SetMode(PORTA,PIN1,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	/* PORTA Pin 2 is output pin */
	MGPIO_SetMode(PORTA,PIN2,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN2,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	/* PORTA Pin 3 is output pin */
	MGPIO_SetMode(PORTA,PIN3,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN3,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	/* PORTA Pin 4 is output pin */
	MGPIO_SetMode(PORTA,PIN4,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN4,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	/* PORTA Pin 5 is output pin */
	MGPIO_SetMode(PORTA,PIN5,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN5,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	/* PORTA Pin 6 is output pin */
	MGPIO_SetMode(PORTA,PIN6,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN6,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	/* PORTA Pin 7 is output pin */
	MGPIO_SetMode(PORTA,PIN7,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN7,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);


	/* PORTB Pin 0 is output pin */
	MGPIO_SetMode(PORTB,PIN0,INPUT_RESET_STATE);
	MGPIO_SetInputPinMode(PORTB,PIN0,PULL_DOWN);
	while(1)
	{
		MGPIO_GetPinValue(PORTB,PIN0,&pin_value1);
		MGPIO_GetPinValue(PORTB,PIN1,&pin_value2);
		if(pin_value1==1 && flag1==1){
			value|=(1<<i);
			if(i==8)
			{
				MGPIO_SetPortValue(PORTA,255);
			}
			else
			{
				MGPIO_SetPortValue(PORTA,value);
			}

			while(pin_value1==1)
			{
				MGPIO_GetPinValue(PORTB,PIN0,&pin_value1);
			}
			flag1=0;
			i++;
			if(i==9)
			{
				value=255;
				i=8;
			}

		}
		else if(pin_value1==0 && flag1==0 )
		{

			flag1=1;
		}


		if(pin_value2==1 && flag2==1){
			if(i>0){
				i--;
			}
			value&=~(1<<i);
			MGPIO_SetPortValue(PORTA,value);

			while(pin_value2==1)
			{
				MGPIO_GetPinValue(PORTB,PIN1,&pin_value2);
			}
			flag2=0;
			if(i==0)
			{
				value=0;
				i=0;
			}


		}
		else if(pin_value2==0 && flag2==0 )
		{

			flag2=1;
		}
	}
	return 0;
}
