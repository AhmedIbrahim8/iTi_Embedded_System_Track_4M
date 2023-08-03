#include<stdio.h>
#include "common_macros.h"
#include "std_types.h"
int main(){
	uint8 x=0;
	printf("x = %d \n",x);
	printf("Set the fist bit in x ......\n");
	SET_BIT(x,0);
	printf("x = %d \n",x);
	printf("Clear the fist bit in x ......\n");
	CLEAR_BIT(x,0);
	printf("x = %d \n",x);
	printf("Toggle the fist bit in x ......\n");
	TOGGLE_BIT(x,0);
	printf("x = %d \n",x);
	return 0;
}