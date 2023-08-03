#include<stdio.h>
int main(){
	int numbers[10];
	int sum=0;
	for(int i=0;i<10;i++){
		printf("Number-%d : ",i);
		scanf("%d",&numbers[i]);
		sum=sum+numbers[i];
	}
	printf("The sum of 10 no is : %d\n",sum);
	printf("The Average is      : %f",sum/10.0);
	return 0;
}