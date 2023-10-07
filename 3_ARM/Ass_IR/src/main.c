#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/MSYSTICK_Interface.h"
#include "../include/HLEDMATIX_Interface.h"
#include "../include/MRCC_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/HIR_Interface.h"
#include "../include/MEXTI_Interface.h"
#include "../include/MNVIC_Interface.h"


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

	u8 index=0;
	/* Initialize System Clock*/
	MRCC_Init();
	/* Initialize the systick timer */
	SYSTICK_voidInit();
	/* Set the call back function of the systick timer */
	SYSTICK_voidSetCallBack(GetData);
	/* Enable the interrupt of the systick timer */
	SYSTICK_voidCtrlIntState(1);

	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);

	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_SYSCFG);
	/* Adjust the PIN8 in PORTA to be input */
	MGPIO_SetMode(PORTA,PIN8,INPUT_RESET_STATE);
	MGPIO_SetInputPinMode(PORTA,PIN8,PULL_UP);
	/* Enable the NVIC enable of the external interrupt 8 */
	/* External interrupt 8 is number 23 in the vector table */
	MNVIC_VoidEnbleInterrupt(23);

	/* Set the call back of the external interrupt 0 */
	MEXTI_voidSetCallBack(EXTI_LINE_8,GetFrame);
	/* Adjust the External interrupt 0 pin */
	MEXTI_voidInterruptSetPort(EXTI_LINE_8,PORTA_PIN);
	/* Set the pin to detect the falling edge */
	MEXTI_voidInterruptTrigger(EXTI_LINE_8,EXTI_FALLING_EDGE);
	/* Enable the interrupt of the external interrupt 0*/
	MEXTI_voidInterruptEnableDisable(EXTI_LINE_8,EXTI_ENABLE);

//	HLEDMATRIX_voidInit();
//	HLEDMATRIX_voidDisplay(numbers[0]);

	while(1)
	{
//		if(data>=30 ){
//			index++;
//			if(index==9)
//			{
//				index=0;
//			}
//
//		}
//
//		else if(data < 30) {
//
//			if(index==0)
//			{
//				index=8;
//			}
//			else{
//				index--;
//			}
//
//		}

//		HLEDMATRIX_voidDisplay(numbers[index]);

	}
}
