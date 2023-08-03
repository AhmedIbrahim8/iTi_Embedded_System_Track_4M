#include<stdio.h>

int main(){
	int index;
	int number[10];
	int max;
	for(index=0;index<10;index++){
		printf("Enter Number %d : ",index+1);
		scanf("%d",&number[index]);
	}
	max=number[0];
	for(index=1;index<10;index++){
		if(number[index]>max){
			max=number[index];
		}
	}
	printf("The maximum Number is %d \n ",max);

	return 0;
}