#include<stdio.h>
#define TRUE   0x01
#define FALSE  0x00
#define SIZE    10
int number_exist_or_not(int *numbers,int size){
	int index;
	int exist;
	/* Frequency array to count the number of existed numbers */
	int freq[10]={0};
	for(index=0;index<size;index++){
		freq[numbers[index]]++;
	}
	/* After looping if any element inside the frequency array
	   is equal zero, all number not exists 
	 */
	 for(index=0;index<size;index++){
		 if(freq[index]==0){
			 exist=FALSE;
			 break;
		 }
		 else{
			 exist=TRUE;
		 }
	 }
	 return exist;
}
 
int main(){
	int numbers[SIZE];
	for(int index=0;index<SIZE;index++){
		printf("Enter array %d : ",index+1);
		scanf("%d",numbers+index);
	}
	int exist = number_exist_or_not(numbers,SIZE);
	if(exist == TRUE){
		printf("All Numbers Are Exist \n");
	}
	else{
		printf("Not All Numbers Are Exist \n");
	}
	
	return 0;
}