/*******************************************************************************************/
/*  Module       :   NVIC                                                                  */
/*  File Name    :   MNVIC_Interface.h                                                     */
/*  Description  :   Header File of the NVIC Interface Driver                              */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   11/09/2023                                                            */
/*******************************************************************************************/

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_


/********************************************************************************************/
/************************************** Masks and Numbers Used  *****************************/
/********************************************************************************************/
#define        SCB_AIRCR_GROUP_MASK                   0x00000700
#define        NUMBER_32                                 32
#define        BIT_NUMBER_8                              8
#define        SCB_AIRCR_VECTKEY_NUMBER               0x05FA0000
#define        NVIC_IPR_MASK                          0x0F
#define        BIT_NUMBER_4                              4
#define        BIT_NUMBER_5                              5
#define        BIT_NUMBER_6                              6
#define        BIT_NUMBER_7                              7

/********************************************************************************************/
/************************************** #s used in the Module *******************************/
/********************************************************************************************/
#define  INTERRRUPT_NOT_ACTIVE            0
#define  INTERRUPT_ACTIVE                 1



/********************************************************************************************/
/************************************** Types Declaration ***********************************/
/********************************************************************************************/

/* Enumeration for the user to Adjust the number of groups and sub groups */
typedef enum{
	GROUP_16_SUB_NONE=3,
	GROUP_8_SUB_2,
	GROUP_4_SUB_4,
	GROUP_2_SUB_8,
	GROUP_NONE_SUB_16,
}MNVIC_Group_t;








/********************************************************************************************/
/************************************** APIs Proto-Types ************************************/
/********************************************************************************************/

/********************************************************************************************/
/* This Function responsible for :                                                          */
/*           - Enable the NVIC Bit for the specified Peripheral in the Copy_u8IntPos        */
/********************************************************************************************/
void MNVIC_VoidEnbleInterrupt(u8 Copy_u8IntPos);

/********************************************************************************************/
/* This Function responsible for :                                                          */
/*           - Disable the NVIC Bit for the specified Peripheral in the Copy_u8IntPos       */
/********************************************************************************************/
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntPos);

/********************************************************************************************/
/* This Function responsible for :                                                          */
/*           - Enable the Peripheral Pending Flag Bit for the specified Peripheral          */
/*             in the Copy_u8IntPos                                                         */
/********************************************************************************************/
void MNVIC_VoidEnableInterruptPending(u8 Copy_u8IntPos);

/********************************************************************************************/
/* This Function responsible for :                                                          */
/*           - Disable the Peripheral Pending Flag Bit for the specified Peripheral         */
/*             in the Copy_u8IntPos                                                         */
/********************************************************************************************/
void MNVIC_VoidDisableInterruptPending(u8 Copy_u8IntPos);

/********************************************************************************************/
/* This Function responsible for :                                                          */
/*           - Checking of the Peripheral Interrupt Active Flag                             */
/********************************************************************************************/
void MNVIC_VoidIsInterruptActive(u8 Copy_u8IntPos,u8 *Copy_Read);

/********************************************************************************************/
/* This Function responsible for :                                                          */
/*           - Adjust the SW Priority of the Specified Peripheral                           */
/********************************************************************************************/
void MNVIC_VoidSetInterruptPriority(u8 Copy_u8IntPos,u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum);

/********************************************************************************************/
/* This Function responsible for :                                                          */
/*           - Adjust the Group and subgroup for the Interrupts                             */
/********************************************************************************************/
void MNVIC_VoidSetInterruptGroupMode(MNVIC_Group_t GroupSubMode);

#endif /* MNVIC_INTERFACE_H_ */
