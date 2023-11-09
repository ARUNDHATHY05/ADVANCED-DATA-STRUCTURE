#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head;
void beginsert();
void lastinsert();
void randominsert();
void insert_pos();
void begdelete();
void lastdelete();
void randomdelete();
void search();
void display();

int main()
{
int choice=0;
while(choice!=9)
{
printf("\n\n-----------------main menu----------------\n\n");
printf("\nchoose an option\n");
printf("\n1.insert in the begining\n2.insert in last\n3.insert randomly\n4.position insert\n5.delete from begining\n6.delete fromlast\n7.delete in random\n8.display\n9.search\n0.exit\n");
printf("\nenter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:beginsert();
       break;
case 2:lastinsert();
	break;
case 3:randominsert();
	break;
case 4:insert_pos();
       break;
case 5:begdelete();
	break;
case 6:lastdelete();
	break;
case 7:randomdelete();
	break;
case 8:display();
	break;
case 9:search();
	break;
case 0:exit(0);
default:printf("\nplease enter valid choice\n");
}
}
}
void beginsert()
{
struct node *ptr;
int item;
ptr=(struct node*)malloc(sizeof(struct node*));
if(ptr==NULL)
{
printf("\nOVERFLOW\n");
}
else
{
printf("\nenter value\n");
scanf("%d",&item);
ptr->data=item;
ptr->next=head;
head=ptr;
printf("\nnode inserted");
}
}
void lastinsert()
{
struct node *ptr, *temp;
int item;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\noverfow\n");
}
else
{
printf("\nenter the value\n");
scanf("%d",&item);
if(head==NULL)
{
ptr->next=NULL;
head=ptr;
printf("\nnode inserted\n");
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
ptr->next=NULL;
printf("\nnode inserted\n");
}
}
}
void randominsert()
{
int i,loc,item;
struct node *ptr, *temp;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\nOVERFLOW\n");
}
else
{
printf("\nenter value\n");
scanf("%d",&item);
ptr->data=item;
printf("\nenter location\n");
scanf("%d",&loc);
temp=head;
for(i=0;i<loc;i++)
{
temp=temp->next;
if(temp==NULL)
{
printf("\ncan't insert\n");
return;
}
}
ptr->next=temp->next;
temp->next=ptr;
printf("\n node inserted\n");
}
}
void insert_pos(){
	int data;
	int pos;
	int count=2;
	node *temp,*pre;
	printf("\nEnter value to insert : ");
	scanf("%d",&data);
	printf("\nEnter Position to insert : ");
	scanf("%d",&pos);
	temp=head;
	pre=(node*)malloc(sizeof(node));
	pre->data=data;
	
	if(head == NULL){
		printf("\nList is Empty \n");
	}
	else if(pos == 1){
			pre->next=head;
			head=pre;
	}
	else{
		temp=head;
		while(temp->next != NULL){
		if(pos==count){
			pre->next=temp->next;
			temp->next=pre;
			break;
		}
		else{
			temp=temp->next;
			count++;
		}
	}
	}
}
void begdelete()  
{
struct node *ptr;
if(head==NULL)
{
printf("\nlist empty\n");
}
else
{
ptr=head;
head=ptr->next;
free(ptr);
printf("\nnode deleted\n");
}
}
void lastdelete()
{
struct node *ptr, *ptr1;
if(head==NULL)
{
printf("\nlist is empty\n");
}
else if(head->next==NULL)
{
head=NULL;
free(head);
printf("\ndeleted\n");
}
else
{
ptr=head;
while(ptr->next=NULL)
{
ptr1=ptr;
ptr=ptr->next;
}
ptr1->next=NULL;
free(ptr);
printf("\ndeleted\n");
}
}
void randomdelete()
{
struct node *ptr,*ptr1;
int loc,i;
printf("\nlocation\n");
scanf("%d",&loc);
ptr=head;
for(i=0;i<loc;i++)
{
ptr1=ptr;
ptr=ptr->next;
if(ptr==NULL)
{
printf("\ncan't delete\n");
return;
}
}
ptr1->next=ptr->next;
free(ptr);
printf("\ndeleted node %d\n",loc+1);
}
void search()
{
struct node *ptr;
int item,i=0,flag;
ptr=head;
if(ptr==NULL)
{
printf("\nlist is empty\n");
}
else
{
printf("\nenter the item\n");
scanf("%d",&item);

while(ptr!=NULL)
{
if(ptr->data==item)
{
printf("\nitem found at location %d\n",i+1);
flag=0;
}
else
{
flag=1;
}
i++;
ptr=ptr->next;
}
if(flag==1)
{
printf("item not found");
}
}
}
void display()
{
struct node *ptr;
ptr=head;
if(ptr==NULL)
{
printf("list empty");
}
else
{
printf("\nprinting values\n");
while(ptr!=NULL)
{
printf("\n%d",ptr->data);
ptr=ptr->next;
}
}
}
