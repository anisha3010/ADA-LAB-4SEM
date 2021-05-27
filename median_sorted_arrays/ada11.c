#include <stdio.h>
#include <math.h>

int median(int [], int); 
int max(int a, int b)
{
	if(a>b)
	return a;
	else return b;
}
int min(int a, int b)
{
	if(a<b)
	return a;
	else return b;
}
int getMedian(int ar1[], int ar2[], int n)
{
	
	if (n <= 0)
		return -1;
	if (n == 1)
		return (ar1[0] + ar2[0])/2;
	if (n == 2)
		return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

	int m1 = median(ar1, n); 
	int m2 = median(ar2, n); 

	
	if (m1 == m2)
		return m1;


	if (m1 < m2)
	{
		if (n % 2 == 0)
			return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);
		return getMedian(ar1 + n/2, ar2, n - n/2);
	}

	
	if (n % 2 == 0)
		return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);
	return getMedian(ar2 + n/2, ar1, n - n/2);
}


int median(int arr[], int n)
{
	if (n%2 == 0)
		return (arr[n/2] + arr[n/2-1])/2;
	else
		return arr[n/2];
}


int main()
{
	int n;
	printf("Enter the length of both the arrays(has to be the same else wont work)\n");
	scanf("%d",&n);
	int ar1[n],ar2[n];
	printf("enter array 1\n");
	for(int i=0;i<n;i++)
	scanf("%d",&ar1[i]);
	printf("enter array 2\n");
	for(int i=0;i<n;i++)
	scanf("%d",&ar2[i]);
	
	printf("Median is %d", getMedian(ar1, ar2, n));
	
	return 0;
}

