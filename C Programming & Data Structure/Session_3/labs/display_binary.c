#include<stdio.h>
void display_binary(int number);

int main(){
	int number;
	printf("Enter a number : ");
	scanf("%d",&number);
	display_binary(number);
	return 0;
}


void display_binary(int number){
	for(int i=31;i>=0;i--){
		if(number&(1<<i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}