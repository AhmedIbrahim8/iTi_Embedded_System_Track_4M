/*******************************************************************************************/
/*  Module       :   SW ICU                                                                */
/*  File Name    :   SWICU.h                                                              */
/*  Description  :   Header File of the Software ICU                                    */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   20/08/2023                                                            */
/*******************************************************************************************/


#ifndef HAL_SW_ICU_SWICU_H_
#define HAL_SW_ICU_SWICU_H_



void SWICU_voidEnable(void);

void SWICU_voidDisable(void);

void SWICU_u8GetTotalPeriod(uint32 *Copy_u32TotalPeriod);

void SWICU_u8GetDutyCycle(uint8 *Copy_u8DutyCycle);

void SWICU_u8GetOnPeriod(uint8 *Copy_u8OnPeriod);

void SWICU_u8GetOffPeriod(uint8 *Copy_u8OffPeriod);

#endif /* HAL_SW_ICU_SWICU_H_ */
