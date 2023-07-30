#include<stdio.h>
void max_ones(int number);

int main(){
	int number;
	printf("Enter a number : ");
	scanf("%d",&number);
	max_ones(number);
	return 0;
}


void max_ones(int number){
	/* Counter to counter number of ones */
	int counter=0;
	/* Max to record the maximum ones between 2-zeros*/
	int max=0;
	/* index and i are just for looping */
	int index;
	int i=0;
	for(index=0;index<32;index++){
		/* To get the occurenence of zero*/
		if(!(number&(1<<index))){
			i=index;
			i++;
			/* loop until finding zero  or you exceed the limit of the integer value */
			while((number&(1<<i)) && (i<32) ){
				counter++;
				i++;
				printf("i = %d\n",i);
				printf("counter = %d\n",counter);
			}
			/* In case of negative value, you need to check the last bit of the integer 
			   to make sure that bit is zero or it will print wrong value 
			 */
			if(i==32){
				/* To check bit31*/
				i--;
				if( (!(number&(1<<i))) && (counter>max)){
					max=counter;
				}
			}
			/* In case of second occurence of zero, you 'll decide the maximum 
			   based on the counter reading.
			*/
			else if(!(number&(1<<i))){
				if(counter>max){
					max=counter;
				}
			}
			counter=0;
			index=i;
			
		}
	}
	printf("Max. number of ones = %d \n",max);
}