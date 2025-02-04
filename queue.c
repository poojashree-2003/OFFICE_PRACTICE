#include <stdio.h>
#include <stdlib.h>

//CREATING A STRUCT
struct node{
   int value;
   struct node* next;
};

struct node* front=0;
struct node* rear=0;

void enqueue(int val){
   struct node* new_node=(struct node *)malloc(sizeof(struct node));
   new_node->value=val;
   new_node->next=NULL;
   if(front==0 && rear==0){
	front=rear=new_node;
   }
   else{
	rear->next=new_node;
        rear=new_node;
	rear->next=NULL;
   }
}

void dequeue(){
   if(front==0){
	printf("Queue is empty");
   }
   else{
	struct node* new_front;
	new_front=front->next;
	front->next=NULL;
	front=new_front;
   }
}

void display(){
    if(front==0 && rear==0){
	printf("The queue is empty");
    }
    else{
	struct node* ptr;
	ptr=front;
	printf("\n");
	while(ptr!=NULL){
	   printf("%d ",ptr->value);
	   ptr=ptr->next;
	}
    }
}

void peek(){
    if(front==0 && rear==0){
	printf("The queue is empty");
    }
    else{
	printf("The front element is: %d ",front->value);
    }
}

int main(){
	/*enqueue(1);
	enqueue(2);
	enqueue(3);
	display();
	dequeue();
	peek();*/
        int decision,num;
	char choice='y';
while(choice=='y'){
	printf("Enter 1 to display\nEnter 2 to enqueue\nEnter 3 to dequeue\nEnter 4 to seek: ");
        scanf("%d",&decision);
switch(decision){
    	case 1:
        	display();
        	break;

    	case 2:
        	printf("\nEnter value to be added : ");
        	scanf("%d",&num);
           	enqueue(num);
		printf("\nThe num is succesfully added in the queue\n");
		display();
           	break;
    	case 3:
        	dequeue();
		printf("\nThe dequeue is successfull");
		display();
        	break;
	case 4:
		peek();
		break;
    	default:
        	printf("Enter valid decision");
}
printf("\nDo you want to continue(y/n):");
getchar();
scanf("%c",&choice);
}
	return 0;

}
