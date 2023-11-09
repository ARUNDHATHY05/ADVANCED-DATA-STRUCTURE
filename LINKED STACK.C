#include<stdio.h>
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *top;  
  
       void push();
       void pop();
       void display();
       int main()
 {
    int ch,value;
    while(ch!=0)
    {
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    printf("\nSELECT AN OPTION\n");
    scanf("%d",&ch);
  switch(ch)
  {
         case 1:push();
         	break;
         case 2:pop();
         	break;
         case 3:display();
         	break;
         case 4:exit(0);
                break;
         default:
         printf("\nINVALID CHOICE\n");
                
   }      
    }
    }
void push()  
{  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(top == NULL)  
        {  
            ptr -> next = NULL;  
            top = ptr;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = top;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}  
void pop()  
{  
    struct node *ptr,*ptr1;  
    if(top == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(top -> next == NULL)  
    {  
        top = NULL;  
        free(top);  
        printf("\nOnly node of the list deleted\n");  
    }  
          
    else  
    {  
        ptr = top;   
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
void display()  
{  
    struct node *ptr;  
    ptr = top;   
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
