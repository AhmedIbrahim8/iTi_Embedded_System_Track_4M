#include<stdio.h>
int sum(int *ptr1,int *ptr2);

int main(){
	int x,y;
	int result;
	printf("Enter Number 1 : ");
	scanf("%d",&x);
	printf("Enter Number 2 : ");
	scanf("%d",&y);
	result=sum(&x,&y);
	printf("The result is : %d ",result);
	return 0;
}

int sum(int *ptr1,int *ptr2){
	return (*ptr1+*ptr2);
}