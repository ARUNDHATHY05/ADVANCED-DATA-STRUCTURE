#include<stdio.h>
#include<stdlib.h>
int main()
{
int a[10],n,i,no;
printf("enter the number of elements\n");
scanf("%d",&no);
printf("enter the elemnts\n");
for(i=0;i<no;i++)
{
scanf("%d",&a[i]);
}
printf("enter the element to be searched:");
scanf("%d",&n);
for(i=0;i<no;i++)
{
if(a[i]==n)
{
printf("%d is present in position %d",n,i+1);
}
}

if(i!=n)
{
printf("%d not present in array",n);
}
return 0;
}
