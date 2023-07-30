#include<stdio.h>
int main(){
	char name[3][6]={"Ahmed","Amr","Wael"};
	int user[3][2]={{1234,7788},{5678,5566},{9870,1122}};
	int index,id,pass,counter=0;
	printf("Please Enter your ID: ");
	scanf("%d",&id);
	for(index=0;index<3;index++){
		if(user[index][0]!=id){
			printf("You are not registered\n");
			return 0;
			
		}
		else{
			break;
		}
	}
	printf("Please Enter Password: ");
	scanf("%d",&pass);
	while(counter<3){
		for(index=0;index<3;index++){
			if(user[index][1]==pass){
				printf("Welcome %s",name[index]);
				return 0;
			}
		}
		counter++;
		if(counter == 3){
			break;
		}
		printf("Try again: ");
		scanf("%d",&pass);
	}
	printf("Incorrect password for 3 times, No more tries");
	return 0;
}