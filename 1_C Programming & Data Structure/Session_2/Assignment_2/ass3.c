#include<stdio.h>
#define SIZE 3
int main()
{
	int numbers[SIZE];
	int index;
	int max;
	for(index=0;index<SIZE;index++)
	{
		printf("Enter number %d: ",index+1);
		scanf("%d",&numbers[index]);
	}
	max=numbers[0];
	for(index=1;index<SIZE;index++)
	{
		if(numbers[index]>max)
		{
			max=numbers[index];
		}
	}
	printf("Maximum number is %d",max);
}