#include<stdio.h>
int front=-1,rear=-1,max,item;
int cqueue[20];
void insert();
void deletion();
void search();
void display();



void insert()
{
  int temprear=rear;
  rear=(rear+1)%(max);
  if(front==-1)
  {
    front=0;
    rear=0;
    printf("\nEnter the element:");
    scanf("%d",&item);
    cqueue[rear]=item;
  }
  else if(rear==front)
  {
   printf("\noverflow");
   rear=temprear;
  }
  else
  {
   printf("\nEnter the element:");
   scanf("%d",&item);
   cqueue[rear]=item;
  }
}

void deletion()
{
 if(front==-1)
 {
  printf("underflow");
 }
 else if(front==rear)
 {
  printf("deleting element is %d",cqueue[front]);
  front=-1;
  rear=-1;
 }
 else
 {
 
 printf("deleting element is %d",cqueue[front]);
 front=(front+1)%max;
 }
} 



void display()
{
 int i=front;
 if(front==-1)
 {
  printf("Queue empty");
 }
 else
 {
  for(;i!=rear;i=((i+1)%(max)))
  {
   printf("\n%d",cqueue[i]);
  }
  printf("\n%d",cqueue[i]);
 }
} 



void search()
{
 int data,i=1,dfront=front;
 printf("\nEnter element:");
 scanf("%d",&data);
 if(front==-1)
 {
  printf("queue is empty:");
 }
 else
 {
  for(;dfront!=rear;dfront=((dfront+1)%(max)))
  {
   if(cqueue[dfront]==data)
   {
    printf("\nelement found at position %d",i);
   }
   i++;
  }
  if(cqueue[dfront]==data)
  {
   printf("\nElement found at pos %d",i);
  }
 }
}



int main()
{
 int choice;
 printf("Enter size of queue:");
 scanf("%d",&max);
 do
 {
  printf("\n1.Insertion \n2.Deletion \n3.Search \n4.Display \n5.Exit \nEnter your choice ");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:insert();
 	 break;
  case 2:deletion();
         break;
  case 3:search();
 	 break;
  case 4:display();
         break;
  case 5:printf("exiting");
         break;
  default:printf("\ninvalid");
  }
 }
 while(choice!=5);
 return 0;
 
}
