#include <stdio.h>
#include <stdlib.h>
int adj[10][10],n,indegree[10];
void sum_indegree()
{
	int i,j,sum;
	for(j=0;j<n;j++)
	{
		sum=0;
		for(i=0;i<n;i++)
		sum+=adj[i][j];
		indegree[j]=sum;
	}
}
void topsort()
{
	int i,p,q,t[10],stack[10],top=-1,k=0;
	sum_indegree();
	for(i=0;i<n;i++)
	{
	    if(indegree[i]==0)
	    stack[++top]=i;
	}
	while(top!=-1)
	{
	p=stack[top--];
	t[k++]=p;
	for(q=0;q<n;q++)
	{
	if(adj[p][q]==1)
	{
	indegree[q]--;
	if(indegree[q]==0)
	stack[++top]=q;
	}
	}
	}
	if(k!=n)
	{printf("Cycle detected! not possible\n");return;}
	printf("The topological sequence is:\n");
	for(i=0;i<n;i++)
	printf("node %d->",t[i]+1);
}
int main()
{
int i,j;
printf("Enter the no of nodes:\n ");
scanf("%d",&n);
printf("Enter the adjacency matrix:\n");
for(i=0;i<n;i++)

{
for(j=0;j<n;j++)
scanf("%d",&adj[i][j]);
}
topsort();
return 0;
}
