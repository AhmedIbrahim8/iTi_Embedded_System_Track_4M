#include<stdio.h>
void swap_pointer(int **p_ptr,int **q_ptr,int **r_ptr);
int main(){
	int num1=10;
	int num2=20;
	int num3=30;
	int *p_ptr=&num1;
	int *q_ptr=&num2;
	int *r_ptr=&num3;
	printf("num1     = %d \n",num1);
	printf("num2     = %d \n",num2);
	printf("num3     = %d \n",num3);
	printf("num1_ptr = %d \n",p_ptr);
	printf("num2_ptr = %d \n",q_ptr);
	printf("num3_ptr = %d \n",r_ptr);
	printf("num1_ptr = %d \n",*p_ptr);
	printf("num2_ptr = %d \n",*q_ptr);
	printf("num3_ptr = %d \n",*r_ptr);
	printf("------- Swapping Pointers -------\n");
	swap_pointer(&p_ptr,&q_ptr,&r_ptr);
	printf("num1     = %d \n",num1);
	printf("num2     = %d \n",num2);
	printf("num3     = %d \n",num3);
	printf("num1_ptr = %d \n",p_ptr);
	printf("num2_ptr = %d \n",q_ptr);
	printf("num3_ptr = %d \n",r_ptr);
	printf("num1_ptr = %d \n",*p_ptr);
	printf("num2_ptr = %d \n",*q_ptr);
	printf("num3_ptr = %d \n",*r_ptr);
	return 0;
}



void swap_pointer(int **p_ptr,int **q_ptr,int **r_ptr){
	/* Swapping first 2-pointer */
	int *temp;
	temp=*p_ptr;
	*p_ptr=*q_ptr;
	*q_ptr=temp;
	/* Swapping the other pointers */
	temp=*q_ptr;
	*q_ptr=*r_ptr;
	*r_ptr=temp;
	/*
	*p_ptr=(*p_ptr)^(*q_ptr);
	*q_ptr=(*p_ptr)^(*q_ptr);
	*p_ptr=(*p_ptr)^(*q_ptr);
	
	*q_ptr=(*q_ptr)^(*r_ptr);
	*r_ptr=(*q_ptr)^(*r_ptr);
	*q_ptr=(*q_ptr)^(*r_ptr);	
	*/
}