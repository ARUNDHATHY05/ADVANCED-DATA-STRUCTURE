#include<stdio.h>
#include<stdlib.h>

#define SIZE 4
int top=-1,inp_arr[SIZE];
int push();
int pop();
int show();

int main()
{
int choice;
while(1)
{

printf("1.push\n2.pop\n3.show\n");
printf("enter the choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
show();
break;
case 4:
exit(0);
default:
printf("invalid input!");
}
}
}

int push()
{
int x;
if(top==SIZE-1)
{
printf("stack overflow\n");
}
else
{
printf("entr the elements to stack:\n");
scanf("%d",&x);
top=top+1;
inp_arr[top]=x;
}

return 0;
}

int pop()
{
if(top==-1)
{
printf("underflow!");
}
else
{
printf("the popped elemnt is %d\n",inp_arr[top]);
top=top-1;
}
return 0;
}


int show()
{
if(top==-1)
{
printf("underflow!");
}
else
{
printf("the elements present in stack are:\n");
for(int i=0;i<=top;i++)
printf("%d\n",inp_arr[i]);
}
return 0;
}
