#include<stdio.h>
#define SIZE 10
void selection_sorting(int* ,int);
int remove_repeated(int *,int);
int main(){
	int index;
	int number[SIZE];
	int new_size;
	for(index=0;index<SIZE;index++){
		printf("Enter Number %d : ",index+1);
		scanf("%d",number+index);
	}
	/* Sort the array before to make it easy */
	selection_sorting(number,SIZE);
	for(index=0;index<SIZE;index++){
		printf("number[%d] = %d\n",index,number[index]);
	}
	/* remove repeated values function that return
	   the new size of the array 
	   */
	new_size=remove_repeated(number,SIZE);
	for(index=0;index<new_size;index++){
		printf("number[%d] = %d\n",index,number[index]);
	}
	
	return 0;
}

void selection_sorting(int* number ,int size){
	int index1;
	int index2;
	int min;
	int temp;
	for(index1=0;index1<size-1;index1++){
		min=index1;
		for(index2=index1+1;index2<size;index2++){
			if(number[index2]<number[min]){
				min=index2;
			}
		}
		temp=number[min];
		number[min]=number[index1];
		number[index1]=temp;
	}
}

int remove_repeated(int *number,int size){
	int index1=0;
	int index2=0;
	int flag=0;
	int temp;
	for(index1=0;index1<size;index1++){
		if( (number[index1]==number[index1+1]) && flag==0){
			index2++;
			flag=1;
		}
		else if(number[index1]!=number[index1+1]){
			if(flag==0){
				index2++;
			}
			number[index2]=number[index1+1];
			flag=0;
		}
	}
	return index2;
}