/*
 * SPI.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_
#include "..\..\LIB\Std_Types.h"
#include "SPI_Types.h"
#include "SPI_Cfg.h"

void SPI_voidInit(void);

tenuErrorStatus SPI_u8TransmitReceive(uint8 Copy_u8DataType,uint8 *Copy_pu8ReceivedData);


#endif /* MCAL_SPI_SPI_H_ */
