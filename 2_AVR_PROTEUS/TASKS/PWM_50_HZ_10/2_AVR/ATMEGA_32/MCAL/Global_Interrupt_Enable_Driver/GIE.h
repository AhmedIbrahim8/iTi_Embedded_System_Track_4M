/*******************************************************************************************/
/*  Module       :   Global Interrupt                                                      */
/*  File Name    :   GIE.h                                                                 */
/*  Description  :   Header File of the Global Interrupt Enable                            */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   12/08/2023                                                            */
/*******************************************************************************************/
#ifndef MCAL_GLOBAL_INTERRUPT_ENABLE_DRIVER_GIE_H_
#define MCAL_GLOBAL_INTERRUPT_ENABLE_DRIVER_GIE_H_

#define I_BIT    7
#define SREG    *((volatile uint8 * const)0x5F)

/* Function ProtoTypes */
void GI_voidEnable(void);
void GI_voidDisable(void);

#endif /* MCAL_GLOBAL_INTERRUPT_ENABLE_DRIVER_GIE_H_ */
