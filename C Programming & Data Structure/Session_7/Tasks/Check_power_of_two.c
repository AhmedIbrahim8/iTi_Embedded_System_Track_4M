#include<stdio.h>
int main(){
	unsigned int number;
	printf("Enter a number : ");
	scanf("%u",&number);
	int i=0;
	int power=2;
	int flag=0;
	if(number==1 || number==2){
		printf("%d is power of 2 ",number);
	}
	else if(number==0){
		printf("%d is not power of 2",number);
	}
	else{
	/* integer value limit is 2 to the power of 32 */
		for(i=0;i<32;i++){
			power=power*2;
			if(number==power && flag==0){
				flag=1;
				printf("%d is power of 2 ",number);
				break;
			}
		}
		if(flag==0){
			printf("%d is not power of 2 ",number);
		}
		}	
	
	return 0;
}