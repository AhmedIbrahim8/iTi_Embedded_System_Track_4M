/*******************************************************************************************/
/*  Module       :   Watch Dog Timer                                                       */
/*  File Name    :   WDT.h                                                                 */
/*  Description  :   Header File of the Watch Dog Timer                                    */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   21/08/2023                                                            */
/*******************************************************************************************/
#ifndef MCAL_WDT_WDT_H_
#define MCAL_WDT_WDT_H_

#define WDTCR  *((volatile uint8 * const)0x41)
#define WDTOE          4
#define WDE            3
#define WDP2           2
#define WDP1           1
#define WDP0           0

typedef enum{
	TIME_16_3_MS,
	TIME_32_5_MS,
	TIME_65_MS,
	TIME_0_13_S,
	TIME_0_26_S,
	TIME_0_52_S,
	TIME_1_0_S,
	TIME_2_1_S,
}WDT_TimeType;

void WDT_voidEnable(WDT_TimeType time);
void WDT_voidDisable(void);

#endif /* MCAL_WDT_WDT_H_ */
