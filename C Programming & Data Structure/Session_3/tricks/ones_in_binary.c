#include<stdio.h>
void ones(int number);

int main(){
	int number;
	printf("Enter a number : ");
	scanf("%d",&number);
	ones(number);
	return 0;
}


void ones(int number){
	int counter=0;
	for(int i=31;i>=0;i--){
		if(number&(1<<i))
		{
			counter++;
		}
	}
	printf("Number of ones = %d \n",counter);
}