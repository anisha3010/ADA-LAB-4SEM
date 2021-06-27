
#include <stdio.h>


int max(int a, int b)
{
	return (a > b) ? a : b;
}


int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1]
						+ K[i - 1][w - wt[i - 1]],
						K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}


int main()
{
	int n,W,i;
	printf("Enter the number of weights/values\n");
	scanf("%d",&n);
	int val[n] ;
	int wt[n] ;
	printf("Enter the values\n");
	for(i=0;i<n;i++)
	scanf("%d",&val[i]);
	printf("Enter the weights in the right order\n");
	for(i=0;i<n;i++)
	scanf("%d",&wt[i]);
	printf("Enter the capacity\n");
	scanf("%d",&W);	
	printf("%d", knapSack(W, wt, val, n));
	return 0;
}

