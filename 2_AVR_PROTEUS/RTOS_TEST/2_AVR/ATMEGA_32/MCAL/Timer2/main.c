//#include "..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
//#include "..\..\LIB\Std_Types.h"
//#include "..\DIO_DRIVER\Dio_Interface.h"
//#include "Timer2.h"
//#include "util/delay.h"
//void Toggle_led(){
//	static uint16 counter=0;
//	counter++;
//	if(counter==1){
//		DIO_enuWritePin(DIO_PIN_NUM_D7,LEVEL_LOW);
//	}
//	if(counter==2){
//		DIO_enuWritePin(DIO_PIN_NUM_D7,LEVEL_HIGH);
//		counter=0;
//	}
//
//}
//int main(){
//	DIO_Init();
//	GI_voidEnable();
//	TIMER2_voidTimer2_Init();
//	TIMER2_voidSetTCNTValue(0);
//	TIMER2_voidSetOCRValue(128);
//	//TIMER2_voidEnableOvfINT();
//	//TIMER2_voidTimer2OVFSetCallBack(Toggle_led);
//	TIMER2_voidEnable(TIMER2_CLK_128);
//
//	while(1){
//
//	}
//}
