#include<stdio.h>
#define SIZE 10	
char binary_search(int *number,int size,int search);
void bubble_sorting(int *number,int size);
int main(){
	int index;
	int search;
	int number[SIZE];
	char found;
	for(index=0;index<SIZE;index++){
		printf("Enter Number %d : ",index+1);
		scanf("%d",number+index);
	}
	printf("Enter a value to search about : ");
	scanf("%d",&search);
	found=binary_search(number,SIZE,search);
	if(found==0){
		printf("Value Not Exist \n");
	}
	else{
		printf("Value Found %d \n",found);
	}
	
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

char binary_search(int *number,int size,int search){
	int start_index=0;
	int end_index=size-1;
	int mid_index;
	char found=0;
	bubble_sorting(number,size);
	while(end_index>=start_index){
		mid_index=(start_index+end_index)/2;
		if(search == number[mid_index]){
			found=1;
			break;
		}
		else if(search > number[mid_index]){
			start_index=mid_index+1;
		}
		else{
			end_index=mid_index-1;
		}
	}
	return found;
}