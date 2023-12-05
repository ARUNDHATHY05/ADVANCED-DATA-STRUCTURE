#include<stdio.h>
#include<stdlib.h>
int q[10],visited[10],i,j,n,adj[10][10],front=1,rear=0,v,item;
void insert(int v)
{
	rear++;
	q[rear]=v;
}
int get()
{
	v= q[front];
	front++;
	return v;
}
int main()
{
	printf("Total no of vertices :: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		 visited[i]=0;
	printf("\nenter the adjacency matrix!\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				scanf("%d",&adj[i][j]);
		}
	}
	printf("spanning tree edges are:\n");
	//printf("\nselect a starting vertex from 1 to  %d:",n);
	insert(1);
	for(i=1;i<=n;i++)
	{
		item=get();
		visited[item]=1;
		for(j=i+1;j<=n;j++)
		{
			if(adj[item][j]==1 && visited[j]==0)
			{
				visited[j]=1;
				insert(j);
				printf("edge(%d,%d)\n",item,j);
			}
		}
	}
	printf("\n");
return 0;
}
