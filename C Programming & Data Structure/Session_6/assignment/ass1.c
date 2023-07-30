#include<stdio.h>
#define SIZE 10
void bubble_sorting(int *number,int size);
int main(){
	int number[SIZE];
	int index;
	for(index=0;index<SIZE;index++){
		printf("Enter element %d : ",index+1);
		scanf("%d",number+index);
	}
	bubble_sorting(number,SIZE);
	for(index=0;index<SIZE;index++){
		printf("Element %d : %d\n",index+1,*(number+index));
	}	
	return 0;
}

void bubble_sorting(int *number,int size){
	int index1;
	int index2;
	for(index1=0;index1<SIZE-1;index1++){
		for(index2=0;index2<SIZE;index2++){
			if(number[index2]>number[index2+1]){
				number[index2]=number[index2]^number[index2+1];
				number[index2+1]=number[index2]^number[index2+1];
				number[index2]=number[index2]^number[index2+1];
				
			}
		}
	}
}