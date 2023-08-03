#include<stdio.h>
int get_max(int *,int);
int get_min(int *,int);

int main(){
	int numbers[4];
	for(int index=0;index<4;index++){
		printf("Enter Number %d : ",index+1);
		scanf("%d",&numbers[index]);
	}
	int max = get_max(numbers,4);
	int min = get_min(numbers,4);
	printf("The maximum number = %d \n",max);
	printf("The minimum number = %d \n",min);
	return 0;
}
int get_max(int *numbers,int size){
	int max=numbers[0];
	for(int i=1;i<size;i++){
		if(numbers[i]>max){
			max=numbers[i];
		}
	}
	return max;
}

int get_min(int *numbers,int size){
	int min=numbers[0];
	for(int i=1;i<size;i++){
		if(numbers[i]<min){
			min=numbers[i];
		}
	}
	return min;
}