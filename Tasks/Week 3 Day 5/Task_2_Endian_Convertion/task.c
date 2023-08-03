#include "stdio.h"

void little_to_big_int(int number);
void little_to_big_short(short number);

int main(){
	int number1=0xAABBCCDD;
	short number2=0xAABB;
	/* Integers Conversion */
	printf("-------------- Integer Conversion --------------\n");
	printf("The number in Little Endian : %X\n",number1);
	little_to_big_int(number1);
	printf("---------------- Short Conversion --------------\n");
	printf("The number in Little Endian : %hX\n",number2);
	little_to_big_short(number2);
	return 100;
}

void little_to_big_int(int number){
	int big_number;
	char *ptr1=(char *)&number;
	char *ptr2=(char *)&big_number;
	
	for(int index=0;index<4;index++)
	{
		ptr2[index]=ptr1[4-1-index];
	}
	printf("The number in Big Endian : %X\n",big_number);
}

void little_to_big_short(short number){
	int big_number;
	char *ptr1=(char *)&number;
	char *ptr2=(char *)&big_number;
	
	for(int index=0;index<2;index++)
	{
		ptr2[index]=ptr1[2-1-index];
	}
	printf("The number in Big Endian : %hX",big_number);
}