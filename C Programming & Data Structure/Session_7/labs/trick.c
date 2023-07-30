#include<stdio.h>
int print(void);
int main(){
	for(print();print();print())
	{
		printf("%d\n",print());
	}
	
	return 0;
}
int print(void){
	static int x=16;
	return x--;
}