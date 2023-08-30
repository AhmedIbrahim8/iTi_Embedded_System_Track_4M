/*******************************************************************************************/
/*  Module       :   TWI                                                                   */
/*  File Name    :   TWI.c                                                       */
/*  Description  :   Source File of the TWI Driver                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   27/08/2023                                                            */
/*******************************************************************************************/

#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "TWI.h"
#include "TWI_Private.h"
#include "TWI_Registers.h"
#include "TWI_Cfg.h"
#define  F_CPU                8000000UL


/* This Function Initiate the TWI as Master */
void TWI_voidMasterInit(void){
	uint32 temp1,temp2;

	TWAR = 64<<1;
	/* Adjust the Acknowledgment */
	TWCR = (TWCR & 0xBF) | (TWI_ACKNOWLEDGMENT<<TWEA);

	/* Set the pre-scaler Value */
	TWSR = (TWSR & 0xFC) | (TWI_PRESCALER & 0x03);
	/* Set the TWBR Value */
#if TWI_PRESCALER ==TWI_PRESCALER_1
	temp1 = ((F_CPU/TWI_SPEED)-16);
	temp2 = (((2*TWI_TWPS_4_0)));
	TWBR  = temp1/temp2;

	// TWBR =(uint8)(((F_CPU/TWI_SPEED)-16)*((1.0/(2*TWI_TWPS_4_0))));
#elif TWI_PRESCALER ==TWI_PRESCALER_4
	TWBR = (uint8)(((F_CPU/TWI_SPEED)-16)*((1.0/(2*TWI_TWPS_4_1))));
#elif TWI_PRESCALER ==TWI_PRESCALER_16
	TWBR = (uint8)(((F_CPU/TWI_SPEED)-16)*((1.0/(2*TWI_TWPS_4_2))));
#elif TWI_PRESCALER ==TWI_PRESCALER_64
	TWBR = (uint8)(((F_CPU/TWI_SPEED)-16)*((1.0/(2*TWI_TWPS_4_3))));
#endif



	/* Adjust the TWI Interrupt */
	TWCR = (TWCR & 0xFE) | (TWI_INTERRUPT);

	/* Adjust TWI */
	TWCR = (TWCR & 0xBF) | (TWI_MODULE<<TWEN);


}

/* This Function Initiate the TWI as Slave */
TWI_ErrorState TWI_enuSlaveInit(uint8 Copy_u8SlaveAddress){
	TWI_ErrorState Local_u8ErrorState = E_OK;
	/* Check the slave address is not reserved and not equal 0x00*/
	if(Copy_u8SlaveAddress <= 0xF0 && Copy_u8SlaveAddress != 0x00){

		/* Set the slave address of the Micro-controller in the TWAR Register */
		TWAR = (TWAR & 0x00) | (Copy_u8SlaveAddress<<TWA0);

		/*Adjust the General Call*/
		TWAR = (TWAR & 0xFE) | (TWI_GENERAL_CALL);

		/* Adjust the Acknowledgment */
		TWCR = (TWCR & 0xBF) | (TWI_ACKNOWLEDGMENT<<TWEA);

		/* Adjust TWI */
		TWCR = (TWCR & 0xBF) | (TWI_ACKNOWLEDGMENT<<TWEN);
	}
	else{
		Local_u8ErrorState = TWI_NOT_VALID_SLAVE_ADDRESS;
	}


	return Local_u8ErrorState;
}


/* This Function send the start condition
 * This Function return the condition of start condition
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendStartCondition(void){
	TWI_ErrorState Local_enuErrorState = TWI_OK;

	/* Send the start Condition */
	SET_BIT(TWCR,TWSTA);
	/* Clear the flag TWINT in TWCR Register To make the action be done */
	SET_BIT(TWCR,TWINT);
	/* Wait for the flag to be 1 */
	while(!(GET_BIT(TWCR,TWINT)));
	/* Check for the Acknowledgment by read the TWSR LAST 5-BITS *
	 * Check ACK => TWI_START */
	if((TWSR & TWI_TWSR_MASK)!=TWI_START){
		Local_enuErrorState = TWI_START_CONDITION_ERROR;
	}
	return Local_enuErrorState;


}





