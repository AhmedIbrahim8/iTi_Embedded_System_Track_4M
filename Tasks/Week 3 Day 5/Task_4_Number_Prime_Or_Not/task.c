/*
 ============================================================================
 Name        : EX_1_Prime_Number_between_interval.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void func(int num1,int num2){
    int number=num1+1;
    int flag=0;
    printf("Prime numbers between %d and %d are: ",num1,num2);
	
	/* Looping from num1+1 to num2-1 */
    for(;number<num2;number++){
		/* looping from 2 to the number-1 
		   Why not to the number ?
		   - Prime number can only be divided by itself or by 1
		   - If a number can be divided by anything else, it will be not a prime number
		   */
        for(int i=2;i<number;i++){
			/* The number can be divided to a number that it is not itself 
			   /* Number if not a prime number */
			  
            if(((float)number/i)==(number/i)){
				/* Flag is an indication that number is not a prime */
                flag=1;
				/* Here, we don't want to still loop */
                break;
            }
            else{
				/* Indication that number can be prime */
                flag=0;
            }

        }
		/* If flag exits the loop and still equal zero, the number will be prime one */
        if(flag==0){
            printf("%d ",number);
        }
        else{
            flag=0;
        }
    }

}

int main() {
    int num1,num2;
    printf("Enter two numbers(intervals) : ");
    scanf("%d%d",&num1,&num2);
    func(num1,num2);
   return 0;
}