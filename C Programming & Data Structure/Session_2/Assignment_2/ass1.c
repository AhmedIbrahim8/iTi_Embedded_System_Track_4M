#include<stdio.h>
#define SIZE 10
int main(){
	int numbers[SIZE];
	int index;
	int search;
	for(index=0;index<SIZE;index++)
	{
		printf("Enter number %d: ",index+1);
		scanf("%d",&numbers[index]);
	}
	printf("Enter the value to search: ");
	scanf("%d",&search);
	for(index=0;index<SIZE;index++)
	{
		if(search==numbers[index])
		{
			printf("Value is exist at element number %d",index+1);
			break;
		}
		else
		{
			
		}
	}
	if(index==SIZE)
	{
		printf("Number not exist");
	}
	return 0;
}