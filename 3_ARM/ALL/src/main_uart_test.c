//#include "../include/STD_Types.h"
//#include "../include/BIT_MATH.h"
//
//#include "../include/MRCC_Interface.h"
//
//#include "../include/MNVIC_Interface.h"
//
//
//#include "../include/MGPIO_Interface.h"
//
//
//#include "../include/MSYSTICK_Interface.h"
//
//#include "../include/MUSART_Interface.h"
//
//
//
//int main()
//{
//	u8 counter=0;
//	u8 data[100];
//	/* Initialize System Clock*/
//	MRCC_Init();
//
//	SYSTICK_voidInit();
//
//	/* Initialize the clock of the GPIO A */
//	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
//	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
//
//
//
//	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_USART1);
//
//
//	MGPIO_SetMode(PORTA,PIN9,ALTERNATE_FUNCTION_MODE);
//	MGPIO_SetMode(PORTA,PIN10,ALTERNATE_FUNCTION_MODE);
//
//	MGPIO_SetAlternativeFuncPin(PORTA,PIN9,AF7_SPI3_I2S3_USART1_USART2);
//	MGPIO_SetAlternativeFuncPin(PORTA,PIN10,AF7_SPI3_I2S3_USART1_USART2);
//
//	MUSART_voidInit();
//
//	MUSART_voidEnable();
//
////	MUSART_voidTransmit(data,1);
////
////	while(1){
////		data[0]='A';
////		MUSART_voidTransmit(data,1);
////		SYSTICK_voidDelayMs(500);
////		data[0]='B';
////		MUSART_voidTransmit(data,1);
////		SYSTICK_voidDelayMs(500);
////	}
//
//
//
//	while(1)
//	{
//		for(counter=0;counter<50;counter++)
//		{
//			data[counter] = MUSART_u8Receive();
//			if(data == '\n')
//			{
//				break;
//			}
//		}
//
//	}
//	return 0;
//}
