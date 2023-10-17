#include<stdio.h>
int main()
{
int arr[50],i,mid,first,last,search,n;
printf("entr the no of elemnts in array:");
scanf("%d",&n);
printf("enter the elements in array in ascending order:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);

printf("enter the elemt to be searched:");
scanf("%d",&search);
first=0;
last=n-1;
mid=first+last/2;
while(first<=last)
{
if(arr[mid]>search)
{
last=mid-1;
}
else if(arr[mid]==search)
{
printf("%d found at position %d",search,mid);
break;
}
else
{
first=mid+1;
mid=first+last/2;
}
}
if(first>last)
{
printf("%d element not found!",search);
}

return 0;
}


