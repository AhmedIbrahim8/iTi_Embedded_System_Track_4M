/*******************************************************************************************/
/*  Module       :   Flash Driver Interface                                                              */
/*  File Name    :   MFDI_Interface.h                                                          */
/*  Description  :   Header File of the FDI Interface                          */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   30/09/2023                                                            */
/*******************************************************************************************/


#ifndef MFPEC_INTERFACE_H_
#define MFPEC_INTERFACE_H_
/********************************************************************************************/
/************************************** Masks and Numbers Used  *****************************/
/********************************************************************************************/
#define  MFDI_WRITE_8_BIT               0
#define  MFDI_WRITE_16_BIT              1
#define  MFDI_WRITE_32_BIT              2
#define  MFDI_WRITE_64_BIT              3



#define  MFDI_NUMBER_ONE                   1
#define  MFDI_NUMBER_ZERO                  0
/********************************************************************************************/
/********************************* User Type Defined ****************************************/
/********************************************************************************************/
typedef enum{
	MFDI_Sector_0,
	MFDI_Sector_1,
	MFDI_Sector_2,
	MFDI_Sector_3,
	MFDI_Sector_4,
	MFDI_Sector_5,
	MFDI_Sector_6,
	MFDI_Sector_7
}MFDI_SectorType;




/********************************************************************************************/
/************************************** APIs Proto-Types ************************************/
/********************************************************************************************/


void MFDI_voidEraseAppArea(void);

void MFDI_voidFlashWrite(u32 Copy_u32Address,u16 *Copy_PtrData,u8 Copy_u8DataLength);

void MFDI_voidSectorErase(MFDI_SectorType Copy_u8SectorNumber);


#endif /* MFPEC_INTERFACE_H_ */
