#include<stdio.h>
#include<stdlib.h>
 
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *top;
 
void push(){
	int data;
	node *temp,*pre;
	printf("\nenter a value to be inserted\n");
	scanf("%d",&data);
 
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
 
	if(top == NULL){
		top=temp;
		top->next=NULL;
	}
	else{
		pre=top;
		while(pre->next != NULL){
			pre=pre->next;
		}
		pre->next=temp;
		temp->next=NULL;
	}		
}
 
void pop()
{
	node *dlt,*pre;
	pre=NULL;
	dlt=top;
	int i;
 
	if(dlt!=NULL)
	{
		while(dlt->next!=NULL)
		{	
			pre=dlt;
			dlt=dlt->next;
			i=i+1;
		}
		printf("\n Deleting element %d\n",dlt->data);
		if(dlt==top)
		{
			top=NULL;
			free(dlt);
		}	
		else
		{
			pre->next=NULL;
		}
	}
	else
		printf("The linkedlist is empty\n");
}
 
void display(){
	node *temp;
	int count=0;
 
	temp=top;
	if(top==NULL){
		printf("\nList is empty\n");
	}
	else{
		while(temp->next!=NULL){
			printf("List [%d] : %d\n",count,temp->data);
			temp=temp->next;
			count++;
		}
		printf("List [%d] : %d\n",count,temp->data);
	}
	printf("\n");		
}
 
int main()
{	
	int choice;
	do{
	printf("\n1.Push\n");
	printf("2.Pop\n");
	printf("3.display\n");
	printf("4.exit\n");
 
	printf("\nEnter your choice:\n");
	scanf("%d",&choice);
	switch(choice){
		case 1: push();
		break;
		case 2: pop();
		break;
		case 3: display();
		break;
		case 4: return 0;
		default: printf("Invalid choice\n");
 
		}
	}while(choice!=0);
}		
