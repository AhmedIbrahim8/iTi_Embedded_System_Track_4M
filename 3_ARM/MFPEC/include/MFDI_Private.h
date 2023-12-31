/*******************************************************************************************/
/*  Module       :   Flash Driver Interface                                                              */
/*  File Name    :   MFDI_Private.h                                                          */
/*  Description  :   Header File of the FDI Private                          */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   30/09/2023                                                            */
/*******************************************************************************************/


#ifndef MFPEC_PRIVATE_H_
#define MFPEC_PRIVATE_H_
#define  MFDI_BASE_ADDRESS           0x40023C00


typedef struct{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;
}FDI_t;



#define   MFDI    ((volatile FDI_t*)(MFDI_BASE_ADDRESS))

#define   DCRST              12
#define   ICRST              11
#define   DCEN               10
#define   ICEN               9
#define   PRFTEN             8
#define   LATENCY3           3
#define   LATENCY2           2
#define   LATENCY1           1
#define   LATENCY0           0


#define   BSY                16
#define   RDERR              8
#define   PGSERR             7
#define   PGPERR             6
#define   PGAERR             5
#define   WRPERR             4
#define   OPERR              1
#define   EOP                0


#define   LOCK               31
#define   ERRIE              25
#define   EOPIE              24
#define   STRT               16
#define   PSIZE1             9
#define   PSIZE0             8
#define   SNB3               6
#define   SNB2               5
#define   SNB1               4
#define   SNB0               3
#define   MER                2
#define   SER                1
#define   PG                 0



#define   SPRMOD             31
#define   nWRP7              23
#define   nWRP6              22
#define   nWRP5              21
#define   nWRP4              20
#define   nWRP3              19
#define   nWRP2              18
#define   nWRP1              17
#define   nWRP0              16
#define   RDP7               15
#define   RDP6               14
#define   RDP5               13
#define   RDP4               12
#define   RDP3               11
#define   RDP2               10
#define   RDP1               9
#define   RDP0               8
#define   nRST_STDBY         7
#define   nRST_STOP          6
#define   WDG_SW             5
#define   BOR_LEV1           3
#define   BOR_LEV0           2
#define   OPTSTRT            1
#define   OPTLOCK            0




#define   MFDI_KEY1                  0x45670123
#define   MFDI_KEY2                  0xCDEF89AB

#define   MFDI_SECTOR_MASK           0xFFFFFF87

#define   MFDI_PROGRAM_SIZE_MASK     0xFFFFFCFF

#endif /* MFPEC_PRIVATE_H_ */
