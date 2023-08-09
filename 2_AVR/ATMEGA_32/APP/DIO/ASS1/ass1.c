#include "..\..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include "..\..\..\HAL\Seven_Segment\SevenSegment.h"
#include "..\..\..\LIB\Std_Types.h"
#include "..\..\..\HAL\LCD\Lcd.h"
#include <util/delay.h>


int main(){
	uint8 seconds;
	DIO_Init();
	LCD_voidInit();
	SEV_Enable(SEV1_INDEX_NUMBER);
	SEV_Enable(SEV2_INDEX_NUMBER);
	while (1){

		/* Green Led */
		for(seconds=11;seconds>=2;seconds--){
			LCD_voidClrScr(0);
			LCD_voidMoveCursor(0,1,1);
			LCD_voidSendNumber(0,seconds-1);
			SEV_Write(SEV1_INDEX_NUMBER ,(seconds-1)%10);
			SEV_Write(SEV2_INDEX_NUMBER ,(seconds-1)/10);
			DIO_enuWritePin(15,LEVEL_HIGH);
			_delay_ms(5000);
		}
		DIO_enuWritePin(15,LEVEL_LOW);
		/* Yellow Led */
		for(seconds=4;seconds>=2;seconds--){
			LCD_voidClrScr(0);
			LCD_voidMoveCursor(0,1,1);
			LCD_voidSendNumber(0,seconds-1);
			SEV_Write(SEV1_INDEX_NUMBER ,(seconds-1)%10);
			SEV_Write(SEV2_INDEX_NUMBER ,(seconds-1)/10);
			DIO_enuWritePin(14,LEVEL_HIGH);
			_delay_ms(5000);
		}
		DIO_enuWritePin(14,LEVEL_LOW);
		/* RED Led*/
		for(seconds=11;seconds>=2;seconds--){
			LCD_voidClrScr(0);
			LCD_voidMoveCursor(0,1,1);
			LCD_voidSendNumber(0,seconds-1);
			SEV_Write(SEV1_INDEX_NUMBER ,(seconds-1)%10);
			SEV_Write(SEV2_INDEX_NUMBER ,(seconds-1)/10);
			DIO_enuWritePin(13,LEVEL_HIGH);
			_delay_ms(5000);
		}
		DIO_enuWritePin(13,LEVEL_LOW);
	}

}

/*   RED      PORT B   PIN 13
 *   YELLOW   PORT B   PIN 14
 *   GREEN    PORT B   PIN 15 */
