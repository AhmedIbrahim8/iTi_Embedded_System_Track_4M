#include<stdio.h>
void swap(int *,int *);
int main(){
	int x=10;
	int y=20;
	printf("Values before swap \n");
	printf("X = %d \n",x);
	printf("Y = %d \n",y);
	swap(&x,&y);
	printf("Values after swap \n");
	printf("X = %d \n",x);
	printf("Y = %d \n",y);
	return 0;
}
void swap(int *x,int *y){
	(*x)=(*x)^(*y);
	(*y)=(*x)^(*y);
	(*x)=(*x)^(*y);
}