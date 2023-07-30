#include<stdio.h>

int main(){
	int index;
	int number[10];
	for(index=0;index<10;index++){
		printf("Enter Number %d : ",index+1);
		scanf("%d",&number[index]);
	}
	for(index=9;index>=0;index--){
		printf("Number %d : %d\n",index+1,number[index]);
		
	}

	return 0;
}