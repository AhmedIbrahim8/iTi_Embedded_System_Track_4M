//#include "..\..\LIB\Std_Types.h"
//#include "..\..\LIB\common_macros.h"
//
//#include "..\..\ServiceLayer\RTO\RTO_Interface.h"
//
//#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
//
//
//void Task1 (void){
//	static uint8 Local_u8Flag=0;
//	if(Local_u8Flag == 0 ){
//		DIO_enuWritePin(0, LEVEL_HIGH);
//		Local_u8Flag = 1;
//	}
//	else{
//		DIO_enuWritePin(0, LEVEL_LOW);
//		Local_u8Flag = 0;
//	}
//}
//
//void Task2 (void){
//	static uint8 Local_u8Flag=0;
//	if(Local_u8Flag == 0 ){
//		DIO_enuWritePin(1, LEVEL_HIGH);
//		Local_u8Flag = 1;
//	}
//	else{
//		DIO_enuWritePin(1, LEVEL_LOW);
//		Local_u8Flag = 0;
//	}
//
//}
//
//void Task3 (void){
//	static uint8 Local_u8Flag=0;
//	if(Local_u8Flag == 0 ){
//		DIO_enuWritePin(2, LEVEL_HIGH);
//		Local_u8Flag = 1;
//	}
//	else{
//		DIO_enuWritePin(2, LEVEL_LOW);
//		Local_u8Flag = 0;
//	}
//
//}
//
//
//int main(){
//	DIO_Init();
//	RTO_u8CreateTask(0, 1, 0, Task1);
//	RTO_u8CreateTask(1, 2, 0, Task2);
//	RTO_u8CreateTask(2, 5, 0, Task3);
//	RTO_voidInit();
//	while(1){
//
//	}
//
//
//
//}