/* This Function send the Repeated Start condition
 * This Function return the condition of start condition
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendRepeatedStartCondition(void){
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Send the Repeated start Condition */
	SET_BIT(TWCR,TWSTA);
	/* Clear the flag TWINT in TWCR Register To make the action be done */
	SET_BIT(TWCR,TWINT);
	/* Wait for the flag to be 1 */
	while(!(GET_BIT(TWCR,TWINT)));
	/* Check for the Acknowledgment by read the TWSR LAST 5-BITS *
	 * Check ACK => TWI_REPEATED_START */
	if((TWSR & TWI_TWSR_MASK)!=TWI_REPEATED_START){
		Local_enuErrorState = TWI_REPEATED_START_CONDITION_ERROR;
	}
	return Local_enuErrorState;
}




/* This Function send the slave address with write operation
 * This Function return the condition of command
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress){
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Set TWDR = SLA + W *
	 * Write =0 */
	TWDR = Copy_u8SlaveAddress << TWD1;
	CLEAR_BIT(TWDR,TWD0);
	/* Clear the start condition In the TWCR Register */
	CLEAR_BIT(TWCR,TWSTA);
	/* Clear the Flag */
	SET_BIT(TWCR,TWINT);

	/* Wait for the flag to be 1 */
	while(!(GET_BIT(TWCR,TWINT)));

	/* Check for the Acknowledgment by read the TWSR LAST 5-BITS *
	 * Check ACK =>  TWI_MT_SLA_W_ACK */
	if((TWSR & TWI_TWSR_MASK)!=TWI_MT_SLA_W_ACK){
		Local_enuErrorState = TWI_SLAVE_ADDRESS_WRITE_ERROR;
	}
	return Local_enuErrorState;
}




/* This Function send the slave address with Read operation
 * This Function return the condition of command
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress){
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Set TWDR = SLA + R */
	TWDR = Copy_u8SlaveAddress << TWD1;
	SET_BIT(TWDR,TWD0);
	/* Clear the start condition In the TWSR Register */
	CLEAR_BIT(TWCR,TWSTA);
	/* Clear the Flag */
	SET_BIT(TWCR,TWINT);

	/* Wait for the flag to be 1 */
	while(!(GET_BIT(TWCR,TWINT)));

	/* Check for the Acknowledgment by read the TWSR LAST 5-BITS *
	 * Check ACK =>  TWI_MR_SLA_W_ACK */
	if((TWSR & TWI_TWSR_MASK)!=TWI_MR_SLA_W_ACK){
		Local_enuErrorState = TWI_SLAVE_ADDRESS_READ_ERROR;
	}
	return Local_enuErrorState;
}




/* This Function send the data
 * This Function return the condition of command
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuSendData(uint8 Copy_u8Data){
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Set TWDR = Data */
	TWDR = Copy_u8Data;

	/* Clear the Flag */
	SET_BIT(TWCR,TWINT);

	/* Wait for the flag to be 1 */
	while(!(GET_BIT(TWCR,TWINT)));

	/* Check for the Acknowledgment by read the TWSR LAST 5-BITS *
	 * Check ACK =>  TWI_MT_DATA_W_ACK */
	if((TWSR & TWI_TWSR_MASK)!=TWI_MT_DATA_W_ACK){
		Local_enuErrorState = TWI_SEND_DATA_ERROR;
	}
	return Local_enuErrorState;
}



/* This Function receive the data
 * This Function return the condition of command
 *     - Success
 *     - Error*/
TWI_ErrorState TWI_enuReceiveData(uint8 *Copy_u8Data){
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Check the Pointer*/
	if(Copy_u8Data != NULL_PTR){
		/* Clear the Flag */
		SET_BIT(TWCR,TWINT);

		/* Wait for the flag to be 1 */
		while(!(GET_BIT(TWCR,TWINT)));
		/* Check for the Acknowledgment by read the TWSR LAST 5-BITS *
		 * Check ACK =>  TWI_MR_DATA_W_ACK */
		if((TWSR & TWI_TWSR_MASK)!=TWI_MR_DATA_W_NACK){
			Local_enuErrorState = TWI_RECEIVE_DATA_ERROR;
//			Local_enuErrorState =TWSR & TWI_TWSR_MASK;

		}
		else{
			/* Read the Data */
		    *Copy_u8Data = TWDR;
		}

	}
	else{
		Local_enuErrorState = TWI_NULL_PTR;
	}

	return Local_enuErrorState;

}




/* This Function send the Stop condition */
void TWI_voidSendStopCondition(void){

	/* Send Stop Condition */
	SET_BIT(TWCR,TWSTO);
	/* Clear the flag */
	SET_BIT(TWCR,TWINT);
}
