#include "stdio.h"
#include "stdlib.h"
#include "std_types.h"

struct node{
	uint32 data;
	struct node *next;
};

struct node *front=NULL_PTR;
struct node *rear=NULL_PTR;

void Enqueue(uint32 data);
void Dequeue();
uint32 peek();

int main(){
	
	
	return 100;
}

void Enqueue(uint32 data){
	struct node *link=(struct node *)malloc(sizeof(struct node));
	link->data=data;
	link->next=NULL_PTR;
	/* Incase the Queue is Empty */
	if(front==NULL_PTR){
		front=link;
		rear=link;
		return;
	}
	rear->next=link;
	rear=link;
}
void Dequeue(){
	struct node *delete_node=NULL_PTR;
	if(front==NULL_PTR){
		return;
	}
	if(front==rear){
		delete_node=front;
		front=NULL_PTR;
		rear=NULL_PTR;
		free(delete_node);
		return;
	}
	delete_node=front;
	front=front->next;
	free(delete_node);
}
uint32 peek(){
	return front->data;
}