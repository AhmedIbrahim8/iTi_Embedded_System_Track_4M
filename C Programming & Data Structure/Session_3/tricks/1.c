#include<stdio.h>
int main(){
	signed int x=-1;
	unsigned int y=5;
	if(x<(signed int)y){
		printf("ok\n");
	}
	else{
		printf("not ok\n");
	}
	return 0;
}