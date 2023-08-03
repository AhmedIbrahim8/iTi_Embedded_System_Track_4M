#include<stdio.h>
void zigzag_order(char *str1,char *str2,char *str3);
int main(){
	char str1[1000];
	char str2[1000];
	char str3[2000];
	printf("Enter string number 1 : ");
	gets(str1);
	printf("Enter string number 2 : ");
	gets(str2);	
	zigzag_order(str1,str2,str3);
	printf("The first    string = %s \n",str1);
	printf("The second   string = %s \n",str2);
	printf("The zigzaged string = %s \n",str3);
	return 0;
}


void zigzag_order(char *str1,char *str2,char *str3){
	int str1_size=0;
	int str2_size=0;
	int index1=0;
	int index2=0;
	/* TO count number of elements inside the string */
	while(str1[str1_size]!='\0'){
		str1_size++;
	}
	/* TO count number of elements inside the string */
	while(str2[str2_size]!='\0'){
		str2_size++;
	}
	/* Incase str2_size is the greatest, we will loop till 
	   we found the the null in the str1 */
	if(str2_size>=str1_size){
		while(str1[index1] != '\0'){
			str3[index2]=str1[index1];
			str3[index2+1]=str2[index1];
			index1++;
			index2=index2+2;
		}
		while(str2[index1]!='\0'){
			str3[index2]=str2[index1];
			index2++;
			index1++;
		}
		/* Terminate the string with null character */
		str3[index2]='\0';
	}
	else{
		while(str2[index1] != '\0'){
			str3[index2]=str1[index1];
			str3[index2+1]=str2[index1];
			index1++;
			index2=index2+2;
		}
		while(str1[index1]!='\0'){
			str3[index2]=str1[index1];
			index2++;
			index1++;
		}
		/* Terminate the string with null character */
		str3[index2]='\0';
		
	}
	
}