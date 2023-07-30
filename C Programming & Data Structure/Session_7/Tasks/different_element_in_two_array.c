#include<stdio.h>
#define SIZE_1 10
#define SIZE_2 11
int main(){
	int array_1[SIZE_1]={10,4,3,1,6,6,9,8,7,7};
	int array_2[SIZE_2]={8,3,6,11,7,7,10,1,4,6,9};
	int sum_array_1=0;
	int sum_array_2=0;
	int index=0;
	for(int index=0;index<SIZE_2;index++){
		if(index<SIZE_1){
			sum_array_1 = sum_array_1 + array_1[index];
		}
		sum_array_2 = sum_array_2 + array_2[index];
	}
	printf("The different number is : %d ",sum_array_2-sum_array_1);
	
	return 0;
}