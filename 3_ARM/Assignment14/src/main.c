#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/MSYSTICK_Interface.h"
#include "../include/HLEDMATIX_Interface.h"
#include "../include/MRCC_Interface.h"
#include "../include/MGPIO_Interface.h"
//
//u8 Array_AHMED[]  = {124, 18, 18, 124, 0, 126, 8, 8, 126, 0, 0, 126, 4, 8, 4, 126, 0, 0, 126, 74, 74, 74, 0, 0, 126, 66, 36, 24, 0, 0};
//u8 Array_AHMED2[] = {0,0,0,0,0,0,124, 18, 18, 124, 0, 126, 8, 8, 126, 0, 0, 126, 4, 8, 4, 126, 0, 0, 126, 74, 74, 74, 0, 0, 126, 66, 36, 24, 0, 0};
//u8 array_A[8] ={0, 124, 18, 18, 18, 124, 0, 0};
//u8 array[8] ={255,255,255,255,255,255,255,255};

/* Multi-dimensional */
u8 numbers[9][8]={{24, 140, 134, 255, 255, 128, 128, 0},
                  {0, 242, 146, 146, 146, 146, 158, 0},
                  {0, 146, 146, 146, 146, 146, 254, 0},
                  {48, 56, 44, 38, 35, 255, 32, 0},
                  {0, 158, 146, 146, 146, 146, 242, 0},
                  {0, 254, 146, 146, 146, 146, 242, 0},
                  {0, 130, 194, 98, 50, 26, 14, 0},
                  {0, 254, 146, 146, 146, 146, 254, 0},
                  {0, 158, 146, 146, 146, 146, 254, 0}};

int main(){
	u32 i=0;
	u32 j=0;
	u8 pin_value1=0;
	u8 flag1=1;
	u8 pin_value2=0;
	u8 flag2=1;
	u8 index=0;
	SYSTICK_voidInit();
	MRCC_Init();

	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);



	MGPIO_SetMode(PORTA,PIN8,INPUT_RESET_STATE);
	MGPIO_SetInputPinMode(PORTA,PIN8,PULL_DOWN);
	MGPIO_SetMode(PORTA,PIN9,INPUT_RESET_STATE);
	MGPIO_SetInputPinMode(PORTA,PIN9,PULL_DOWN);

	HLEDMATRIX_voidInit();
	HLEDMATRIX_voidDisplay(numbers[0]);

	while(1)
	{
		MGPIO_GetPinValue(PORTA,PIN8,&pin_value1);
		MGPIO_GetPinValue(PORTA,PIN9,&pin_value2);
		if(pin_value1==1 && flag1==1){
			index++;
			if(index==9)
			{
				index=0;
			}
			while(pin_value1==1)
			{
				MGPIO_GetPinValue(PORTA,PIN8,&pin_value1);
			}
			flag1=0;
		}
		else if(pin_value1==0 && flag1==0 )
		{

			flag1=1;
		}
		if(pin_value2==1 && flag2==1){
			if(index==0)
			{
				index=8;
			}
			else{
				index--;
			}
			while(pin_value2==1)
			{
				MGPIO_GetPinValue(PORTA,PIN9,&pin_value2);
			}
			flag2=0;
		}
		else if(pin_value2==0 && flag2==0 )
		{

			flag2=1;
		}

		HLEDMATRIX_voidDisplay(numbers[index]);

	}
}
