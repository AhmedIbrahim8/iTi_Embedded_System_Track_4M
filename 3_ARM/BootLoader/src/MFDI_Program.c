/*******************************************************************************************/
/*  Module       :   Flash Driver Interface                                                              */
/*  File Name    :   MFDI_Program.c                                                         */
/*  Description  :   Header File of the FDI Program                          */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   30/09/2023                                                            */
/*******************************************************************************************/


#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"


#include "../include/MFDI_Private.h"
#include "../include/MFDI_Interface.h"
#include "../include/MFDI_Config.h"






/********************************************************************************************/
/************************************** APIs Definitions ************************************/
/********************************************************************************************/

/* Function Responsible for erasing specific sector in the flash memory
 * Copy_u8SectorNumber   :   Sector Number to be erased
 * */
void MFDI_voidSectorErase(MFDI_SectorType Copy_u8SectorNumber)
{
	/* Wait till Flash Driver ends its operation
     *     0 : no Flash memory operation ongoing
     *     1 : Flash memory operation ongoing
	 * */
	while(GET_BIT(MFDI->SR,BSY) == MFDI_NUMBER_ONE);

	/* Check If the Flash Driver is locked
	 * 1 : Locked
	 * 0 : UnLocked
	 * */
	/* If flash Driver is locked */
	if(GET_BIT(MFDI->CR,LOCK) == MFDI_NUMBER_ONE)
	{
		MFDI->KEYR = MFDI_KEY1;
		MFDI->KEYR = MFDI_KEY2;
	}
	/* Flash Driver is unlocked */
	else
	{
		/* DO No Thing */
	}
	/* Set Number of Sector to be erased in the CR Register
	 * We need to clear the bits responsible for the sector choose so, we
	 * anding the register with a MFDI_SECTOR_MASK then to adjust the sector
	 * number, we oring the Copy_u8SectorNumber shift left with the first bit of the bits
	 * */

	MFDI->CR = (MFDI->CR & MFDI_SECTOR_MASK) | (Copy_u8SectorNumber << SNB0);

	/* Set the end of the operation interrupt enable to give a responsive communication the
	 * operation of erasing is done
	 * 0: Interrupt generation disabled
     * 1: Interrupt generation enabled
	 * */
	SET_BIT(MFDI->CR,EOPIE);

	/* Set the sector erase bit to Configure the operation of erasing the
	 * sector
	 * Bit 1 SER: Sector Erase
     * Sector Erase activated.
     */
	SET_BIT(MFDI->CR,SER);

	/* Start the erasing operation by setting the start bit in the CR Register
	 * This bit triggers an erase operation when set. It is set only by software and cleared when the
     * BSY bit is cleared
	 * */
	SET_BIT(MFDI->CR,STRT);

	/* Wait till Flash Driver ends its operation
     *     0 : no Flash memory operation ongoing
     *     1 : Flash memory operation ongoing
	 * */
	while(GET_BIT(MFDI->SR,BSY) == MFDI_NUMBER_ONE);

	/* Bit 0 EOP: End of operation
     * Set by hardware when one or more Flash memory operations (program/erase) has/have
     * completed successfully. It is set only if the end of operation interrupts are enabled (EOPIE = 1).
     * Cleared by writing a 1.
     * */
	SET_BIT(MFDI->SR,EOP);

	/* Clear the sector erase bit to Configure the operation of erasing the
	 * sector
	 * Bit 1 SER: Sector Erase
     * Sector Erase activated.
     */
	CLEAR_BIT(MFDI->CR,SER);



}









void MFDI_voidEraseAppArea(void)
{
	u8 sector_u8Iterator;
	for(sector_u8Iterator = 1 ; sector_u8Iterator <= 5 ; sector_u8Iterator++ )
	{
		MFDI_voidSectorErase(sector_u8Iterator);
	}

}







/* Function Responsible for Writing on the flash
 * Copy_u32Address    : The Address which i will write to
 * *Copy_PtrData      : Pointer to thee data which will be written in the address
 * Copy_u8DataLength  : Length of the data be written
 * */
void MFDI_voidFlashWrite(u32 Copy_u32Address,u16 *Copy_PtrData,u8 Copy_u8DataLength)
{
	u8 Loc_u8ProgramIterator;

	/* Wait till Flash Driver ends its operation
     *     0 : no Flash memory operation ongoing
     *     1 : Flash memory operation ongoing
	 * */
	while(GET_BIT(MFDI->SR,BSY) == MFDI_NUMBER_ONE);

	/* Check If the Flash Driver is locked
	 * 1 : Locked
	 * 0 : UnLocked
	 * */
	/* If flash Driver is locked */
	if(GET_BIT(MFDI->CR,LOCK) == MFDI_NUMBER_ONE)
	{
		MFDI->KEYR = MFDI_KEY1;
		MFDI->KEYR = MFDI_KEY2;
	}
	/* Flash Driver is unlocked */
	else
	{
		/* DO No Thing */
	}

	/* Bits 9:8 PSIZE[1:0]: Program size
     * These bits select the program parallelism.
     *    00 program x8
     *    01 program x16
     *    10 program x32
     *    11 program x64
	 * */
	MFDI->CR = (MFDI->CR & MFDI_PROGRAM_SIZE_MASK) | (MFDI_PROGRAM_SIZE << PSIZE0);

	/* Looping to the Length of the data */
	for(Loc_u8ProgramIterator =0;Loc_u8ProgramIterator < Copy_u8DataLength;Loc_u8ProgramIterator++)
	{
		/* Set the Programming bit to Configure the operation of Prograaming the
		 * Flash memory
         * Bit 0 PG: Programming
         * Flash programming activated
	     */
		SET_BIT(MFDI->CR,PG);
#if MFDI_PROGRAM_SIZE == MFDI_WRITE_16_BIT
		/* Write the data at the specified address in the flash */
		*((volatile u16 *)Copy_u32Address) = Copy_PtrData[Loc_u8ProgramIterator];
		/* Increment the address in the flash memory by 2 because we are
		 * writing 16 Program size
		 * */
		Copy_u32Address = Copy_u32Address +2;
#endif
		/* Wait till Flash Driver ends its operation
	     *     0 : no Flash memory operation ongoing
	     *     1 : Flash memory operation ongoing
		 * */
		while(GET_BIT(MFDI->SR,BSY) == MFDI_NUMBER_ONE);

		/* Bit 0 EOP: End of operation
	     * Set by hardware when one or more Flash memory operations (program/erase) has/have
	     * completed successfully. It is set only if the end of operation interrupts are enabled (EOPIE = 1).
	     * Cleared by writing a 1.
	     * */
		SET_BIT(MFDI->SR,EOP);

		/* Clear PG Bit to deactivate the programming */
		CLEAR_BIT(MFDI->CR,PG);
	}
}






