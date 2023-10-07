/*******************************************************************************************/
/*  Module       :   MSPI                                                                  */
/*  File Name    :   MSPI_Private.h                                                        */
/*  Description  :   Header File of the SPI Private Driver                                 */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   20/09/2023                                                            */
/*******************************************************************************************/

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_


#define SPI1_BASE_ADDRESS		0x40013000
#define SPI4_BASE_ADDRESS		0x40013400


#define SPI2_BASE_ADDRESS		0x40003800
#define SPI3_BASE_ADDRESS		0x40003C00

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}MSPI_t;


#define   SPI1     ((volatile MSPI_t *)SPI1_BASE_ADDRESS)

#define   BIDIMODE                   15
#define   BIDIOE                     14
#define   CRCEN                      13
#define   CRCNEXT                    12
#define   DFF                        11
#define   RXONLY                     10
#define   SSM                        9
#define   SSI                        8
#define   LSBFIRST                   7
#define   SPE                        6
#define   BR2                        5
#define   BR1                        4
#define   BR0                        3
#define   MSTR                       2
#define   CPOL                       1
#define   CPHA                       0





#define   TXEIE                      7
#define   RXNEIE                     6






#define   FRE                        8
#define   BSY                        7
#define   OVR                        6
#define   MODF                       5
#define   CRCERR                     4
#define   UDR                        3
#define   CHSIDE                     2
#define   TXE                        1
#define   RXNE                       0
#endif /* MSPI_PRIVATE_H_ */
