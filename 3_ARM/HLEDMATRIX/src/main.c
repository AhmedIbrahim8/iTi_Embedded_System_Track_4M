#include "../include/MSYSTICK_Interface.h"
#include "../include/HLEDMATIX_Interface.h"
#include "../include/MRCC_Interface.h"

u8 Array_AHMED[]  = {124, 18, 18, 124, 0, 126, 8, 8, 126, 0, 0, 126, 4, 8, 4, 126, 0, 0, 126, 74, 74, 74, 0, 0, 126, 66, 36, 24, 0, 0};
u8 Array_AHMED2[] = {0,0,0,0,0,0,124, 18, 18, 124, 0, 126, 8, 8, 126, 0, 0, 126, 4, 8, 4, 126, 0, 0, 126, 74, 74, 74, 0, 0, 126, 66, 36, 24, 0, 0};
u8 array_A[8] ={0, 124, 18, 18, 18, 124, 0, 0};
u8 array[8] ={255,255,255,255,255,255,255,255};

int main(){
	u32 i=0;
	u32 j=0;
	SYSTICK_voidInit();
	MRCC_Init();

	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);

	HLEDMATRIX_voidInit();
	while(1)
	{
//		for(i=0;i<50;i++){
//			HLEDMATRIX_voidDisplay(array);
//		}
//		for(i=0;i<50;i++){
//			HLEDMATRIX_voidDisplay(array_A);
//		}
		for(i=0;i<30-8;i++)
		{
			/* 50 FPS -------->  2500 usec */
			/* HLEDMATRIX_voidDisplay(Array_AHMED+i) will have an execute time = 20 msec
			 * 2500usec * 8 = 20 msec
			 *
			 * function = 20 msec
			 * desired  = 0.5 sec
			 * function repeated every ?
			 * no. of repeated = 500/20 = 25 times
			 * */
			/* Execution time of inner for loop =
			 *         25 * 20mec = 0.5 second
			 * ex : i=30
			 *         HLEDMATRIX_voidDisplay(Array_AHMED + 29); // Access out range of the array elements
			 *   HLEDMATRIX_voidDisplay(Array_AHMED+i);
			 *
			 *         */
			for(j=0;j<25;j++){
				HLEDMATRIX_voidDisplay(Array_AHMED+i);
			}

//			SYSTICK_voidDelayUs(DELAY_VALUE);

		}
//		for(i=0;i<36-8;i++)
//		{
//			HLEDMATRIX_voidDisplay(Array_AHMED2+i);
////			SYSTICK_voidDelayUs(DELAY_VALUE);
//
//		}


	}
}
