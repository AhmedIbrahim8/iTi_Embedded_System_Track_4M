#include<stdio.h>
#define SIZE 3
int main(){
	int numbers[SIZE];
	char index=0;
	for(index=0;index<SIZE;index++)
	{
		printf("Please enter number %d: ",index+1);
		scanf("%d",&numbers[index]);
	}
	for(index=SIZE-1;index>=0;index--)
	{
		printf("number %d: %d \n",index+1,*(numbers+index));
	}
	
	return 0;
}