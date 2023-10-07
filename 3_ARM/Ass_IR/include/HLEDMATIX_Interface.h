/*
 * HLEDMATIX_Interface.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Ahmed
 */

#ifndef HLEDMATIX_INTERFACE_H_
#define HLEDMATIX_INTERFACE_H_

#define   DELAY_VALUE                   2500UL
void HLEDMATRIX_voidInit();
void HLEDMATRIX_voidDisableCols(void);

void HLEDMATRIX_voidSetRowValue(u8 Copy_u8ColumnValue);

void HLEDMATRIX_voidDisplay(u8 *Copy_u8arr);

#endif /* HLEDMATIX_INTERFACE_H_ */
