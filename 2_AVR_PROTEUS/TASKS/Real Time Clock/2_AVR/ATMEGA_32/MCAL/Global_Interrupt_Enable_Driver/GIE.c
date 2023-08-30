/*******************************************************************************************/
/*  Module       :   Global Interrupt                                                      */
/*  File Name    :   GIE.h                                                                 */
/*  Description  :   Source File of the Global Interrupt Enable                            */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   12/08/2023                                                            */
/*******************************************************************************************/
#include "GIE.h"
#include "..\..\LIB\common_macros.h"
#include "..\..\LIB\Std_Types.h"
void GI_voidEnable(void){
	SET_BIT(SREG,I_BIT);
}

void GI_voidDisable(void){
	CLEAR_BIT(SREG,I_BIT);
}
