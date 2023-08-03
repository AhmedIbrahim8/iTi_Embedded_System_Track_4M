/* Get the maximum by using bubble sorting */
#include<stdio.h>
#define SIZE 10
void bubble_sorting(int *number,int size);
int main(){
	int index;
	int number[SIZE];
	int max;
	int min;
	for(index=0;index<SIZE;index++){
		printf("Enter Number %d : ",index+1);
		scanf("%d",number+index);
	}
	bubble_sorting(number,SIZE);
	printf("The minimum Number = %d\n",number[0]);
	printf("The maximum Number = %d\n",number[SIZE-1]);
	return 0;
}


void bubble_sorting(int *number,int size){
	int index1;
	int index2;
	int flag;
	int counter=0;
	for(index1=0;index1<SIZE-1-counter;index1++){
		for(index2=0;index2<SIZE-index1-1;index2++){
			if(number[index2]>number[index2+1]){
				number[index2]=number[index2]^number[index2+1];
				number[index2+1]=number[index2]^number[index2+1];
				number[index2]=number[index2]^number[index2+1];
				flag=1;
			}
			else{
				if(flag==1){
					counter=0;
					flag=0;
				}
				else{
					counter++;
				}
			}
		}
	}
}