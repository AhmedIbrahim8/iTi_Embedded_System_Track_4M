/*******************************************************************************************/
/*  Module       :   USART                                                                 */
/*  File Name    :   MUSART_Private.h                                                      */
/*  Description  :   Header File of the USART Private Driver                               */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   19/09/2023                                                            */
/*******************************************************************************************/

#ifndef MUSART_H_
#define MUSART_H_

#define  USART1_BASE_ADDRESS           0x40011000
#define  USART2_BASE_ADDRESS           0x40004400
#define  USART6_BASE_ADDRESS           0x40011400




typedef struct {
	u32 SBK          :1;
	u32 RWU          :1;
	u32 RE           :1;
	u32 TE           :1;
	u32 IDLEIE       :1;
	u32 RXNEIE       :1;
	u32 TCIE         :1;
	u32 TXEIE        :1;
	u32 PEIE         :1;
	u32 PS           :1;
	u32 PCE          :1;
	u32 WAKE         :1;
	u32 M            :1;
	u32 UE           :1;
	u32 RESERVED0    :1;
	u32 OVER8        :1;
	u32 RESERVED1    :16;

}MUSART_CR1;


typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	MUSART_CR1 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}MUSART_t;

#define    TXE                        7
#define    RXNE                       5

#define    DIV_FRACTION0              0
#define    DIV_MANTISSA0              4

#define    STOP0                      12


#define  USART1        ((volatile MUSART_t *)USART1_BASE_ADDRESS)

#define  USART2        ((volatile MUSART_t *)USART2_BASE_ADDRESS)

#define  USART6        ((volatile MUSART_t *)USART6_BASE_ADDRESS)









#endif /* MUSART_H_ */
