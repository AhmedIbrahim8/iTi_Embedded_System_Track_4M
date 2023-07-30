#include<stdio.h>
int main(){
	int x,y;
	printf("number 1 : ");
	scanf("%d",&x);
	printf("number2 : ");
	scanf("%d",&y);
	if(y>=0){
		while(y!=0){
			x++;
			y--;
			
		}
		printf("The sum = %d",x);
	}
	else{
		while(y!=0){
			
			y++;
			x--;
		}
		printf("The sum = %d",x);
	}
}