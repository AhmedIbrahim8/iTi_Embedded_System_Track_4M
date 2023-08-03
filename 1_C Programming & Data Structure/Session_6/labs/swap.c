#include<stdio.h>
void swap_pointer(int **num1_ptr,int **num2_ptr);
int main(){
	int num1=10;
	int num2=20;
	int *num1_ptr=&num1;
	int *num2_ptr=&num2;
	printf("num1     = %d \n",num1);
	printf("num2     = %d \n",num2);
	printf("num1_ptr = %d \n",num1_ptr);
	printf("num2_ptr = %d \n",num2_ptr);
	printf("num1_ptr = %d \n",*num1_ptr);
	printf("num2_ptr = %d \n",*num2_ptr);
	
	printf("------- Swapping Pointers -------\n");
	swap_pointer(&num1_ptr,&num2_ptr);
	printf("num1     = %d \n",num1);
	printf("num2     = %d \n",num2);
	printf("num1_ptr = %d \n",num1_ptr);
	printf("num2_ptr = %d \n",num2_ptr);
	printf("num1_ptr = %d \n",*num1_ptr);
	printf("num2_ptr = %d \n",*num2_ptr);
	return 0;
}



void swap_pointer(int **num1_ptr,int **num2_ptr){
	/* Swapping 2-pointer */
	(*num1_ptr)=(*num1_ptr)^(*num2_ptr);
	(*num2_ptr)=(*num1_ptr)^(*num2_ptr);
	(*num1_ptr)=(*num1_ptr)^(*num2_ptr);
	
}