#include<stdio.h>
int Get_Max(int x,int y);

int main(){
	int x,y,res;
	printf("Enter value 1 : ");
	scanf("%d",&x);
	printf("Enter value 2 : ");
	scanf("%d",&y);
	res=Get_Max(x,y);
	printf("The maximum number = %d",res);
	
	return 0;
}

int Get_Max(int x,int y){
	if(x>y){
		return x;
	}
	else{
		return y;
	}
}