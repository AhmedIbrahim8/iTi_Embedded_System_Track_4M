#include<stdio.h>
#define SIZE 10
typedef struct {
	int math;
	int lang;
	int phys;
	int chem;
}class;

int main(){
	class students[SIZE];
	int student_index;
	int index=0;
	for(index=0;index<SIZE;index++){
		printf("Enter Student Number %d grades\n",index+1);
		printf("Maths : ");
		scanf("%d",&(students[index].math));
		printf("Language : ");
		scanf("%d",&(students[index].lang));
		printf("Physics : ");
		scanf("%d",&(students[index].phys));
		printf("Chemistery : ");
		scanf("%d",&(students[index].chem));
	}
	printf("Enter student index : ");
	scanf("%d",&student_index);
	if(student_index>=SIZE || student_index <0){
		printf("Student Id is not correct\n");
	}
	else{
		printf("Maths      grade : %d \n",students[student_index].math);
		printf("Language   grade : %d \n",students[student_index].lang);
		printf("Physics    grade : %d \n",students[student_index].phys);
		printf("Chemistery grade : %d \n",students[student_index].chem);
	}
	
	return 0;
}