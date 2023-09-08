#include "Std_Types.h"
#include "common_macros.h"
#include "DIO_Interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#define  TASK_1_PRIORITY         3
#define  TASK_2_PRIORITY         3

#define  TASK_3_PRIORITY         4


void App_voidTask1(void * Copy_Pv);
void App_voidTask2(void * Copy_Pv);
//void App_voidTask3(void * Copy_Pv);

/* Create Global Variable of semaphore type */
xSemaphoreHandle App_ButtonSemph;

int main(){
	DIO_Init();
	/* Create Semaphore control block */
	vSemaphoreCreateBinary(App_ButtonSemph);
	xSemaphoreTake(App_ButtonSemph,portMAX_DELAY);
	/* Create Tasks */
	xTaskCreate(App_voidTask1,
			    NULL_PTR,
				200,
				NULL_PTR,
				TASK_1_PRIORITY,
				NULL_PTR);
	xTaskCreate(App_voidTask2,
			    NULL_PTR,
				200,
				NULL_PTR,
				TASK_2_PRIORITY,
				NULL_PTR);
//	/* Create Task 3 : Toggle Led Every 3 Second */
//	xTaskCreate(App_voidTask3,
//			    NULL_PTR,
//				200,
//				NULL_PTR,
//				TASK_3_PRIORITY,
//				NULL_PTR);
	/* Start the scheduler */
	vTaskStartScheduler();
	while(1){


	}
}



/* Task to check the button */
void App_voidTask1(void * Copy_Pv)
{
	while(1){
		if(PORTA & (1<<1)){
			xSemaphoreGive(App_ButtonSemph);
			vTaskDelay(20);
		}

	}

}



/* Task to toggle led based on button */

void App_voidTask2(void * Copy_Pv)
{
	while(1){
		if(xSemaphoreTake(App_ButtonSemph,portMAX_DELAY) == pdTRUE){
			PORTA ^=(1<<0);
		//	xSemaphoreGive(App_ButtonSemph);
			vTaskDelay(10);
		}

	}
}



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
