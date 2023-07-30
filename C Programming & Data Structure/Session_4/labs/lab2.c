#include<stdio.h>
void swap(int *num1,int *num2);
int num1=10;
int num2=20;

int main(){
	printf("X before swap : %d\n",num1);
	printf("Y before swap : %d\n",num2);
	swap(&num1,&num2);
	printf("X after swap : %d\n",num1);
	printf("X after swap : %d\n",num2);
}

void swap(int *num1,int *num2){
	if((*num1)!=(*num2)){
		(*num1)=(*num1)^(*num2);
		(*num2)=(*num1)^(*num2);
		(*num1)=(*num1)^(*num2);
	}
	else{
		
	}
}