#include<stdio.h>
void display_binary(int number);
int main(){
	unsigned int number;
	int shift_number;
	printf("Enter the number : ");
	scanf("%d",&number);
	printf("\nEnter the shifted number : ");
	scanf("%d",&shift_number);
	printf("\nThe number before rotation : %d ",number);
	display_binary(number);
	/* Rotate Lift */
	number = (number << shift_number)|(number >>(8*sizeof(number)-shift_number));
	printf("\nThe number after rotation : %d ",number);
	display_binary(number);
	return 0;
}


void display_binary(int number){
	for(int i=31;i>=0;i--){
		if(number&(1<<i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
}