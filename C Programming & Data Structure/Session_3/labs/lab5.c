#include<stdio.h>
int main(){
	int number;
	printf("Enter the number to display its multiplication table : ");
	scanf("%d",&number);
	for(int i=1;i<=6;i++){
		printf("%d x %d = %d\n",number,i,number*i);
	}
	return 0;
}