#include<stdio.h>
#include<stdlib.h>
 
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;
node *head;
node *end;
 
void insert_begin()
{
	int data;
	node *temp;
 
	printf("\nenter a value to be inserted\n");
	scanf("%d",&data);
 
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
 
	if(head==NULL)
	{
       	 	end=temp;
	}
	else
	{
		head->prev=temp;
	}  
	head=temp;
}
 
void insert_end()
{
	int data;
	node *temp,*prev;
 
	printf("\nenter the element to be inserted\n");
	scanf("%d",&data);
 
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	end=temp;
 
	if(head==NULL)
	{
		temp->prev=NULL;
		head=temp;
 
	}
	else{
		prev=head;
		while(prev->next != NULL){
			prev=prev->next;
 
		}
		prev->next=temp;
		temp->prev=prev;
	}
 
 
}
 
void insert_pos()
{
	int data,pos,i;
	node *ptr,*swap,*temp,*nexxt;
	printf("\nenter the value to instered : ");
	scanf("%d",&data);
	printf("\n enter the position to be inserted");
	scanf("%d",&pos);
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	  {
		printf("list is empty\n");
	        head=temp;
		temp->prev=NULL;
		temp->next=NULL;
		end=temp;
	  }
	else
	  {
	    ptr=head;
 
 
	    for(i=1;i<(pos-1)&&(ptr->next!=NULL);i++)
	       {
 
			printf("%d",ptr->data);
			ptr=ptr->next;
 
	       }
		   if(ptr==head && i==(pos))
			{
              			ptr->prev=temp;
			 	temp->next=ptr;
			 	temp->prev=NULL;
			 	head=temp;
			}
        else if(ptr==end && i==(pos-1))
	{
         	ptr->next=temp;
         	temp->prev=ptr;
         	end=temp;
	}
	else if(i==(pos-1))
	{
		nexxt=ptr->next;	
		swap=ptr->next;
		temp->next=swap;
		nexxt->prev=temp;
		ptr->next=temp;
		temp->prev=ptr;
 
	}
	     else
	       {
		 printf("invalid position");
	       }
	  }
 
 
}
 
 
void dlt_strt()
{
	node *dlt;
	dlt=head;
	if(dlt!=NULL)
	{
		head=dlt->next;
		head->prev=NULL;
		printf("\ndeleting element is %d",dlt->data);
		free(dlt);
	}
	else
		printf("The Linkedlist is empty\n");
}	
 
void dlt_end()
{
	struct node *dlt;
		dlt=end;
		if(dlt==NULL)
			{
				printf("List is empty");
			}
		else
			{
				end=dlt->prev;
				end->next=NULL;
				printf("deletion the element %d",dlt->data);
				free(dlt);
 
			}
}
 
void dlt_pos()
{
	node *ptr,*previous,*nexxt;
	int pos;
	printf("enter the position to delete");
	scanf("%d",&pos);
	ptr=head;
	if(head==NULL)
	{
		printf("list is  empty");
	}
	else
	{
		int i=1;
		while(ptr->next!=NULL && i!=pos)
		{
			ptr=ptr->next;
			i++;
		}
		if(ptr==head && i==pos)
		{
			head=ptr->next;
			head->prev=NULL;
			free(ptr);
		}
		else if(ptr==end && i==pos)
		{
			end=ptr->prev;
			end->next=NULL;
			free(ptr);
		}
		else if(i==pos)
		{
			previous=ptr->prev;
			nexxt=ptr->next;
			previous->next=nexxt;
			nexxt->prev=previous;
 
		}
		else
			printf("invalid position");
	}
}
void search()
{
	int data,i;
	  struct node *ptr;
	  ptr=head;
	  printf("enter the element to be search: \n");
	  scanf("%d",&data);
	  for(i=1;ptr->next!=NULL;i++)
	  	{
	  	   if(ptr->data==data)
	  		{
	  		  printf("\nelement found at position %d \n",i);
 
	  		}
	  	    ptr=ptr->next;
 
	  	}
	  if(ptr->data==data)
	  		{
	  		  printf("\nelement found at position %d \n",i);
 
	  		}
}
 
void display()
{
	int i=1;
	struct node *ptr;
	ptr=head;
	if(ptr!=NULL)
	  {
	    while(ptr->next!=NULL)
	      {
	       printf("%d element : %d \n",i,ptr->data);
	       ptr=ptr->next;
	       i++;
	      }
	    printf("%d element : %d \n",i,ptr->data);
	  }
	else
	   {
	     printf("\n linked list is empty \n");
	   }		
}
 
void display_reverse()
{
	node *ptr;
	int count=1;
	ptr=end;
	if(head == NULL)
		printf("\n\t\tLinked List is Empty!!");
	else{
		while(ptr->prev != NULL)
		{
		printf("[%d] element :%d\n",count,ptr->data);
 
		ptr = ptr->prev;
		count++;
		}
		printf("[%d] element :%d\n",count,ptr->data);
	}
 
}
 
 
int main()
{	
	int choice;
	do{
	printf("\n1.insert  first\n");
	printf("2.insert end\n");
	printf("3.insert in position\n");
	printf("4.delete first\n");
	printf("5.delete end\n");
	printf("6.delete in pos\n");
	printf("7.search\n");
	printf("8.display\n");
	printf("9.display reverse\n");
	printf("10.exit\n");
	printf("\nEnter your choice:\n");
	scanf("%d",&choice);
	switch(choice){
		case 1: insert_begin();
		break;
		case 2: insert_end();
		break;
		case 3: insert_pos();
		break;
		case 4: dlt_strt();
		break;
		case 5: dlt_end();
		break;
		case 6: dlt_pos();
		break;
		case 7: search();
		break;
		case 8: display();
		break;
		case 9:display_reverse();
		break;
		case 10: return 0;
		default: printf("Invalid choice\n");
		}
	}while(choice!=0);
}		
