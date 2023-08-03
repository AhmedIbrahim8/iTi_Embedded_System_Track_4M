#include<stdio.h>
int main()
{
	int real_id=4793;
	char real_pass[]="ahmed123";
	int id;
	char pass[9];
	char index;
	printf("Enter a valid ID Number : ");
	scanf("%d",&id);	
	while(1)
	{
	if(id==real_id)
	{
		break;
	}
	else
	{
		printf("Not valid ID\n");
		printf("Please Re-enter a valid ID : ");
		scanf("%d",&id);
	}
	}
	printf("Enter a valid password : ");
	scanf("%s",pass);
	index=0;
	while(*(pass+index)!='\0')
	{
		if(pass[index]!=real_pass[index])
		{
			printf("Incorrect Password\n");
			break;
		}
		index++;
	}
	if(index==8){
		printf("Welcome Ahmed\n");
	}
	
	return 0;
}