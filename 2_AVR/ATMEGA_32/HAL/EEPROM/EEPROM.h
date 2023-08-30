/*******************************************************************************************/
/*  Module       :   EEPROM                                                                */
/*  File Name    :   EEPROM.h                                                              */
/*  Description  :   Header File of the EEPROM Driver                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   27/08/2023                                                            */
/*******************************************************************************************/

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_

/* Application does not know how EEPROM will communicate so, we have this function
 * to initialize the I2C */
void EEPROM_voidInit(void);

uint8 EEPROM_u8WriteDataByte(uint8 Copy_u8Data,uint16 Copy_u16ByteAddress);

uint8 EEPROM_u8ReadDataByte(uint8 *Copy_pu8RecData,uint16 Copy_u16ByteAddress);

#endif /* HAL_EEPROM_EEPROM_H_ */
