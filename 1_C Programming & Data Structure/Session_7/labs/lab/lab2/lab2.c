#include<stdio.h>
#include "std_types.h"
int main(){
	printf("Size of   uint8      = %d bytes \n",sizeof(uint8));
	printf("Size of   uint16     = %d bytes \n",sizeof(uint16));
	printf("Size of   uint32     = %d bytes \n",sizeof(uint32));
	printf("Size of   sint16     = %d bytes \n",sizeof(sint16));
	printf("Size of   sint32     = %d bytes \n",sizeof(sint32));
	printf("Size of   float32    = %d bytes \n",sizeof(float32));
	printf("Size of   float64    = %d bytes \n",sizeof(float64));
	return 0;
}