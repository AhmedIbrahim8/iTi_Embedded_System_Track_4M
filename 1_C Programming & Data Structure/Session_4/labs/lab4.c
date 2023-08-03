#include<stdio.h>
int factorial(int number);

int main(){
	int n;
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("Factorial = %d",factorial(n));
	return 0;
}
int factorial(int number){
	if(number<1){
		return 1;
	}
	else{
		return number*factorial(number-1);
	}
}