#include<stdio.h>
#include "std_types.h"
typedef struct {
	uint16 x;
	uint32 y;
	uint16 z;
	uint32 k;
}my_struct;

int main(){
	
	printf("Size of my_struct = %d ",sizeof(my_struct));
	return 0;
}