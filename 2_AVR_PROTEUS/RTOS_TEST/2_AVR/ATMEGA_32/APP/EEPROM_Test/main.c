//#include "..\..\LIB\Std_Types.h"
//#include "..\..\LIB\common_macros.h"
//
//
//#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
//
//#include "..\..\HAL\LCD\Lcd.h"
//#include "..\..\HAL\EEPROM\EEPROM.h"
//
//#include <util/delay.h>
//
//int main(){
//	uint8 error;
//	uint8 Local_u8Data=0;
//	DIO_Init();
//	LCD_voidInit();
//	EEPROM_voidInit();
//	LCD_voidClrScr(0);
//
//	EEPROM_u8WriteDataByte(50, 200);
//	error = EEPROM_u8ReadDataByte(&Local_u8Data, 200);
//
//	_delay_ms(1000);
//	LCD_voidClrScr(0);
//	LCD_voidMoveCursor(0,0,0);
//	LCD_voidSendNumber(0, Local_u8Data);
//
//	while(1){
//
//	}
//
//	return 0;
//}
