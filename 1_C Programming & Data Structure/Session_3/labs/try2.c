#include<stdio.h>
int main(){
	int num1,num2,num3;
	printf("Enter number 1: ");
	scanf("%d",&num1);
	printf("Enter number 2: ");
	scanf("%d",&num2);
	printf("Enter number 3: ");
	scanf("%d",&num3);
	switch((num1>num2 && num1>num3) + \
	     2*(num2>num1 && num2>num3) + \
		 3*(num3>num1 && num3>num2) + \
		 4*(num1>num2 && num1==num2) + \
		 5*(num1>num3 && num1==num) + \
		 6*(num2>num1 && num2>num3) + \){
	}
}