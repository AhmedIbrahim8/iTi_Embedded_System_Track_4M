#include<stdio.h>
#include "stdlib.h"
int main(){
	int num_elements;int sum=0;int new_num_elements;
	printf("Enter number of elements : ");
	scanf("%d",&num_elements);
	int *ptr=(int *)malloc(sizeof(int)*num_elements);
	for(int index=0;index<num_elements;index++){
		printf("Please Enter number %d :",index+1);
		scanf("%d",ptr+index);
		sum=sum+ptr[index];
	}
	printf("The sum of all elements : %d \n",sum);
	int temp;
	for(int index1=0;index1<num_elements-1;index1++){
		for(int index2=0;index2<num_elements;index2++){
			if(ptr[index2+1]<ptr[index2]){
				temp=ptr[index2+1];
				ptr[index2+1]=ptr[index2];
				ptr[index2]=temp;
			}
		}
	}
	printf("Values after sorting are.......\n");
	for(int index=0;index<num_elements;index++){
		printf("%d\n",ptr[index]);
	}
	/* Change the elements number */
	printf("Enter the new number of elements : ");
	scanf("%d",&new_num_elements);
	int *ptr2=(int *)realloc(ptr,new_num_elements*sizeof(int));
	if(ptr2 == '\0'){
		printf("No memory allocated\n");
	}
	else{
		sum=0;
		for(int index=0;index<new_num_elements;index++)
		{
		printf("Please Enter number %d :",index+1);
		scanf("%d",ptr2+index);
		sum=sum+ptr[index];
		}
		printf("Sum of new elements size = %d \n",sum);
	}
	free(ptr);
	free(ptr2);
	return 0;
}