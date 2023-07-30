#include<stdio.h>
#include<stdlib.h>
#include"std_types.h"

struct node{
	uint32 data;
	struct node *next;
};
/* head points to the first element in the linked list */
struct node *head = NULL_PTR;
/* current used to move through the linked list because 
   if we move the head we will lost the nodes addresses  */
struct node *current=NULL_PTR;

/* Function for Inserting node at the first */
void insertAtFirst(uint32 data);
/* Function for Inserting node at the last */
void insertAtLast(uint32 data);
/* Function for Printing the Linked List */
void printList(void);
/* Function to print the size of the linked list */
void sizeOfList(void);
/* Function to find an item inside the list 
   if the item was found, it will give us the index of the item 
   if it is not found, it will print not found 
*/
void findItemInTheList(uint32 item);
/* Function to update the data inside the linked list */
void updateItemInTheList(uint32 old, uint32 new);
/* Function to remove node based on its data */
void removeNodeFromTheList(uint32 data);
/* Function to insert node inside the linked list */
void insertNodeInsideList(int data,int position);
/* Function that return size of linked list */
int size_of_list(void);
/* Function to give you the middle node inside 
   the linked list 
*/
void findMiddleNode(int *mid);
/* Function to give you the fifth element from the end
 */
void fifthElmentFromEnd(int *fifth);

int main(){
	printList();
	sizeOfList();	
	insertAtFirst(40);
	insertAtFirst(30);
	insertAtFirst(20);
	insertAtFirst(10);
	printList();
	sizeOfList();
	insertAtLast(50);
	insertAtLast(70);
	insertAtLast(80);
	insertAtLast(90);
	printList();
	sizeOfList();
	findItemInTheList(5);
	findItemInTheList(40);
	updateItemInTheList(5,10);
	updateItemInTheList(10,5);
	printList();
	sizeOfList();
	removeNodeFromTheList(3);
	printList();
	sizeOfList();	
	removeNodeFromTheList(5);
	printList();
	sizeOfList();
	insertNodeInsideList(10,0);
	printList();
	sizeOfList();
/* Insering at index = 5 */
	insertNodeInsideList(60,5);
	printList();
	sizeOfList();
	removeNodeFromTheList(60);
	printList();
	sizeOfList();
	return 0;
}

void insertAtFirst(uint32 data){
	/* Memory allocation to the node inside the heap segment*/
	struct node *link=(struct node *)malloc(sizeof(struct node));
	/* The first node next should be pointing to what head points */
	link->next=head;
	/* Inserting the data inside the node */
	link->data=data;
	/* Because it is the first node, head must point to it
	   Note : head always points to the first node in the Linked List
	*/
	head=link;
}
void insertAtLast(uint32 data){
	/* Memory allocation to the node inside the heap segment */
	struct node *link=(struct node *)malloc(sizeof(struct node));
	/* Inserting the data inside the node */
	link->data=data;
	/* Because we inserting at the last, this node next will point
	   to the NULL_PTR 
	   NOTE : NULL_PTR is an indication of the end of the linked list
	*/
	link->next=NULL_PTR;
	/* Initialize the current to be equal to head to loop inside
	   the linked list because, we can't move the head node or we
	   will loss the linked list nodes addresses 
	   */
	current=head;
	/* Incase of linked list is empty */
	if(current==NULL_PTR){
		/* Here Linked list is empty so ,we will link address 
		   inside the head and exit the function */
		head=link;
	}
	/* Incase of linked list not empty, we will loop unitl the 
	   node->next equal null. here we reach the last node.
	   */
	else{
		/* loop unit we find the last node in the linked list 
		   if(current->next == NULL_PTR), You will reach the last node
		   which its next == NULL_PTR
		   */
		while(current->next != NULL_PTR){
			/* increment the current to the next node and etc...*/
			current=current->next;
		}
		/* Last node next is equal to NULL_PTR but now we insert 
		   a node which will be the last node so, we will make 
		   current->next equal the address of the last node which
		   we inserted
		*/
		current->next=link;
	}
}


void printList(void){
	/* Initialize the current to be equal to head to loop inside
	   the linked list because, we can't move the head node or we
	   will loss the linked list nodes addresses 
	 */
	current=head;
	/* In case linked list is empty, we will print the message below */
	if(current==NULL_PTR){
		printf("Linked List is Empty\n");
	}
	else{
		printf("[head] => ");
		/* Loop untill you reach the node*/
		while(current !=NULL_PTR){
			/*printing the node data */ 
			printf("%d => ",current->data);
			/* Initialize the current node to the next node */
			current=current->next;
		}
		printf("[NULL]\n");
	}
}

