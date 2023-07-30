#include<stdio.h>
struct employee{
	int salary;
	int b;
	int d;
};
int main(){
	int sum_salary=0;
	int sum_bounce=0;
	int sum_deduction=0;
	struct employee name[3];
	int index=0;
	for(index=0;index<3;index++){
		printf("The data of the employee number %d \n",index+1);
		printf("Salary = ");
		scanf("%d",&(name[index].salary));
		printf("Bounce = ");
		scanf("%d",&(name[index].b));
		printf("Deduction = ");
		scanf("%d",&(name[index].d));
		sum_salary=sum_salary+name[index].salary;
		sum_bounce=sum_bounce+name[index].b;
		sum_deduction=sum_deduction+name[index].d;
	}
	printf("The total = %d ",sum_salary+sum_bounce-sum_deduction);
	return 0;
}