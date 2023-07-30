#include "stdio.h"
#include "stdlib.h"
#include "std_types.h"

struct node{
	int data;
	struct node *next;
};

struct node *top=NULL_PTR;
void push(uint32 data );
void pop(void);
int peek(void);

int main(){
	int data;
	push(30);
	push(20);
	push(10);
	data=peek();
	printf("data = %d\n",data);
	pop();
	data=peek();
	printf("data = %d\n",data);
	pop();
	data=peek();
	printf("data = %d\n",data);
	pop();
	data=peek();
	printf("data = %d\n",data);
	pop();	
	return 1000;
}

void push(uint32 data ){
	struct node *link=(struct node *)malloc(sizeof(struct node));
	link->data=data;
	if(top==NULL_PTR){
		link->next=NULL_PTR;
		top=link;
		return;
	}
	link->data=data;
	link->next=top;
	top=link;
}
void pop(void){
	if(top==NULL_PTR){
		return;
	}
	struct node *delete_node=top;
	top=top->next;
	free(delete_node);
}
int peek(void){
	return top->data;
}