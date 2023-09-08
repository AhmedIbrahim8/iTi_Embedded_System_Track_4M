/*
 * EXT_INT.h
 *
 *  Created on: Aug 11, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_DRIVER_EXT_INT_H_
#define MCAL_EXTERNAL_INTERRUPT_DRIVER_EXT_INT_H_
#include "EXT_INT_Types.h"
#include "..\..\LIB\Std_Types.h"
/* Macros Used in the External Interrupt Driver */

#define EXTERNAL_INT_0_INDEX               0
#define EXTERNAL_INT_1_INDEX               1
#define EXTERNAL_INT_2_INDEX               2


/* Function ProtoTypes */

void EXT_INT_Enable(uint8 ExtIntIndexCpy,EXT_INT_LevelType levelTypeCopy);
void EXT_INT_Disable(uint8 ExtIntIndexCpy);

/* Call back function */
void EXT_INT_SetCallBack(void (*EXT_INT_PfCpy)(void),uint8 ExtIntIndexCpy);
#endif /* MCAL_EXTERNAL_INTERRUPT_DRIVER_EXT_INT_H_ */
