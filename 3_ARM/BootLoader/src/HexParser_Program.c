#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"


#include "../include/HexParser_Interface.h"
#include "../include/MFDI_Interface.h"


#define          FLASH_BASE_ADDRESS                     0x08000000

/* We want to program the flash 16 bits by 16 bits
 * that's why we use u16 as a type of the array    */
u16     DataBuffer[100];

/* Function responsible for converting from ascii values to heax-decimal value */
static u8 HexParser_u8Ascii2Hex(u8 A_u8Ascii)
{
	u8 L_u8HexValue = 0;
	/* In case value is between '0' and '9' */
	if(A_u8Ascii >= '0' && A_u8Ascii<= '9')
	{
		/* Hexa-decimal value will be - '0'*/
		L_u8HexValue = A_u8Ascii - '0';
	}
	/* In case value between 'A' and 'F' */
	else if(A_u8Ascii >= 'A' && A_u8Ascii <= 'F')
	{
		L_u8HexValue = A_u8Ascii - 55;
	}
	return L_u8HexValue;
}



void HexParser_vParseData(u8 A_pu8Data[])
{
	/* index    0 12     3456               78                  9 to 40                  41 42     */
	/*          : 10     0000               00      00000120C5020008CB020008CF020008     5   2     */
	/*            cc  high address     record type               Data                 check sum */
	u8 CC_high,CC_low,CC;

	u8 counter;

	u8 digit0,digit1,digit2,digit3;

	u32 address = 0;

	/* get the character count high nibbles which is at index 1
	 * but we need this value in hexa-decimal value so, we need to convert
	 * from ascii value to hexa-decimal value */
	CC_high = HexParser_u8Ascii2Hex(A_pu8Data[1]);

	/* get the character count low nibbles which is at index 2
	 * but we need this value in hexa-decimal value so, we need to convert
	 * from ascii value to hexa-decimal value */
	CC_low = HexParser_u8Ascii2Hex(A_pu8Data[2]);

	/* Adjust the character count by shifting left the high nibbles of the cc_high by 4
	 * and oring it with the low nibbles of the character count                           */
	CC = (CC_high  << 4) | CC_low;

	/* Get the address which at index 3 , 4 , 5 , 6 */
	digit0 = HexParser_u8Ascii2Hex(A_pu8Data[3]);
	digit1 = HexParser_u8Ascii2Hex(A_pu8Data[4]);
	digit2 = HexParser_u8Ascii2Hex(A_pu8Data[5]);
	digit3 = HexParser_u8Ascii2Hex(A_pu8Data[6]);

	/* Zeros to the low 16 bits of the address to insert the new low address */
	address = address & 0xFFFF0000;
	/* The address contain of the base address which is 0x0800 0000 and the low address
	 * the low address is adjusted by oring the digit0 , digit1 , digit2 , digit3
	 *  */
	address = (FLASH_BASE_ADDRESS) \
			 |(digit0 << 12)\
			 |(digit1 << 8)\
			 |(digit2 << 4)\
			 |(digit0 << 0);

	/* Adjust the data byte based on the character counter into the buffer data
	 * to be sent to the flash driver to be burned into the flash memory         */
	for(counter =0;counter< (CC/2);counter++)
	{
		/* Get the data inside the record and adjust it at the array to be
		 * sent to the flash driver to be burned to the flash memory
		 *  */
		digit0 = HexParser_u8Ascii2Hex(A_pu8Data[(4*counter)+9]);
		digit1 = HexParser_u8Ascii2Hex(A_pu8Data[(4*counter)+10]);
		digit2 = HexParser_u8Ascii2Hex(A_pu8Data[(4*counter)+11]);
		digit3 = HexParser_u8Ascii2Hex(A_pu8Data[(4*counter)+12]);

		DataBuffer[counter] = (digit0 << 12) \
			                 |(digit1 << 8)  \
			                 |(digit2 << 4)  \
			                 |(digit3 << 0);
	}
	/* After the termination of the upper for loop the buffer data is adjusted
	 * then we will call the flash driver to burn the data record into the flash memory
	 * the programming of the flash memory is done record by record
	 * */
	MFDI_voidFlashWrite(address,DataBuffer,CC/2);


}
