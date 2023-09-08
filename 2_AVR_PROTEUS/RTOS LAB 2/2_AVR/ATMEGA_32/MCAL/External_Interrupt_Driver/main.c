#include "EXT_INT.h"
#include "..\Global_Interrupt_Enable_Driver\GIE.h"
#include "..\DIO_Driver\Dio_Interface.h"
#include "..\DIO_Driver\Dio_Registers.h"
#include "..\..\LIB\common_macros.h"

/*
void LED1(){
	TOGGLE_BIT(PORTA,0);

}
void LED2(){
	TOGGLE_BIT(PORTA,1);
}
void LED3(){
	TOGGLE_BIT(PORTA,2);
}
int main(){
	DIO_Init();
	GI_voidEnable();

	EXT_INT_SetCallBack(LED1,EXTERNAL_INT_0_INDEX);
	EXT_INT_SetCallBack(LED2,EXTERNAL_INT_1_INDEX);
	EXT_INT_SetCallBack(LED3,EXTERNAL_INT_2_INDEX);

	EXT_INT_Enable(EXTERNAL_INT_0_INDEX,RISING_EDGE);
	EXT_INT_Enable(EXTERNAL_INT_1_INDEX,RISING_EDGE);
	EXT_INT_Enable(EXTERNAL_INT_2_INDEX,RISING_EDGE);
	while(1){

	}
	return 0;
}
*/
