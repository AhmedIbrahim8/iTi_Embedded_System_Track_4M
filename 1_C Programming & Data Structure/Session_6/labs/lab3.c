#include<stdio.h>
void sum_sub(int *ptr1,int *ptr2,int *sum,int *sub);

int main(){
	int x,y;
	int sum,sub;
	printf("Enter Number 1 : ");
	scanf("%d",&x);
	printf("Enter Number 2 : ");
	scanf("%d",&y);
	sum_sub(&x,&y,&sum,&sub);
	printf("The result of  summation  is : %d \n",sum);
	printf("The result of subtraction is : %d ",sub);
	return 0;
}

void sum_sub(int *ptr1,int *ptr2,int *sum,int *sub){
	*sum=*ptr1+*ptr2;
	*sub=*ptr1-*ptr2;
}