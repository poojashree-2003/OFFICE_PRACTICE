//CREATING A LINKED LIST
#include <stdio.h>
#include <stdlib.h>

//STRUCT CREATION
struct node{
    int value;
    struct node* next;//self referring struct
};

//ADDING ELEMENTS AT THE END
void add_node_end(struct node* head,int new_value){
    struct node* add;
    add=(struct node*)malloc(sizeof(struct node));
    struct node* ptr= head;
    //printf("%p",ptr->next);
    
   if(add==NULL){
	printf("Memory allocation is not done");
	exit(1);
   }
    
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    
    ptr->next=add;
    ptr=ptr->next;
    ptr->value=new_value;
    ptr->next=NULL;
    printf("The element is added successfully\n");
    
}

//ADDING ELEMENTS AT THE BEGGINING
void add_node_begin(struct node** head,int new_value){
    struct node* add;
    add=(struct node*)malloc(sizeof(struct node));
    add->value=new_value;
    add->next=*head;
    *head=add;
}

//DELETING LAST element
void delete_element(struct node* node){
    struct node* temp=node;
    struct node* ptr=temp->next;
    if(temp->next==NULL){
	printf("The linked list is empty now\n");
        free(temp);
    }
    while(ptr->next!=NULL){
        temp=temp->next;
        ptr=ptr->next;
    }
    temp->next=NULL;
    printf("The last node has been deleted\n");
}

//PRINT THE STRUCT
void traversal(struct node* ptr){
    int count=0;
    if(ptr==NULL){
	printf("No members in the linked list!!");
	exit(1);
    } 
    while(ptr!=NULL){
	count+=1;
        printf("The element %d is %d\n",count,ptr->value);
        ptr=ptr->next;
    }
}

int main()
{
    struct node* head;
    struct node* first;
    struct node* second;
    int new_value;
    
    
    head=(struct node*)malloc(sizeof(struct node));
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    
    head->value=0;
    head->next=second;
    printf("%p\n",head->next);
    
    second->value=1;
    second->next=first;
    
    first->value=2;
    first->next=NULL;
    
    
    int decision,num=0,choice;
    printf("Enter 1 to print\nEnter 2 to Add node\nEnter 3 to Delete node : ");
    scanf("%d",&decision);

    switch(decision){
	case 1:
	    traversal(head);
	    break;

	case 2:
	    printf("Enter value to be added : ");
	    scanf("%d",&num);
	    printf("1.Add in end\n2.Add at the beggining : ");
	    scanf("%d",&choice);
	    if(choice==1){
	       add_node_end(head,num);
	       traversal(head);
	       break;
            }
	    else{
		add_node_begin(&head,num);
	        traversal(head);
	       break;
	    }
	case 3:
	    delete_element(head);
	    traversal(head);
	    break;

	default:
	    printf("Enter valid decision");
}
    return 0;
    
}






