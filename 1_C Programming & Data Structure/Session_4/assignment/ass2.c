#include<stdio.h>
void add(int,int);
void sub(int,int);
void mul(int,int);
void divide(int,int);
void anding(int,int);
void oring(int,int);
void NOT(int);
void xoring(int,int);
void rem(int,int);
void inc(int);
void dec(int);

int main(){
	int operation;
	int n1,n2;
	while(1){
		printf("Enter the operation you want\n \
				(0)  Exit Program \n \
				(1) Add\n \
				(2)  Subtract\n \
				(3)  Multiply\n \
				(4)  Divide\n \
				(5)  And\n \
				(6)  Or\n \
				(7)  Not\n \
				(8)  Xor\n \
				(9)  remainder\n \
				(10) Increment\n \
				(11) Decrement\n \
				");
		scanf("%d",&operation);
		switch (operation){
			case 0:
			return 0;
			break;
			case 1:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			printf("Enter Number 2 : ");
			scanf("%d",&n2);
			add(n1,n2);
			break;
			case 2:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			printf("Enter Number 2 : ");
			scanf("%d",&n2);
			sub(n1,n2);
			break;
			case 3:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			printf("Enter Number 2 : ");
			scanf("%d",&n2);
			mul(n1,n2);
			break;
			case 4:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			printf("Enter Number 2 : ");
			scanf("%d",&n2);
			divide(n1,n2);
			break;
			case 5:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			printf("Enter Number 2 : ");
			scanf("%d",&n2);
			anding(n1,n2);
			break;
			case 6:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			printf("Enter Number 2 : ");
			scanf("%d",&n2);
			oring(n1,n2);
			break;
			case 7:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			NOT(n1);
			break;
			case 8:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			printf("Enter Number 2 : ");
			scanf("%d",&n2);
			xoring(n1,n2);
			break;
			case 9:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			printf("Enter Number 2 : ");
			scanf("%d",&n2);
			rem(n1,n2);
			break;
			case 10:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			inc(n1);
			break;
			case 11:
			printf("Enter Number 1 : ");
			scanf("%d",&n1);
			dec(n1);
			break;
			default:
			printf("Incorrent Operation ");
		}
	}
	return 0;
}

void add(int x,int y){
	printf("%d + %d = %d \n",x,y,x+y);
}
void sub(int x,int y){
	printf("%d - %d = %d \n",x,y,x-y);
}
void mul(int x,int y){
	printf("%d x %d = %ld \n",x,y,x*y);
}
void divide(int x,int y){
	printf("%d / %d = %f \n",x,y,(float)x/y);
}
void anding(int x,int y){
	printf("%d & %d = %d \n",x,y,x&y);
}
void oring(int x,int y){
	printf("%d | %d = %d \n",x,y,x|y);
}
void NOT(int x){
	printf("!%d = %d \n",x,!x);
}
void xoring(int x,int y){
	printf("%d ^ %d = %d \n",x,y,x^y);
}
void rem(int x,int y){
	printf("%d rem %d = %d \n",x,y,x%y);
}
void inc(int x){
	printf("++%d = %d \n",x,++x);
}
void dec(int x){
	printf("%--d = %d \n",x,--x);
}