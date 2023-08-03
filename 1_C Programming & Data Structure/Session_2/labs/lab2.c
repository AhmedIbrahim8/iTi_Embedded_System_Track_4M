#include<stdio.h>
#define HOUR_RATE 50
int main(){
	int hour;
	float salary;
	printf("Enter the number of hours : ");
	scanf("%d",&hour);
	if(hour<40){
		salary=HOUR_RATE*(float)hour*0.9;
	}
	else{
		salary=HOUR_RATE*hour;
	}
	printf("Salary = %f",salary);
	return 0;
}