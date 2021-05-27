#include <stdio.h>
#include <stdlib.h>
int flag=0;
int counter=0;
int a[20][20],reach[20],n;
void dfs(int v)
{
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
	if(a[v][i])
	{
		if(reach[i]==1 && counter==0)
		{printf("cycle detected!\n");
		flag=1;
		exit(0);}
		else
		dfs(i);
		counter++;
	}
}
int main()
{
	int i,j;
	printf("\n Enter number of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		reach[i]=0;
		for(j=1;j<=n;j++)
		a[i][j]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	dfs(1);
	
	if(flag==0)
	printf("No cycles");
	
	return 0;
}
