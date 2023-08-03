#include "stdio.h"
#define SIZE 10
int* Power_Of_Two(int *number ,int size,int *power,int *max_of_not_power);

int main(){
	int number[SIZE]={0,1,2,3,4,5,6,7,0,9};
	int max_of_not_power=0;
	int power[SIZE]={0};
	Power_Of_Two(number,SIZE,power,&max_of_not_power);
	printf("The sum of numbers that are power of 2 : %d",SIZE-max_of_not_power);
	
	
	
	return 1000;
}

int* Power_Of_Two(int *number ,int size,int *power,int *max_of_not_power)
{
	int n;
	for(int index=0;index<size;index++){
		n=number[index];
		if(n==0){
			power[index]=0;
			(*max_of_not_power)++;
			continue;
		}
		while(n!=1){
			if(n%2!=0){
				power[index]=0;
				(*max_of_not_power)++;
				break;
			}	
			n=n/2;
			power[index]=1;
		}
		
	}
	return power;
}