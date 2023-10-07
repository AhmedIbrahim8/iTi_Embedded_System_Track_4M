/*******************************************************************************************/
/*  Module       :   DMA                                                                  */
/*  File Name    :   MDMA_Private.h                                                       */
/*  Description  :   Header File of the DMA Driver Private                                */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   17/09/2023                                                            */
/*******************************************************************************************/

#ifndef MDMA_PRIVATE_H_
#define MDMA_PRIVATE_H_
/**************************************************************************/
/* DMA Module Base Address From Reference Manual page 38                */
/* DMA1 is connected to AHB1 Bus                                         */
/* Start from    address                 0x4002 6000                      */
/*                                       -----------                      */
/* End   at      address                 0x4002 63FF                      */

/* DMA2 is connected to AHB1 Bus                                         */
/* Start from    address                 0x4002 6400                     */
/*                                       -----------                      */
/* End   at      address                 0x4002 67FF                      */


/**************************************************************************/
#define  DMA1_BASE_ADDRESS       (0x40026000)

#define  DMA2_BASE_ADDRESS       (0x40026400)




/**************************************************************************/
/* Typedef for all DMA Module Register                                   */
/* Reference Manual Page 164 8.4.11 GPIO register map                     */
/**************************************************************************/
typedef struct {
	u32 SCR;
	u32 SNDTR;
	u32 SPAR;
	u32 SM0AR;
	u32 SM1AR;
	u32 SFCR;
}DMA_Stream_t;

typedef struct{
	u32 LISR;
	u32 HISR;
	u32 LIFCR;
	u32 HIFCR;
	DMA_Stream_t s[8];
}DMA_t;


/* Macro to point to the base address of the DMA1 Module */
#define       DMA1          ((volatile DMA_t*)DMA1_BASE_ADDRESS)

/* Macro to point to the base address of the DMA1 Module */
#define       DMA2          ((volatile DMA_t*)DMA2_BASE_ADDRESS)

/********************************************************************/
/** DMA stream x configuration register (DMA_SxCR) (x = 0..7) Bits **/
/********************************************************************/

/* Channels Selected Bits */
#define       CHSEL0              25
#define       CHSEL1              26
#define       CHSEL2              27

/* Memory burst transfer configuration Bits */
#define       MBURST0             23
#define       MBURST1             24

/* Peripheral burst transfer configuration Bits */
#define       PBURST0             21
#define       PBURST1             22

/* Current target (only in double buffer mode) Bit */
#define       CT                  19
/* Double Buffer mode bit */
#define       DBM                 18
/* Stream Priority Level */
#define       PL0                 16
#define       PL1                 17
/* Peripheral increment offset size */
#define       PINCOS              15

/* Memory data size */
#define       MSIZE0              13
#define       MSIZE1              14

/*  Peripheral data size */
#define       PSIZE0              11
#define       PSIZE1              12
/*  Peripheral increment mode */
#define       PINC                9
/*  Memory increment mode */
#define       MINC                10
/* Circular Mode */
#define       CIRC                8
/* Data transfer direction */
#define       DIR0                6
#define       DIR1                7
/* Peripheral flow controller */
#define       PFCTRL              5
/* Transfer complete interrupt enable */
#define       TCIE                4
/* Half transfer interrupt enable */
#define       HTIE                3
/* Transfer error interrupt enable */
#define       TEIE                2
/*  Direct mode error interrupt enable */
#define       DMEIE               1
/*  Stream enable / flag stream ready when read low */
#define       EN                  0






/*********************************************************************/
/***** DMA stream x FIFO control register (DMA_SxFCR) (x = 0..7) *****/
/*********************************************************************/
/* FIFO threshold selection Bits */
#define        FTH0                 0
#define        FTH1                 1
/* Direct MOde Disable Bit */
#define        DMDIS                2
/* FIFO status Bits (Read Only Bits) */
#define        FS0                  3
#define        FS1                  4
#define        FS2                  5
/* FIFO error interrupt enable Bit */
#define        FEIE                 7



#endif /* MDMA_PRIVATE_H_ */
