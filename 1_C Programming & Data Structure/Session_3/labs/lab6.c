#include<stdio.h>
int main(){
	int number,factorial=1,i=1;
	printf("Enter an integer: ");
	scanf("%d",&number);
	do{
		factorial=factorial*i;
		i++;
	}while(i<=number);
	printf("Factorial = %d",factorial);
	return 0;
}