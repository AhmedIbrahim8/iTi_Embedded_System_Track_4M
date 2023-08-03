/* Get the maximum grade and minimum grade by using bubble sorting */
#include<stdio.h>
#define SIZE 10
void bubble_sorting(int *class,int size);
void enter_the_data(int *class,int size);
int sum_all_grades(int *class1,int *class2,int *class3,int size);
void get_max_min_grade(int *class1,int *class2,int *class3,int size,int *max,int *min);
void passed_failed(int *class1,int *class2,int *class3,int size,int *passed,int *failed);
int main(){
	int class1[SIZE];
	int class2[SIZE];
	int class3[SIZE];
	int max;
	int min;
	float average;
	int passed=0;
	int failed=0;
	printf("------------ Class 1 Students Entry ---------\n");
	enter_the_data(class1,SIZE);
	printf("------------ Class 2 Students Entry ---------\n");
	enter_the_data(class2,SIZE);
	printf("------------ Class 3 Students Entry ---------\n");
	enter_the_data(class3,SIZE);
	/* Bubble sorting to all arrays to get the maximum 
	   and minimum grade easily for the 3 - classes
	   */
	bubble_sorting(class1,SIZE);
	bubble_sorting(class2,SIZE);
	bubble_sorting(class3,SIZE);
	for(int i=0;i<10;i++){
		printf("class1[%d] = %d\n",i,class1[i]);
	}
	for(int i=0;i<10;i++){
		printf("class2[%d] = %d\n",i,class2[i]);
	}
	for(int i=0;i<10;i++){
		printf("class3[%d] = %d\n",i,class3[i]);
	}
	get_max_min_grade(class1,class2,class3,SIZE,&max,&min);
	printf("The highest grade = %d\n",max);
	printf("The lowest  grade = %d\n",min);
	/* Get the average of grades in 3-classes */
	average = sum_all_grades(class1,class2,class3,SIZE)/30.0;
	printf("Average grade = %f \n",average);
	/* Number of failed and passed in the 3-classes */
	passed_failed(class1,class2,class3,SIZE,&passed,&failed);
	printf("Number of passes = %d \n",passed);
	printf("Number of fails = %d \n",failed);
	
	return 0;
}


void enter_the_data(int *class,int size){
	int index;
	for(index=0;index<size;index++){
		printf("Enter Number %d : ",index+1);
		scanf("%d",class+index);
	}
}

int sum_all_grades(int *class1,int *class2,int *class3,int size){
	int index;
	int counter=0;
	int sum=0;
	for(index=0;index<size;index++){
		sum=sum+class1[index];
	}
	for(index=0;index<size;index++){
		sum=sum+class2[index];
	}
	for(index=0;index<size;index++){
		sum=sum+class3[index];
	}
	return sum; 
}

void get_max_min_grade(int *class1,int *class2,int *class3,int size,int *max,int *min){
	int maximum;
	int minimum;
	/* Get the maximum grade */
	if( (class1[size-1]>=class2[size-1]) && (class1[size-1]>=class3[size-1]) ){
		maximum=class1[size-1];
	}
	else if( (class2[size-1]>=class1[size-1]) && (class2[size-1]>=class3[size-1]) ){
		maximum=class2[size-1];
	}
	else {
		maximum=class3[size-1];
	}
	/* Get the minimum grade */
	if( (class1[0]<=class2[0]) && (class1[0]<=class3[0]) ){
		minimum=class1[0];
	}
	else if( (class2[0]<=class1[0]) && (class2[0]<=class3[0]) ){
		minimum=class2[0];
	}
	else{
		minimum=class3[0];
	}
	*max=maximum;
	*min=minimum;
}

void bubble_sorting(int *number,int size){
	int index1;
	int index2;
	
	for(index1=0;index1<SIZE-1;index1++){
		for(index2=0;index2<SIZE-1;index2++){
			if(number[index2]>number[index2+1]){
				number[index2]=number[index2]^number[index2+1];
				number[index2+1]=number[index2]^number[index2+1];
				number[index2]=number[index2]^number[index2+1];
			
			}
		}
	}
}

void passed_failed(int *class1,int *class2,int *class3,int size,int *passed,int *failed){
	int index=0;
	int fail=0;
	while(class1[index]<50){
		fail++;
		index++;
	}
	index=0;
	while(class2[index]<50){
		fail++;
		index++;
	}	
	index=0;
	while(class3[index]<50){
		fail++;
		index++;
	}
	*failed=fail;
	*passed=30-fail;
}