#include<stdio.h>
#define SIZE 10
int main(){
	int array_1[10]={1,2,3,4,5,6,7,8,9,10};
	int array_2[10]={21,22,23,24,25,26,27,28,29,30};
	int index_1;
	int index_2;
	int index;
	int temp;
	printf("-------- Arrays before swapping --------\n");
	printf("Array 1 \t Array 2 \n");
	for(index=0;index<SIZE;index++){
		printf("%d\t\t  %d\n",array_1[index],array_2[index]);
	}
	
	/* Swap In reverse way */
	for(index_1=0,index_2=SIZE-1;index_1<SIZE;index_1++,index_2--){
		temp=array_1[index_1];
		array_1[index_1]=array_2[index_2];
		array_2[index_2]=temp;
	}
	
	/* Print after swaping */
	printf("-------- Arrays after swapping --------\n");
	printf("Array 1 \t Array 2 \n");
	for(index=0;index<SIZE;index++){
		printf("%d\t\t  %d\n",array_1[index],array_2[index]);
	}	
	
	return 0;
}