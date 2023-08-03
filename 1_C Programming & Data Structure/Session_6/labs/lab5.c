#include<stdio.h>
#define SIZE 5
int scalar(int *arr1,int *arr2,int size);
int main(){
	int arr1[SIZE];
	int arr2[SIZE];
	int index=0;
	printf("Enter array number 1 \n");
	for(index=0;index<SIZE;index++){
		printf("Enter element %d : ",index+1);
		scanf("%d",arr1+index);
	}
	printf("Enter array number 2 \n");
	for(index=0;index<SIZE;index++){
		printf("Enter element %d : ",index+1);
		scanf("%d",arr2+index);
	}
	int result=scalar(arr1,arr2,SIZE);
	printf("Scalar Multiplication Result = %d\n",result);
	return 0;
}
int scalar(int *arr1,int *arr2,int size){
	int index=0;
	int sum=0;
	for(index=0;index<size;index++){
		sum=sum+(arr1[index]*arr2[index]);
	}
	return sum;
}