void sizeOfList(void){
	/* Initialize the current to be equal to head to loop inside
	   the linked list because, we can't move the head node or we
	   will loss the linked list nodes addresses 
	 */
	current=head;
	uint32 size=0;
	/* In case linked list is empty */
	if(current==NULL_PTR){
		printf("Linked list is Empty\n");
	}
	else{
		/* Loop till reaching the end node*/
		while(current != NULL_PTR){
			/* increment the size by one*/
			size++;
			/* Initialize the current node to the next node */
			current=current->next;
		}
		printf("Size of linked list is %d nodes\n",size);
	}
}
void findItemInTheList(uint32 item){
	/* In case of Linked List is empty, we will not loop */
	int index=0;
	if(head==NULL_PTR){
		printf("Linked List is Empty \n");
	}
	else{
	/* Initialize the current to be equal to head to loop inside
	   the linked list because, we can't move the head node or we
	   will loss the linked list nodes addresses 
	 */
		current=head;
		while(current != NULL_PTR){
			/* Here, we found the item*/
			if(current->data==item){
				printf("%d is found at index %d \n",item,index);
				/* Exit the function after finding the item*/
				return;
			}
			else{
				/* Initialize the current node to the next node */
				current=current->next;
				/* Initialize the index to the next index */
				index++;
			}
		}
		/*In case of not exit the function, we didn't find the item */
		printf("%d not found inside the linked list\n",item);
	}
	
}

void updateItemInTheList(uint32 old, uint32 new){
	/* In case of Linked List is empty, we will not loop */
	if(head==NULL_PTR){
		printf("Linked List is Empty \n");
	}
	else{
	/* Initialize the current to be equal to head to loop inside
	   the linked list because, we can't move the head node or we
	   will loss the linked list nodes addresses 
	 */
		current=head;
		while(current != NULL_PTR){
			/* Here, we found the item*/
			if(current->data==old){
				current->data=new;
				printf("Data is updated \n");
				/* Exit the function after finding the item*/
				return;
			}
			else{
				/* Initialize the current node to the next node */
				current=current->next;
			}
		}
		/*In case of not exit the function, we didn't find the old data*/
		printf("%d is not found inside the linked list \n",old);
	}

}

void removeNodeFromTheList(uint32 data){
	/* Indication of position of data if it was found*/
	int position=0;
	current=head;
	/* Node to free the node if it is found*/
	struct node *delete_node=NULL_PTR;
	/* Previous always point to the previous node of current */
	struct node *previous = head;
	if(current == NULL_PTR){
		printf("Linked List is Empty \n");
	}
	/* In case first node equal the data */
	else if(current->data == data){
		delete_node=current;
		head=current->next;
		free(delete_node);
		printf("%d is found at position %d and has been deleted \n",data,position);
	}
	/* In case of first node not equal data */
	else{
		/* Increment the position */
		position++;
		/* Move to the next node */
		current=current->next;
		/* Loop until you reach the end */
		while(current != NULL_PTR){
			/* Exit the function if the data was found */
			if(current->data == data){
				/* previous next must be equal to the current next*/
				previous->next=current->next;
				/* delete node is now equal to the current */
				delete_node=current;
				free(delete_node);
				printf("%d is found at position %d and has been deleted \n",data,position);
				return;
			}
			/* In case not found, it will resume looping */
			previous=current;
			current=current->next;
			position++;
		}
		/*If delete node still equal null, the data not found */
		if(delete_node == NULL_PTR){
			printf("%d not found inside the linked list \n",data);
		}
	}
	
	
}
void insertNodeInsideList(int data,int position){
	struct node *link=(struct node *)malloc(sizeof(struct node));
	struct node *prev=NULL_PTR;
	int pos=0;
	/* If Linked list is Empty, it will insert the 
	   node at the first 
	*/
	if(head==NULL_PTR){
		head=link;
		link->next=NULL_PTR;
		link->data=data;
		return;
	}
	/* If position grater than the size of the linked
	   list, it will exit the function with a message  
	 */
	if(position > size_of_list()){
		printf("Invalid linked list index \n");
		return;
	}
	/* If position equal zero, we will insert 
	   at the first.
	*/
	if(position==0){
		link->data=data;
		link->next=head;
		head=link;
		printf("Node is inserted in positon %d \n",pos);
		return;
	}
	/* Initialize the current to be equal head */
	current=head;
	
	while(pos<position){
		prev=current;
		current=current->next;
		pos++;
		}
	link->data=data;
	link->next=current;
	prev->next=link;
	printf("Node is inserted in positon %d \n",pos);
			
}
	


int size_of_list(void)
{
   int size = 0;

   // check if the linked list is empty
   if(head==NULL)
   {
      printf("List size : %d ", size);
      return -1;
   }

   current = head;
   size = 1;
   while(current->next != NULL)
   {
      current = current->next;
      size++;
   }
   return size;
}

void findMiddleNode(int *mid){
	struct node *current=head;
	struct node *middle=head;
	int counter=0;
	if(head==NULL_PTR){
		printf("Linked list is empty \n");
		return;
	}
	if(head->next ==NULL_PTR){
		printf("Linked list has only one node \n");
		*mid=head->data;
		return;
	}
	while(current->next != NULL_PTR){
		current=current->next;
		counter++;
		if(counter==2){
			middle=middle->next;
			counter=0;
		}
	}
	*mid=middle->data;
}

void fifthElmentFromEnd(int *fifth){
	current=head;
	if(head==NULL)
	{
		printf("Empty Linked List \n");
		return;
	}
			// check if the list has only one node
	if(head->next == NULL)
	{
		printf("Linked list has only one element \n");
		*fifth = head->data;
		return;
	}
			//check if the array size is greater than or equal 5
	if(size_of_list() >= 5)
	{
		while(current->next->next->next->next->next != NULL){
			current=current->next;
		}
		*fifth=current->data;
	}
	else{
		printf("Linked List Size is smaller than 5\n");
	}
}