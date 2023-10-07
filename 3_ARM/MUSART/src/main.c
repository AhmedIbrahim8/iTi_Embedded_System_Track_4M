#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/MGPIO_Interface.h"
#include "../include/MRCC_Interface.h"
#include "../include/MSYSTICK_Interface.h"
#include "../include/MUSART_Interface.h"



int main()
{
	char tx[] = {'A'};
	char rx[1];
	MRCC_Init();
	SYSTICK_voidInit();

	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_USART1);

	/* USART 1 TX is at PIN 9 */
	MGPIO_SetMode(PORTA,PIN9,ALTERNATE_FUNCTION_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN9,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);

	/* USART 1 RX is at PIN 10 */
	MGPIO_SetMode(PORTA,PIN10,ALTERNATE_FUNCTION_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN10,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);

	MUSART_voidInit();
	MUSART_voidEnable();

	while(1)
	{
		MUSART_voidTransmit(tx,1);
		SYSTICK_voidDelayMs(500);
		tx[0]='B';
		MUSART_voidTransmit(tx,1);
		SYSTICK_voidDelayMs(500);
		tx[0]='A';
	}


}
