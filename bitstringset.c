#include <stdio.h>
#include <stdlib.h>

int main(){
	int setU[10],setA[10],setB[10],unionAB[10],intersection[10],diffAB[10],diffBA[10],i,j,flag;
	int u[10]={1,2,3,4,5,6,7};
	int a[10]={2,3,4};
	int b[10]={3,4,5,6};
	

	for(i=0;i<7;++i){
		setU[i]=1;
	}
	printf("Universal bit set\n    	");
	for(i=0;i<7;++i){
		printf("%d ",setU[i]);
	}

	//set A
	for(i=0;i<7;++i)
	{
		flag=0;
		for(j=0;j<7;++j)
		{

			if(u[i]==a[j])
			{
				flag=1;
				break;
			}
		}
			if(flag==1)
			{
				setA[i]=1;
			}
			else
			{
				setA[i]=0;
			}
		}
	printf("\nBit set A\n	   ");
	for(i=0;i<7;++i)
	{
		printf("%d ",setA[i]);
	}

	//set B
	for(i=0;i<7;++i)
	{
		flag=0;
		for(j=0;j<7;++j)
		{

			if(u[i]==b[j])
			{
				flag=1;
				break;
			}
		}
			if(flag==1)
			{
				setB[i]=1;
			}
			else
			{
				setB[i]=0;
			}
		}

	printf("\nBit set B\n	   ");
	for(i=0;i<7;++i)
	{
		printf("%d ",setB[i]);
	}

	//Union of A and B

	printf("\nUnion of A and B\n	   ");
	for(i=0;i<7;++i)
	{
		unionAB[i]=setA[i]|setB[i];
		printf("%d ",unionAB[i]);
	}

	//Intersection of A and B
	printf("\nIntersection of A and B\n	   ");
	for(i=0;i<7;++i)
	{
		intersection[i]=setA[i]&setB[i];
		printf("%d ",intersection[i]);
	}

	//Difference of A and B
	printf("\nDifference  A - B\n	   ");
	for(i=0;i<7;++i)
	{
		if(setA[i]==1 && setB[i]==0)
		{
			diffAB[i]=1;
		}
		else
		{
			diffAB[i]=0;
		}
		printf("%d ",diffAB[i]);
	}


	//Difference of B and A
	printf("\nDifference  B - A\n	   ");
	for(i=0;i<7;++i)
	{
		if(setB[i]==1 && setA[i]==0)
		{
			diffBA[i]=1;
		}
		else
		{
			diffBA[i]=0;
		}
		printf("%d ",diffBA[i]);
	}




	return 0 ;

}
