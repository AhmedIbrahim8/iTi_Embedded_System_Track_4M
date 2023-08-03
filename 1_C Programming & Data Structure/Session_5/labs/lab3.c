#include<stdio.h>
#define SIZE 5

int main(){
	int number[SIZE];
	int index1,index2;
	int counter=0;
	int flag=0;
	for(index1=0;index1<SIZE;index1++){
		printf("Enter Number %d : ",index1+1);
		scanf("%d",&number[index1]);
	}
	for(index1=0;index1<SIZE-1-counter;index1++){
		
		for(index2=0;index2<SIZE-index1-1;index2++){
			printf("index2 = %d \n",index2);
			if(number[index2]>number[index2+1]){
				number[index2]=number[index2]^number[index2+1];
				number[index2+1]=number[index2]^number[index2+1];
				number[index2]=number[index2]^number[index2+1];
				flag=1;
				
			}
			else{
				if(flag==1){
					counter=0;
					flag=0;
				}
				else{
					counter++;
				}
				
			}
	
		}
		
		
	}
	for(index1=0;index1<SIZE;index1++){
		printf("Element %d : %d \n",index1,number[index1]);
	}
	return 0;
}