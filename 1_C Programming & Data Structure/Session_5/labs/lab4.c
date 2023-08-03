#include<stdio.h>
#define SIZE 10
int linear_search(int *numbers,int size,int search);

int main(){
	int index;
	int search;
	int counter=0;
	int number[SIZE];
	for(index=0;index<SIZE;index++){
		printf("Enter Number %d : ",index+1);
		scanf("%d",number+index);
	}
	printf("Enter a value to search about : ");
	scanf("%d",&search);
	counter=linear_search(number,SIZE,search);
	if(counter==0){
		printf("Value Not Exist \n");
	}
	else{
		printf("Value Exists %d times\n",counter);
	}
	
	
	return 0; 
}


int linear_search(int *number,int size,int search){
	int index;
	int counter=0;
	for(index=0;index<size;index++){
		if(search == number[index]){
			counter++;
		}
	}
	return counter;
}