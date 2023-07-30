#include<stdio.h>
int main(){
	int num=10;
	int *ptr=&num;
	printf("X before change is %d \n",num);
	*ptr=20;
	printf("X before change is %d \n",num);
	return 0;
}