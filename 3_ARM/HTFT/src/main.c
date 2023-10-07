/*************************************************************************************/
/****************************** Included Libraries ***********************************/
/*************************************************************************************/
#include "..\include\STD_Types.h"
#include "..\include\BIT_MATH.h"

/*************************************************************************************/
/******************************** Included Drivers ***********************************/
/*************************************************************************************/
#include "..\include\MRCC_Interface.h"
#include "..\include\MGPIO_Interface.h"
#include "..\include\MSYSTICK_Interface.h"
#include "..\include\HTFT_Interface.h"

#include "..\include\MSPI_Interface.h"



int main(){
	MRCC_Init();
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_SPI1);

	/* Pin Reset of the TFT is Output */
	MGPIO_SetMode(PORTA,PIN8,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN8,OUTPUT_PUSH_PULL,OUTPUT_HIGH_SPEED_TYPE);

	/* Pin A0 of the TFT is Output    */
	MGPIO_SetMode(PORTA,PIN9,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN9,OUTPUT_PUSH_PULL,OUTPUT_HIGH_SPEED_TYPE);

	/* Configure the SPI CLOCK and SPI MOSI and SPI NSS */
	/* SPI1 Clock Pin                                   */
	MGPIO_SetMode(PORTA,PIN5,ALTERNATE_FUNCTION_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN5,OUTPUT_PUSH_PULL,OUTPUT_VERY_HIGH_SPEED_TYPE);
	MGPIO_SetAlternativeFuncPin(PORTA,PIN5,AF5_SPI1_SPI2_I2S2_SPI3_I2S3_SPI4);
	/* SPI1 Data Pin                                    */
	MGPIO_SetMode(PORTA,PIN7,ALTERNATE_FUNCTION_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN7,OUTPUT_PUSH_PULL,OUTPUT_VERY_HIGH_SPEED_TYPE);
	MGPIO_SetAlternativeFuncPin(PORTA,PIN7,AF5_SPI1_SPI2_I2S2_SPI3_I2S3_SPI4);
	/* SPI1 NSS Pin                                     */
	MGPIO_SetMode(PORTA,PIN4,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN4,OUTPUT_PUSH_PULL,OUTPUT_HIGH_SPEED_TYPE);
//	MGPIO_SetAlternativeFuncPin(PORTA,PIN4,AF5_SPI1_SPI2_I2S2_SPI3_I2S3_SPI4);

	SYSTICK_voidInit();
	MSPI1_voidInit();
	HTFT_voidInitialize();
	HTFT_DisplayImage(Image);
	SYSTICK_voidDelayMs(1000);
	HTFT_FillColor(0xF0F0);
	SYSTICK_voidDelayMs(1000);
	HTFT_DrawShape(50,100,50,100,0);

	while(1);
}
