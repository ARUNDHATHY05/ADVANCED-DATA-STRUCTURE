#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
struct node *prev;  
    int data;  
    struct node *next;   
};  
struct node *head;
  
void beginsert();   
void lastinsert();  
void posinsert();  
void begin_delete();  
void last_delete();  
void posdelete();  
void display();  
void search(); 
void reverseList(); 
int main ()  
{  
    int choice =0;  
    while(choice !=10)   
    {  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at position\n4.Delete from Beginning\n5.Delete from last\n6.Delete from position\n7.Search for an element\n8.Show\n9.reverse\n10.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            beginsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            posinsert();       
            break;  
            case 4:  
            begin_delete();       
            break;  
            case 5:  
            last_delete();        
            break;  
            case 6:  
            posdelete();          
            break;  
            case 7:  
            search();         
            break;  
            case 8:  
            display();        
            break;
            case 9:
            reverseList();
            break;  
            case 10:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
} 
void beginsert()  
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value");  
    scanf("%d",&item);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  
  
void lastinsert()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
       }  
     printf("\nnode inserted\n");  
    }  
void posinsert()  
{
	int data,pos,i;
	node *ptr,*swap,*temp,*nexxt,*end;
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
void begin_delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining\n");  
    }  
} 

void last_delete()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last\n");  
    }     
}  
void posdelete()  
{  
    {
	node *ptr,*previous,*nexxt,*end;
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
}
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
       }
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }     
          
}    
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}
void reverseList()
{
	node *ptr,*end;
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
