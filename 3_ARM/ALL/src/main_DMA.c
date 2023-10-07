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
//#include "../include/MDMA_Interface.h"
//
//void isr(void){
//	MGPIO_SetPinValue(PORTA,PIN0,PIN_LEVEL_HIGH);
//	SYSTICK_voidDelayMs(1000);
//}
//
//int main()
//{
//	u32 value1[4000]={0};
//	u32 value2[4000];
//
//	u32 value3[4000]={0};
//	u32 value4[4000];
//	u16 i=0;
//
//	for(i=0;i<4000;i++)
//	{
//		value1[i]=5;
//		value2[i]=10;
//	}
//	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_DMA2);
//
//
//	/* Initialize System Clock*/
//	MRCC_Init();
//
//	SYSTICK_voidInit();
//
//	/* Initialize the clock of the GPIO A */
//	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
//	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
//
//	MGPIO_SetMode(PORTA,PIN0,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetMode(PORTA,PIN1,GENRAL_PURPOSE_OUTPUT_MODE);
//
//
//	MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//	MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//
//
//
//
//	DMA2_Init();
//	DMA2_SetStreamConfiguration(DMA2_STREAM_0_SELECTED,DMA2_CHANNEL_0_SELECTED,value1,value3,32,4000);
//	DMA2_SetCallBack(DMA2_STREAM_0_SELECTED,isr);
//	MNVIC_VoidEnbleInterrupt(EXTINT_DMA2STREAM0_POSITION);
//
//
//	DMA2_EnbaleStream(DMA2_STREAM_0_SELECTED);
//	for(i=0;i<4000;i++)
//	{
//		value2[i]=value4[i];
//
//	}
//	MGPIO_SetPinValue(PORTA,PIN1,PIN_LEVEL_HIGH);
//
//	while(1){
//
//
//	}
//	return 0;
//}
