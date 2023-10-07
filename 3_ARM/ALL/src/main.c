//#include "../include/STD_Types.h"
//#include "../include/BIT_MATH.h"
//
//#include "../include/MRCC_Interface.h"
//
//#include "../include/MNVIC_Interface.h"
//
//#include "../include/HLEDMATIX_Interface.h"
//
//#include "../include/MGPIO_Interface.h"
//
//#include "../include/MSPI_Interface.h"
//
//#include "../include/MEXTI_Interface.h"
//
//#include "../include/MSPI_Interface.h"
//
//#include "../include/MSYSTICK_Interface.h"
//
//#include "../include/HTFT_Interface.h"
//
//
//
//#include "../include/HIR_Interface.h"
//
//
//
//
//int main()
//{
//	u8 loop=0;
//	u8 index=0;
//	/* Multi-dimensional */
//	u8 numbers[9][8]={{24, 140, 134, 255, 255, 128, 128, 0},
//	                  {0, 242, 146, 146, 146, 146, 158, 0},
//	                  {0, 146, 146, 146, 146, 146, 254, 0},
//	                  {48, 56, 44, 38, 35, 255, 32, 0},
//	                  {0, 158, 146, 146, 146, 146, 242, 0},
//	                  {0, 254, 146, 146, 146, 146, 242, 0},
//	                  {0, 130, 194, 98, 50, 26, 14, 0},
//	                  {0, 254, 146, 146, 146, 146, 254, 0},
//	                  {0, 158, 146, 146, 146, 146, 254, 0}};
//
//
//	/* Initialize System Clock*/
//	MRCC_Init();
//	/* Initialize the systick timer */
//	SYSTICK_voidInit();
//	/* Set the call back function of the systick timer */
//	SYSTICK_voidSetCallBack(GetData);
//	/* Enable the interrupt of the systick timer */
//	SYSTICK_voidCtrlIntState(0);
//
//	/* Initialize the clock of the GPIO A */
//	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
//	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
//	/* Initialize the clock of the */
//	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_SYSCFG);
//	/* Adjust the PIN8 in PORTA to be input */
//	MGPIO_SetMode(PORTA,PIN8,INPUT_RESET_STATE);
//	MGPIO_SetInputPinMode(PORTA,PIN10,PULL_UP);
//	/* Enable the NVIC enable of the external interrupt 0 */
//	/* External interrupt 8 is number 23 in the vector table */
//	MNVIC_VoidEnbleInterrupt(EXTINT_EXTI15_10_POSITION);
//
//
//	/* Set the call back of the external interrupt 0 */
//	MEXTI_voidSetCallBack(EXTI_LINE_10,GetFrame);
//	/* Adjust the External interrupt 0 pin */
//	MEXTI_voidInterruptSetPort(EXTI_LINE_10,PORTA_PIN);
//	/* Set the pin to detect the falling edge */
//	MEXTI_voidInterruptTrigger(EXTI_LINE_10,EXTI_FALLING_EDGE);
//	/* Enable the interrupt of the external interrupt 0*/
//	MEXTI_voidInterruptEnableDisable(EXTI_LINE_10,EXTI_ENABLE);
//
//
//
//	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_SPI1);
//	/* Pin Reset of the TFT is Output */
//	MGPIO_SetMode(PORTA,PIN8,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN8,OUTPUT_PUSH_PULL,OUTPUT_HIGH_SPEED_TYPE);
//
//	/* Pin A0 of the TFT is Output    */
//	MGPIO_SetMode(PORTA,PIN9,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN9,OUTPUT_PUSH_PULL,OUTPUT_HIGH_SPEED_TYPE);
//
//	/* Configure the SPI CLOCK and SPI MOSI and SPI NSS */
//	/* SPI1 Clock Pin                                   */
//	MGPIO_SetMode(PORTA,PIN5,ALTERNATE_FUNCTION_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN5,OUTPUT_PUSH_PULL,OUTPUT_VERY_HIGH_SPEED_TYPE);
//	MGPIO_SetAlternativeFuncPin(PORTA,PIN5,AF5_SPI1_SPI2_I2S2_SPI3_I2S3_SPI4);
//	/* SPI1 Data Pin                                    */
//	MGPIO_SetMode(PORTA,PIN7,ALTERNATE_FUNCTION_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN7,OUTPUT_PUSH_PULL,OUTPUT_VERY_HIGH_SPEED_TYPE);
//	MGPIO_SetAlternativeFuncPin(PORTA,PIN7,AF5_SPI1_SPI2_I2S2_SPI3_I2S3_SPI4);
//	/* SPI1 NSS Pin                                     */
//	MGPIO_SetMode(PORTA,PIN4,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN4,OUTPUT_PUSH_PULL,OUTPUT_HIGH_SPEED_TYPE);
//
//
//	MSPI1_voidInit();
//	HTFT_voidInitialize();
//
//
//
//	/* Initialize the led matrix */
//	HLEDMATRIX_voidInit();
//	while(1)
//	{
//		if(data == HIR_INCREMENT_DATA){
//			data =0;
//			index++;
//			if(index==9)
//			{
//				index=0;
//			}
//
//		}
//		if(data == HIR_DECREMENT_DATA){
//			data=0;
//			if(index==0)
//			{
//				index=8;
//			}
//			else
//			{
//				index--;
//			}
//
//		}
//		for(loop=0;loop<5;loop++)
//		{
//			HLEDMATRIX_voidDisplay(numbers[index]);
//		}
//
//		if(data == HIR_ONE_DATA)
//		{
//			data=0;
//			HTFT_DisplayImage(number1);
//		}
//		if(data == HIR_TWO_DATA)
//		{
//			data=0;
//			HTFT_DisplayImage(number2);
//		}
//		if(data == HIR_THREE_DATA)
//		{
//			data=0;
//			HTFT_DisplayImage(number3);
//		}
//		if(data == HIR_FOUR_DATA)
//		{
//			data=0;
//			HTFT_DisplayImage(number4);
//		}
//
//
//
//	}
//	return 0;
//}
