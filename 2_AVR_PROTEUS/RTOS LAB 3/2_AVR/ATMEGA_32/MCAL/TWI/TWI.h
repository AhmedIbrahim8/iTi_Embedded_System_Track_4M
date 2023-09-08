/*******************************************************************************************/
/*  Module       :   TWI                                                                   */
/*  File Name    :   TWI.h                                                       */
/*  Description  :   Header File of the TWI Driver                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   27/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TWI_TWI_H_
#define MCAL_TWI_TWI_H_

/* Enumeration has the value of the errors that can be happened
 * in the TWI */
typedef enum {
	TWI_OK = 1,
	TWI_NOT_VALID_SLAVE_ADDRESS,
	TWI_START_CONDITION_ERROR,
	TWI_REPEATED_START_CONDITION_ERROR,
	TWI_SLAVE_ADDRESS_WRITE_ERROR,
	TWI_SLAVE_ADDRESS_READ_ERROR,
	TWI_SEND_DATA_ERROR,
	TWI_NULL_PTR,
	TWI_RECEIVE_DATA_ERROR
}TWI_ErrorState;

/* This Function Initiate the TWI as Master */
void TWI_voidMasterInit(void);

/* This Function Initiate the TWI as Slave */
TWI_ErrorState TWI_enuSlaveInit(uint8 Copy_u8SlaveAddress);


/* This Function send the start condition
 * This Function return the condition of start condition
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendStartCondition(void);

/* This Function send the Repeated Start condition
 * This Function return the condition of start condition
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendRepeatedStartCondition(void);

/* This Function send the slave address with write operation
 * This Function return the condition of command
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress);

/* This Function send the slave address with Read operation
 * This Function return the condition of command
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress);

/* This Function send the data
 * This Function return the condition of command
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendData(uint8 Copy_u8Data);

/* This Function receive the data
 * This Function return the condition of command
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuReceiveData(uint8 *Copy_u8Data);


/* This Function send the Stop condition */
void TWI_voidSendStopCondition(void);


#endif /* MCAL_TWI_TWI_H_ */
