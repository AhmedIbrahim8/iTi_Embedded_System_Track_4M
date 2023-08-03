#include<stdio.h>
int main(){
	int number;
	printf("Enter a number : ");
	scanf("%d",&number);
	int n=number;
	int sum=0;
	int counter=0;
	/* Reverse way */
	while(n!=0){
		printf("%d + ",n%10); 
		sum=sum+(n%10);
		n=n/10; 
		if(n<10){
			printf("%d = %d",n,sum+n);
			break;
		}
	}	
	printf("\n");
	/* Forward way */
	n=number;
	sum=0;
	while(n!=0){
		n=n/10;
		/* To counter number of digits */
		counter++;
	}
	n=number;
	int division=1;
	for(int i=counter;i>0;i--){
		for(int j=i;j>1;j--){
			division=division*10;
		}
		printf("%d + ",n/division);
		sum=sum+(n/division);
		n=n-division*(n/division);
		division=1;
		if(n<10){
			printf("%d = %d",n,sum+n);
			break;
		}
	}
	return 0;
}