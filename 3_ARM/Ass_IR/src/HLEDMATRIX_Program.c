/*
 * HLEDMATRIX_Program.c
 *
 *  Created on: Sep 24, 2023
 *      Author: Ahmed
 */
#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/MGPIO_Interface.h"
#include "../include/MSYSTICK_Interface.h"

#include "../include/HLEDMATIX_Interface.h"
#include "../include/HLEDMATRIX_Config.h"
#include "../include/HLEDMATRIX_Private.h"



void HLEDMATRIX_voidInit()
{
	/* Adjust the Row Pins Configuration */
	MGPIO_SetMode(LED_MATRIX_ROW0_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_ROW1_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_ROW2_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_ROW3_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_ROW4_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_ROW5_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_ROW6_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_ROW7_PIN,GENRAL_PURPOSE_OUTPUT_MODE);

	MGPIO_SetOutputPinMode(LED_MATRIX_ROW0_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_ROW1_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_ROW2_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_ROW3_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_ROW4_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_ROW5_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_ROW6_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_ROW7_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);

	/* Adjust the Row Pins Configuration */
	MGPIO_SetMode(LED_MATRIX_COL0_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_COL1_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_COL2_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_COL3_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_COL4_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_COL5_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_COL6_PIN,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetMode(LED_MATRIX_COL7_PIN,GENRAL_PURPOSE_OUTPUT_MODE);

	MGPIO_SetOutputPinMode(LED_MATRIX_COL0_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_COL1_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_COL2_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_COL3_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_COL4_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_COL5_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_COL6_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetOutputPinMode(LED_MATRIX_COL7_PIN,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);



}










void HLEDMATRIX_voidDisableCols(void)
{
	MGPIO_SetPinValue(LED_MATRIX_COL0_PIN,GPIO_PIN_LEVEL_HIGH);
	MGPIO_SetPinValue(LED_MATRIX_COL1_PIN,GPIO_PIN_LEVEL_HIGH);
	MGPIO_SetPinValue(LED_MATRIX_COL2_PIN,GPIO_PIN_LEVEL_HIGH);
	MGPIO_SetPinValue(LED_MATRIX_COL3_PIN,GPIO_PIN_LEVEL_HIGH);
	MGPIO_SetPinValue(LED_MATRIX_COL4_PIN,GPIO_PIN_LEVEL_HIGH);
	MGPIO_SetPinValue(LED_MATRIX_COL5_PIN,GPIO_PIN_LEVEL_HIGH);
	MGPIO_SetPinValue(LED_MATRIX_COL6_PIN,GPIO_PIN_LEVEL_HIGH);
	MGPIO_SetPinValue(LED_MATRIX_COL7_PIN,GPIO_PIN_LEVEL_HIGH);

}

void HLEDMATRIX_voidSetRowValue(u8 Copy_u8ColumnValue)
{
	MGPIO_SetPinValue(LED_MATRIX_ROW0_PIN,GET_BIT(Copy_u8ColumnValue,0));
	MGPIO_SetPinValue(LED_MATRIX_ROW1_PIN,GET_BIT(Copy_u8ColumnValue,1));
	MGPIO_SetPinValue(LED_MATRIX_ROW2_PIN,GET_BIT(Copy_u8ColumnValue,2));
	MGPIO_SetPinValue(LED_MATRIX_ROW3_PIN,GET_BIT(Copy_u8ColumnValue,3));
	MGPIO_SetPinValue(LED_MATRIX_ROW4_PIN,GET_BIT(Copy_u8ColumnValue,4));
	MGPIO_SetPinValue(LED_MATRIX_ROW5_PIN,GET_BIT(Copy_u8ColumnValue,5));
	MGPIO_SetPinValue(LED_MATRIX_ROW6_PIN,GET_BIT(Copy_u8ColumnValue,6));
	MGPIO_SetPinValue(LED_MATRIX_ROW7_PIN,GET_BIT(Copy_u8ColumnValue,7));


}

void HLEDMATRIX_voidDisplay(u8 *Copy_u8arr)
{
	HLEDMATRIX_voidDisableCols();
	HLEDMATRIX_voidSetRowValue(Copy_u8arr[0]);
	MGPIO_SetPinValue(LED_MATRIX_COL0_PIN,GPIO_PIN_LEVEL_LOW);
	SYSTICK_voidDelayUs(DELAY_VALUE);

	HLEDMATRIX_voidDisableCols();
	HLEDMATRIX_voidSetRowValue(Copy_u8arr[1]);
	MGPIO_SetPinValue(LED_MATRIX_COL1_PIN,GPIO_PIN_LEVEL_LOW);
	SYSTICK_voidDelayUs(DELAY_VALUE);

	HLEDMATRIX_voidDisableCols();
	HLEDMATRIX_voidSetRowValue(Copy_u8arr[2]);
	MGPIO_SetPinValue(LED_MATRIX_COL2_PIN,GPIO_PIN_LEVEL_LOW);
	SYSTICK_voidDelayUs(DELAY_VALUE);

	HLEDMATRIX_voidDisableCols();
	HLEDMATRIX_voidSetRowValue(Copy_u8arr[3]);
	MGPIO_SetPinValue(LED_MATRIX_COL3_PIN,GPIO_PIN_LEVEL_LOW);
	SYSTICK_voidDelayUs(DELAY_VALUE);


	HLEDMATRIX_voidDisableCols();
	HLEDMATRIX_voidSetRowValue(Copy_u8arr[4]);
	MGPIO_SetPinValue(LED_MATRIX_COL4_PIN,GPIO_PIN_LEVEL_LOW);
	SYSTICK_voidDelayUs(DELAY_VALUE);

	HLEDMATRIX_voidDisableCols();
	HLEDMATRIX_voidSetRowValue(Copy_u8arr[5]);
	MGPIO_SetPinValue(LED_MATRIX_COL5_PIN,GPIO_PIN_LEVEL_LOW);
	SYSTICK_voidDelayUs(DELAY_VALUE);

	HLEDMATRIX_voidDisableCols();
	HLEDMATRIX_voidSetRowValue(Copy_u8arr[6]);
	MGPIO_SetPinValue(LED_MATRIX_COL6_PIN,GPIO_PIN_LEVEL_LOW);
	SYSTICK_voidDelayUs(DELAY_VALUE);

	HLEDMATRIX_voidDisableCols();
	HLEDMATRIX_voidSetRowValue(Copy_u8arr[7]);
	MGPIO_SetPinValue(LED_MATRIX_COL7_PIN,GPIO_PIN_LEVEL_LOW);
	SYSTICK_voidDelayUs(DELAY_VALUE);
}
