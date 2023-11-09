#include<stdio.h>
int i,setA[10],setB[10],setC[20],pa,pb,m,n;
void create();
void unionset();
void find();
int main()
{
	int c;
	while(1)
	{
	printf("\n1.creation\n2.union\n3.find\n4.exit\n");
		printf("enter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			create();
			break;
			case 2:
			unionset();
			break;
			case 3:
			find();
			break;
			case 4:
			return 0;

			default:
			printf("\n invalid choice\n");
		}
	}
return 0;
}
void create()
{
	printf("enter the limit of first set:");
	scanf("%d",&m);
	printf("enter the first set:\n");
	for(i=1;i<=m;i++)
		scanf("%d",&setA[i]);
	printf("enter the limit of second set:");
	scanf("%d",&n);
	printf("enter the second set:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&setB[i]);
	printf("\nSET A:{");
	for(i=1;i<=m;i++)
		printf("%d,",setA[i]);
	printf("}\n");
	printf("SET B:{");
	for(i=1;i<=n;i++)
		printf("%d,",setB[i]);
	printf("}\n");
}
void unionset()
{
	int j;
		for(i=1;i<=m;i++)
			setC[i]=setA[i];
		j=m+1;
		for(i=1;i<=n;i++)
		{
			setC[j]=setB[i];
			j++;
		}
		printf("\nUNIONSET:{");
		for(i=1;i<=m+n;i++)
			printf("%d,",setC[i]);
		printf("}\n");
}
void find()
{
	int item,f=-1;
	printf("enter the element:");
	scanf("%d",&item);
	for(i=1;i<=m;i++)
	{
		if(item==setA[i])
		{
			printf("\nPARENT IS:%d",setA[1]);
			f=1;
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(item==setB[i])
		{
			printf("\nPARENT IS:%d",setB[1]);
			f=1;
			break;
		}
	}
	if(f<0)
		printf("\nthere is no such element in the set");
}
