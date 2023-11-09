#include<stdio.h>

int main()
{
 int n,item,i;
 int a[50];
 printf("Enter the size of array:");
 scanf("%d",&n);
 printf("Enter the value\n");
 for(i=0;i<n;i++)
 
 scanf("%d",&a[i]);
 printf("Enter the item to be searched:");
 scanf("%d",&item);
 for(i=0;i<n;i++)
 {
  if(a[i]==item)
  {
   printf("Search Successfull\n");
   printf("Item Found At Position %d\n",i+1);
   break;
  }
 } 
 if(a[i]!=item)
 {
  printf("Item Not Found!!\n");
 }
}
