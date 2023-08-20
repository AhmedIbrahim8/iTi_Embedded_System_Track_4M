#include "..\..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include "..\..\..\HAL\Seven_Segment\SevenSegment.h"
#include "..\..\..\LIB\Std_Types.h"
#include <util/delay.h>
/*
int main(){
	uint8 number=0;
	DIO_Init();
	SEV_Enable(SEV1_INDEX_NUMBER );
	while(1){
		SEV_Write(SEV1_INDEX_NUMBER ,number);
		_delay_ms(5000);
		number++;
		if(number==10){
			number=0;
		}
	}
}
*/
