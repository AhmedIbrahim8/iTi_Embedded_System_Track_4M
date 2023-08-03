#include<stdio.h>

int main(){
	int index;
	int number[10];
	int sum=0;
	float average;
	for(index=0;index<10;index++){
		printf("Enter Number %d : ",index+1);
		scanf("%d",&number[index]);
		sum=sum+number[index];
	}
	average=sum/10.0;
	printf("Sum = %d\n",sum);
	printf("Average = %f\n",average);

	return 0;
}