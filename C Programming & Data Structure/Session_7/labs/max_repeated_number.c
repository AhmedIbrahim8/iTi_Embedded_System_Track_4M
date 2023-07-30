#include<stdio.h>
int main(){
	int number[10]={1,3,3,3,6,6,10,1,7,6};
	int index=0;
	int array[10]={0};
	int max=0;
	for(index=0;index<10;index++){
		array[number[index]]++;
	}
	
	
	return 0;
}