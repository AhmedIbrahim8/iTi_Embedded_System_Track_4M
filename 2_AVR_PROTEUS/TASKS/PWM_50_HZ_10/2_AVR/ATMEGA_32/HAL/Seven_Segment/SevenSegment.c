/*******************************************************************************************/
/*  Module       :   Seven Segement                                                        */
/*  File Name    :   SevenSegment.c                                                        */
/*  Description  :   File contains the Definitions of the functions used                   */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   06/08/2023                                                            */
/*******************************************************************************************/

#include "..\..\LIB\Std_Types.h"
#include "SevenSegment.h"
#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include "..\..\LIB\common_macros.h"

static void SEV_HexToBinary(uint8 SEV_Index,uint8 HexNum);

void SEV_Write(uint8 SEV_Index,uint8 number){
	uint8 value[10]={0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	if(number<10){
		SEV_HexToBinary(SEV_Index,value[number]);
	}
	else{

	}
}
void SEV_Enable(uint8 SEV_Index){
	if(SEV_Index < NUMBER_OF_LCDS)
	{
		if(SEV_Configuration[SEV_Index].type==COMMON_ANODE){
			DIO_enuWritePin(SEV_Configuration[SEV_Index].enablePinIndex,LEVEL_HIGH);
		}
		else if(SEV_Configuration[SEV_Index].type==COMMON_CATHODE){
			DIO_enuWritePin(SEV_Configuration[SEV_Index].enablePinIndex,LEVEL_LOW);
		}
		else{

		}
	}
	else{

	}
}
void SEV_Disable(uint8 SEV_Index){
	if(SEV_Index < NUMBER_OF_LCDS)
	{
		if(SEV_Configuration[SEV_Index].type==COMMON_ANODE){
			DIO_enuWritePin(SEV_Configuration[SEV_Index].enablePinIndex,LEVEL_LOW);
		}
		else if(SEV_Configuration[SEV_Index].type==COMMON_CATHODE){
			DIO_enuWritePin(SEV_Configuration[SEV_Index].enablePinIndex,LEVEL_HIGH);
		}
		else{

		}
	}
	else{

	}
}


static void SEV_HexToBinary(uint8 SEV_Index,uint8 HexNum){
	uint8 counter;
	uint8 binary[7];
	if(SEV_Configuration[SEV_Index].type==COMMON_CATHODE){
		for(counter=0;counter<7;counter++){
			binary[counter]=GET_BIT(HexNum,counter);
		}
		DIO_enuWriteGroup(SEV_Configuration[SEV_Index].ConnectionPins,binary,7);
	}
	else if(SEV_Configuration[SEV_Index].type==COMMON_ANODE){
		for(counter=0;counter<7;counter++){
			binary[counter]=!GET_BIT(HexNum,counter);
		}
		DIO_enuWriteGroup(SEV_Configuration[SEV_Index].ConnectionPins,binary,7);
	}
	else{

	}
}
