#include <stdio.h>
#include <conio.h>
void unionjk(int u,int v);
int find(int);
int parent[10];


void main()
{
    int n,i,j,k,mincost,x,costs,u,v,m,temp;
	int cost[10][10],t[10][2],heap[10],U[10],V[10];

	clrscr();
	//Enter number of vertices
	printf("Enter number of vertices\n");
	scanf("%d",&n);


	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			cost[i][j]=-1;
		}
	}
	//cost of edges
	x=0;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(cost[i][j]==-1)
			{
				printf("Enter the cost of edge( %d,%d )",i,j);
				scanf("%d",&cost[i][j]);
				if(cost[i][j]==0)
				{
					cost[i][j]=999; //cost(1,1)=infinity

				}
				else
				{
							     //if edge is (1,2) and cost[1][2]=3
					heap[x]=cost[i][j];  //store cost of edge (ie 3) in an array heap
					U[x]=i;              //store vertex (ie 1) in an array U
					V[x]=j;              //store vertex (ie 2) in an array V
					x++;
				}
				cost[j][i]=cost[i][j];
			}
		}
	}

	//print cost of edges
	printf("Cost Adjacency Matrix\n");
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
				printf("%d ",cost[i][j]);
		}
		printf("\n");
	}
	//initialize parent of each node to -1
	for(i=1;i<=n;++i)
	{
		parent[i]=-1;
	}
	/* print parent of each node

	for(i=1;i<=n;++i)
	{
		printf("%d ",parent[i]);
	}
	printf("\n"); */


	//sort costs in heap array
	for(i=0;i<x;++i){
		for(j=i+1;j<x;++j){
			if(heap[i]>heap[j]){
				temp=heap[i];
				heap[i]=heap[j];
				heap[j]=temp;

				//swap array U with respect to heap
				temp=U[i];
				U[i]=U[j];
				U[j]=temp;

				//swap array V with respect to heap
				temp=V[i];
				V[i]=V[j];
				V[j]=temp;


			}

		}

		       printf("%d<- %d-> %d\n",U[i],heap[i],V[i]);
	}
	m=0;  //m is the index for spanning tree
	mincost=0;
	while(m<n-1)
	{
	for(i=0;i<x;++i)
	{
	       heap[i]=0;   //delete edge with minimum cost(make it null)
		u=U[i];     //corresponding vertex of minimum cost edge
		v=V[i];     //corresponding vertex of minimum cost edge
		j=find(u);
		k=find(v);
		//printf("%d %d\n",j,k);
		if(j!=k)    //j and k on different set
		{
		   m=m+1;
		   t[m][1]=u; //add vertex to spanning tree
		   t[m][2]=v; //add vertex to spanning tree
		   mincost=mincost+cost[u][v];
		   //printf("\n%d \n",mincost);
		   unionjk(u,v);

		}

	}
	}

	if(m!=n-1)
		printf("No spanning tree\n");
	else
	{
		for(i=1;i<n;++i)
		{
		    printf("Cost of edge( %d,%d ): %d \n",t[i][1],t[i][2],cost[t[i][1]][t[i][2]]);
		}
		printf("Mincost : %d ",mincost);
	}

	getch();
}

int find(u)
{
	if(parent[u]==-1)  //single node
	{
		parent[u]=u;
	}

	return parent[u];
}

void unionjk(int u,int v)
{
	parent[v]=parent[u]; //make same parent for u and v
}
