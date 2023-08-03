#include<stdio.h>
int main(){
	int result;
	printf("Rnter the answer of 3 x 4 = ");
	scanf("%d",&result);
	while(1){
		if(result==12){
			printf("Thank You");
			break;
		}
		else{
			printf("Not correct, Please try again: ");
			scanf("%d",&result);
		}
	}
	return 0;
}