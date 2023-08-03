#include<stdio.h>
int main(){
	int grade;
	printf("Please Enter your grade : ");
	scanf("%d",&grade);
	if(grade>=85){
		printf("Your rating is Excellent\n");
	}
	else if(grade>=75){
		printf("Your rating is Very good\n");
	}
	else if(grade>=65){
		printf("Your rating is Good\n");
	}
	else if(grade>=50){
		printf("Your rating is Normal\n");
	}
	else{
		printf("Your rating is Faild\n");
	}
	return 0;
}