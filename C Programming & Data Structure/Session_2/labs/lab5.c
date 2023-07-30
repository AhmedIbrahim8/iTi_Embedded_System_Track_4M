#include<stdio.h>
int main(){
	int id;
	printf("Please Enter Your ID: ");
	scanf("%d",&id);
	if(id==1234){
		printf("Welcome Ahmed");
	}
	else if(id==5678){
		printf("Welcome Youssef");
	}
	else if(id==1145){
		printf("Welcome Mina");
	}
	else{
		printf("Wrong ID");
	}
	return 0;
}