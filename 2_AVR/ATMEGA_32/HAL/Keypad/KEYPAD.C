/*******************************************************************************************/
/*  Module       :   Keypad                                                                */
/*  File Name    :   Keypad.c                                                              */
/*  Description  :   Source File of the Keypad Driver                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   10/08/2023                                                            */
/*******************************************************************************************/
#include "..\..\LIB\Std_Types.h"
#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include "Keypad.h"
/* Function Responsible of initializing the Keypad */
void KPD_voidInit(uint8 u8keyPadIndex){
	uint8 cols[KEYPAD_COL_NUM]=KEYPAD1_COL_PINS;
	uint8 rows[KEYPAD_ROW_NUM]=KEYPAD1_ROW_PINS;
	uint8 counter;
	for(counter=0;counter<KEYPAD_COL_NUM;counter++){
		DIO_enuWritePin(cols[counter],LEVEL_HIGH);
	}
	for(counter=0;counter<KEYPAD_ROW_NUM;counter++){
		DIO_enuStatePullup(rows[counter],PULL_UP);
	}
}

uint8 KPD_u8GetPressedKey(uint8 u8keyPadIndex){
	uint8 u8key=KEYPAD_NOT_PRESSED;
	uint8 u8readValue=1;
	uint8 row;
	uint8 col;
	/* Looping to the columns of the keypad */
	for(col=0;col<KEYPAD_COL_NUM;col++){
		/* Initialize specific column at the col variable to be zero to
		 * make a pull up switch */
		DIO_enuWritePin(keypad_config[u8keyPadIndex].keypad_cols[col],LEVEL_LOW);
		/* Looping to the rows of the keypad*/
		for(row=0;row<KEYPAD_ROW_NUM;row++){
			/* Read Pin value at the specific row at the row variable  */
			DIO_enuReadPin(keypad_config[u8keyPadIndex].keypad_rows[row],&u8readValue);
			/* If the readed value is low so, the user pressed the key  */
			if(u8readValue==LEVEL_LOW){
				/* get the pressed key from the configuration of the structure at
				 * specific row and col */
				u8key=keypad_config[u8keyPadIndex].keypad_content[row][col];
				/* Loop till user release the key */
				while(u8readValue==LEVEL_LOW){
					/* continue check and read the pin till user release his finger */
					DIO_enuReadPin(keypad_config[u8keyPadIndex].keypad_rows[row],&u8readValue);
				}
				/* Before returning the key, you must make the pin logic high for the second
				 * call of the function */
				DIO_enuWritePin(keypad_config[u8keyPadIndex].keypad_cols[col],LEVEL_HIGH);
				return u8key;
			}

		}
		DIO_enuWritePin(keypad_config[u8keyPadIndex].keypad_cols[col],LEVEL_HIGH);
	}
	u8key=KEYPAD_NOT_PRESSED;
	return u8key;
}



