//#include "..\..\LIB\Std_Types.h"
//#include "..\..\LIB\common_macros.h"
//#include "..\DIO_DRIVER\DIO_Interface.h"
//#include "..\..\HAL\LCD\Lcd.h"
//#include "ADC.h"
//#include "..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
//#include <util/delay.h>
//#include "ADC_Register.h"
//void sensor_lm35(){
//	static uint8 Temperature;
//	uint16 digital_value = ADC_u16ReadAsync();
//	Temperature= ((digital_value*500UL)/(uint16)1024);
//	LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Temp = ");
//	LCD_voidSendNumber(0,Temperature);
//}
//
//int main(){
//
//	uint8 Temperature;
//	uint16 digital;
//	DIO_Init();
//	LCD_voidInit();
//	ADC_voidInit();
//	ADC_voidEnable();
//	GI_voidEnable();
//	/* Polling Method */
////	while(1){
////		digital = ADC_u16ReadSync(0);
////		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"digit = ");
////		LCD_voidSendNumber(0,digital);
////		Temperature= ((digital*500UL)/(uint16)1024);
////		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"Temp = ");
////		LCD_voidSendNumber(0,Temperature);
////
////		_delay_ms(1000);
////
////	}
//	ADC_voidEnableInterrupt();
//	ADC_voidSetCallback(&sensor_lm35);
//
//	while(1){
//		ADC_voidStartConversion(0);
//		_delay_ms(5000);
//	}
//
///* analog = digital * step      (5/1024)
// * analog = (digial * 5 ) / 1024
// * 1c --------> 10mv
// * temp -------> analog
// *
// * temp = (analog *1)/10mv
// * temp = ((digital *5) /1024)/10mv
// * */
//
//}
//
//
