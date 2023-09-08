//#include "..\..\..\LIB\Std_Types.h"
//#include "..\..\..\LIB\common_macros.h"
//#include "..\..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
//#include "..\..\..\MCAL\Timer0\Timer0.h"
//#include "..\..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
//
//void App_voidPwm50Hz(){
//	static uint8 counter=0;
//	counter++;
//	if(counter==8){
//		DIO_enuWritePin(DIO_PIN_NUM_A0, LEVEL_LOW);
//	}
//	else if(counter==80){
//		DIO_enuWritePin(DIO_PIN_NUM_A0, LEVEL_HIGH);
//		counter=0;
//	}
//}
//
//int main(){
//	DIO_Init();
//	GI_voidEnable();
//	TIMER0_voidEnableCompareINT();
//	TIMER0_voidTimer0CMPSetCallBack(App_voidPwm50Hz);
//	TIMER0_voidSetTCNTValue(0);
//	TIMER0_voidSetOCRValue(250);
//	TIMER0_voidTimer0_Init();
//	DIO_enuWritePin(DIO_PIN_NUM_A0, LEVEL_HIGH);
//	TIMER0_voidEnable(TIMER0_CLK_8);
//	while(1);
//
//	return 0;
//}
