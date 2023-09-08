/*******************************************************************************************/
/*  Module       :   EEPROM                                                                */
/*  File Name    :   EEPROM.c                                                              */
/*  Description  :   Source File of the EEPROM Driver                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   27/08/2023                                                            */
/*******************************************************************************************/

/* Application does not know how EEPROM will communicate so, we have this function
 * to initialize the I2C */
#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#define  F_CPU    8000000UL
#include <util/delay.h>
#include "..\..\MCAL\TWI\TWI.h"

#include "EEPROM.h"
#include "EEPROM_Private.h"
#include "EEPROM_Cfg.h"

#include "..\LCD\LCD.h"

static uint8 EEPROM_Private_u8ErrorStateCheck(TWI_ErrorState Copy_enuErrorState);

void EEPROM_voidInit(void){
	TWI_voidMasterInit();
}

uint8 EEPROM_u8WriteDataByte(uint8 Copy_u8Data,uint16 Copy_u16ByteAddress){
	uint8 Local_u8ErrorState = E_OK;
	TWI_ErrorState Local_enuTWIErrorState= TWI_OK;

	/* Send the Start Condition */
	Local_enuTWIErrorState = TWI_enuSendStartCondition();

	LCD_voidSendNumber(0,Local_enuTWIErrorState );
	/* Check the Error State */
//	Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);


	/* Send Slave Address With Write Operation */
	Local_enuTWIErrorState = TWI_enuSendSlaveAddressWithWrite( (EEPROM_FIXED_ADDRESS )                \
			                                                 | (EEPROM_A2_VALUE <<2)                  \
			                                                 | ((uint8)(Copy_u16ByteAddress>>8)));

	LCD_voidSendChar(0, ' ');
	LCD_voidSendNumber(0,Local_enuTWIErrorState );
	/* Check the Error State */
//	Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);

	/* Send The rest of the byte address */
	Local_enuTWIErrorState = TWI_enuSendData((uint8)(Copy_u16ByteAddress));


	LCD_voidSendChar(0, ' ');
	LCD_voidSendNumber(0,Local_enuTWIErrorState );
	/* Check the Error State */
//	Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);



	/* Send the byte data */
	Local_enuTWIErrorState = TWI_enuSendData(Copy_u8Data);

	LCD_voidSendChar(0, ' ');
	LCD_voidSendNumber(0,Local_enuTWIErrorState );
	/* Check the Error State */
//	Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);

	/* Send the stop condition */
	TWI_voidSendStopCondition();


	/* Delay 5 msec between the previous start and the new one */
	_delay_ms(10);

	/* Return the error state */
	return Local_u8ErrorState;
}

uint8 EEPROM_u8ReadDataByte(uint8 *Copy_pu8RecData,uint16 Copy_u16ByteAddress){
	uint8          Local_u8ErrorState     = E_OK;
	TWI_ErrorState Local_enuTWIErrorState = TWI_OK;

	uint8 Local_u8EEPROMAddress = (EEPROM_FIXED_ADDRESS )                \
                                | (EEPROM_A2_VALUE <<2)                  \
                                | ((uint8)(Copy_u16ByteAddress>>8));

	/* Check the pointer */
	if(Copy_pu8RecData != NULL_PTR){

		LCD_voidMoveCursor(0,1,0);

		/* Send the Start Condition */
		Local_enuTWIErrorState = TWI_enuSendStartCondition();


		LCD_voidSendNumber(0,Local_enuTWIErrorState );
		/* Check the Error State */
//		Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);


		/* Send Slave Address With Write Operation */
		Local_enuTWIErrorState = TWI_enuSendSlaveAddressWithWrite(Local_u8EEPROMAddress);


		LCD_voidSendChar(0, ' ');
		LCD_voidSendNumber(0,Local_enuTWIErrorState );
		/* Check the Error State */
//		Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);


		/* Send The rest of the byte address */
		Local_enuTWIErrorState = TWI_enuSendData((uint8)(Copy_u16ByteAddress));

		LCD_voidSendChar(0, ' ');
		LCD_voidSendNumber(0,Local_enuTWIErrorState );
		/* Check the Error State */
//		Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);

		/* Send the repeated start condition */
		Local_enuTWIErrorState = TWI_enuSendRepeatedStartCondition();


		LCD_voidSendChar(0, ' ');
		LCD_voidSendNumber(0,Local_enuTWIErrorState );
		/* Check the Error State */
//		Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);

		/* Send Slave Address with read operation */
		Local_enuTWIErrorState = TWI_enuSendSlaveAddressWithRead(Local_u8EEPROMAddress);


		LCD_voidSendChar(0, ' ');
		LCD_voidSendNumber(0,Local_enuTWIErrorState );
		/* Check the Error State */
//		Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);


		/* Read the data */
		Local_enuTWIErrorState = TWI_enuReceiveData(Copy_pu8RecData);


		LCD_voidSendChar(0, ' ');
		LCD_voidSendNumber(0,Local_enuTWIErrorState );
		/* Check the Error State */
//		Local_u8ErrorState = EEPROM_Private_u8ErrorStateCheck(Local_enuTWIErrorState);

		/* Send Stop Condition */
		TWI_voidSendStopCondition();
//		_delay_ms(10);

	}
	else
	{
		Local_u8ErrorState = E_NOT_OK;
	}






	return Local_u8ErrorState;
}



uint8 EEPROM_Private_u8ErrorStateCheck(TWI_ErrorState Copy_enuErrorState){
	uint8 Local_u8TWIErrorState= E_OK;
	if(Copy_enuErrorState != TWI_OK){
		Local_u8TWIErrorState = E_NOT_OK;
	}
	return Local_u8TWIErrorState;
}
