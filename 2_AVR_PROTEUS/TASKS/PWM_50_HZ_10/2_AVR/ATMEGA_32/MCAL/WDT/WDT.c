/*******************************************************************************************/
/*  Module       :   Watch Dog Timer                                                       */
/*  File Name    :   WDT.c                                                                 */
/*  Description  :   Source File of the Watch Dog Timer                                    */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   21/08/2023                                                            */
/*******************************************************************************************/
#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "WDT.h"

void WDT_voidEnable(WDT_TimeType time){
/* Select the pre-scaler*/
	SET_BIT(WDTCR,WDE);
	WDTCR = time;


}
void WDT_voidDisable(void){
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	WDTCR = 0x00;
}

