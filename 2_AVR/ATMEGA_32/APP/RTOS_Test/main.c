//#include "..\..\LIB\Std_Types.h"
//#include "..\..\LIB\common_macros.h"
//
//#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
//
//#include "..\..\ServiceLayer\FreeRTOS\FreeRTOS.h"
//#include "..\..\ServiceLayer\FreeRTOS\task.h"
//
//#define  TASK_1_PRIORITY         1
//#define  TASK_2_PRIORITY         2
//#define  TASK_3_PRIORITY         4
//
//
//void App_voidTask1(void * Copy_Pv);
//void App_voidTask2(void * Copy_Pv);
//void App_voidTask3(void * Copy_Pv);
//
//int main(){
//	DIO_Init();
//
//	/* Create Tasks */
//	/* Create Task 1 : Toggle Led Every 1 Second */
//	xTaskCreate(App_voidTask1,
//			    NULL_PTR,
//				configMINIMAL_STACK_SIZE,
//				NULL_PTR,
//				TASK_1_PRIORITY,
//				NULL_PTR);
//	/* Create Task 2 : Toggle Led Every 2 Second */
//	xTaskCreate(App_voidTask2,
//			    NULL_PTR,
//				configMINIMAL_STACK_SIZE,
//				NULL_PTR,
//				TASK_2_PRIORITY,
//				NULL_PTR);
//	/* Create Task 3 : Toggle Led Every 3 Second */
//	xTaskCreate(App_voidTask3,
//			    NULL_PTR,
//				configMINIMAL_STACK_SIZE,
//				NULL_PTR,
//				TASK_3_PRIORITY,
//				NULL_PTR);
//	/* Start the scheduler */
//	vTaskStartScheduler();
//	while(1){
//
//
//	}
//}
//
//
//
//void App_voidTask1(void * Copy_Pv)
//{
//	static uint8 Local_u8Flag=0;
//	while(1){
//
//			if(Local_u8Flag == 0 ){
//				DIO_enuWritePin(0, LEVEL_HIGH);
//				Local_u8Flag = 1;
//			}
//			else{
//				DIO_enuWritePin(0, LEVEL_LOW);
//				Local_u8Flag = 0;
//			}
//		vTaskDelay(1000);
//	}
//}
//
//
//
//
//void App_voidTask2(void * Copy_Pv)
//{
//	static uint8 Local_u8Flag=0;
//	while(1){
//
//			if(Local_u8Flag == 0 ){
//				DIO_enuWritePin(1, LEVEL_HIGH);
//				Local_u8Flag = 1;
//			}
//			else{
//				DIO_enuWritePin(1, LEVEL_LOW);
//				Local_u8Flag = 0;
//			}
//		vTaskDelay(2000);
//	}
//}
//
//
//
//
//void App_voidTask3(void * Copy_Pv)
//{
//	static uint8 Local_u8Flag=0;
//	while(1){
//
//			if(Local_u8Flag == 0 ){
//				DIO_enuWritePin(2, LEVEL_HIGH);
//				Local_u8Flag = 1;
//			}
//			else{
//				DIO_enuWritePin(2, LEVEL_LOW);
//				Local_u8Flag = 0;
//			}
//		vTaskDelay(3000);
//	}
//}
