/*
 * SPI.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Ahmed
 */

#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "SPI.h"
#include "SPI_Registers.h"


void SPI_voidInit(void)
{
#if SPI_MODE == SPI_MASTER_MODE
	SPCR = (SPCR & 0x00) | \
			(SPI_INTERRUPT<<SPIE)        |\
			(SPI_ENABLE_DISABLE<<SPE)    |\
			(SPI_DATA_ORDER<<DORD)       |\
			(SPI_MODE<<MSTR)             |\
			(SPI_CLOCK_POLARITY<<CPOL)   |\
			(SPI_CLOCK_PHASE<<CPHA)      |\
			((SPI_CLOCK & 0x03));
	SPSR = (SPSR & 0xFE) | ((SPI_CLOCK_PHASE & 0x04) >>2);
#elif SPI_MODE == SPI_SLAVE_MODE
	SPCR = (SPCR & 0x00) | \
			(SPI_INTERRUPT<<SPIE)        |\
			(SPI_ENABLE_DISABLE<<SPE)    |\
			(SPI_DATA_ORDER<<DORD)       |\
			(SPI_MODE<<MSTR)             |\
			(SPI_CLOCK_POLARITY<<CPOL)   |\
			(SPI_CLOCK_PHASE<<CPHA);
#else

	#error "Not valid Mode "
#endif
}

tenuErrorStatus SPI_u8TransmitReceive(uint8 Copy_u8DataType,uint8 *Copy_pu8ReceivedData)
{
	tenuErrorStatus Local_enuErrorState=ENOK;
	if(Copy_pu8ReceivedData != NULL_PTR){
		/* Send Data Byte */
		SPDR = Copy_u8DataType;
		/* Check the flag */
		while((GET_BIT(SPSR,SPIF))==0);
		/* Read the Tnput Data */
		*Copy_pu8ReceivedData = SPDR;
		Local_enuErrorState=EOK;
	}
	else{

	}
	return Local_enuErrorState;
}
