/*******************************************************************************************/
/*  Module       :   GPIO                                                                  */
/*  File Name    :   MGPIO_Interface.h                                                     */
/*  Description  :   Header File of the GPIO Interface Driver                              */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   10/09/2023                                                            */
/*******************************************************************************************/

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

/********************************************************************************************/
/************************************* PORT INDEX *******************************************/
/********************************************************************************************/
#define  PORTA                     0
#define  PORTB                     1
#define  PORTC                     2


/********************************************************************************************/
/************************************* PIN INDEX *******************************************/
/********************************************************************************************/
#define  PIN0                     0
#define  PIN1                     1
#define  PIN2                     2
#define  PIN3                     3
#define  PIN4                     4
#define  PIN5                     5
#define  PIN6                     6
#define  PIN7                     7
#define  PIN8                     8
#define  PIN9                     9
#define  PIN10                    10
#define  PIN11                    11
#define  PIN12                    12
#define  PIN13                    13
#define  PIN14                    14
#define  PIN15                    15

/*******************************************************************************************/
/********************************** Macros for the mode ************************************/
/*******************************************************************************************/
#define  INPUT_RESET_STATE                   0
#define  GENRAL_PURPOSE_OUTPUT_MODE          1
#define  ALTERNATE_FUNCTION_MODE             2
#define  ANALOG_MODE                         3

#define  GPIO_MODE_MASK                      0x00000003


/*******************************************************************************************/
/******************************* Macros for the Output type ********************************/
/*******************************************************************************************/
#define  OUTPUT_PUSH_PULL                 0
#define  OUTPUT_OPEN_DRAIN                1
#define  GPIO_OUTPUT_TYPE_MASK         0x00000001
#define  GPIO_PIN_LEVEL_LOW               0
#define  GPIO_PIN_LEVEL_HIGH              1
#define  GPIO_OUTPUT_DATA_MASK         0x00000001

/*******************************************************************************************/
/******************************* Macros for the OutputSpeed Type ***************************/
/*******************************************************************************************/
#define  OUTPUT_LOW_SPEED_TYPE                                0
#define  OUTPUT_MEDIUM_SPEED_TYPE                             1
#define  OUTPUT_HIGH_SPEED_TYPE                               2
#define  OUTPUT_VERY_HIGH_SPEED_TYPE                          3

#define PIN_LEVEL_LOW                                         0
#define PIN_LEVEL_HIGH                                        1

#define  GPIO_OUTPUT_SPEED_TYPE_MASK                      0x00000003

/*******************************************************************************************/
/******************************* Macros for the Input Type *********************************/
/*******************************************************************************************/

#define  NO_PULL_UP_DOWN                     0
#define  PULL_UP                             1
#define  PULL_DOWN                           2

#define  GPIO_PULL_UP_DOWN__MASK                      0x00000003



/*******************************************************************************************/
/******************************* Macros for the Set Reset **********************************/
/*******************************************************************************************/

#define  OUTPUT_SET                               0
#define  OUTPUT_RESET                             1



/********************************************************************************************/
/************************************** APIs Proto-Types ************************************/
/********************************************************************************************/
void MGPIO_SetPortValue(u8 Copy_u8PortIndex,u32 Copy_u32Value);

void MGPIO_SetMode(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8PinMode);

void MGPIO_SetOutputPinMode(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8OutputType,u8 Copy_u8Speed);

void MGPIO_SetInputPinMode(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8InputType);

void MGPIO_GetPinValue(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 *Copy_pu8Data);

void MGPIO_SetPinValue(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8);

void MGPIO_SetResetValue(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8SetOrReset);

#endif /* MGPIO_INTERFACE_H_ */
