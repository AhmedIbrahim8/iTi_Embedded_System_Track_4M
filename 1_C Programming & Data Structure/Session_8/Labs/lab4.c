#include<stdio.h>
struct x{
	char a:3;
	char b:3;
	char c:2;
};

int main(){
	struct x m={6,5,2};
	printf("%d\n",m.a);
	printf("%d\n",m.b);
	printf("%d\n",m.c);
	return 0;
}