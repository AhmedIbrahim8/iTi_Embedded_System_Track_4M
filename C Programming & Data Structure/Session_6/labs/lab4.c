#include<stdio.h>
#define SIZE 10

int sum(int *arr,int size);

int main(){
	int arr[SIZE];
	int index;
	for(index=0;index<SIZE;index++){
		printf("Enter element %d : ",index+1);
		scanf("%d",arr+index);
	}
	int result = sum(arr,SIZE);
	printf("Result = %d\n",result);
	return 0;
}

int sum(int *arr,int size){
	int index=0;
	int result=0;
	for(index=0;index<size;index++){
		result=result+*(arr+index);
	}
	return result;
}