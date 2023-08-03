#include<stdio.h>
struct iti{
	int x;
	int y;
	int z;
};
struct iti global={10,20};
int main(){
	struct iti local={1,2};
	printf("global.z = %d\n",global.z);
	printf("local.z  = %d\n",local.z);
	return 0;
}