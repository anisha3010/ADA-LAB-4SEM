#include <stdio.h>
#include <stdlib.h>

 
 int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1, fr = -1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else 
        {
            fr = mid;
            high = mid - 1;
        }
    }
    return fr;
}
 
int last(int arr[], int x, int n)
{
    int low = 0, high = n - 1, lst = -1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else 
        {
            lst = mid;
            low = mid + 1;
        }
    }
    return lst;
}
 
int main()
{
    int n,i,x,count,f,l;
    printf("enter the length of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
	printf("Enter the element to search\n");
	scanf("%d",&x);
	if(first(arr,x,n)==-1)
	printf("element not found!\n");
	else
	{
		f= first(arr, x, n);
		l= last(arr, x, n);
		printf("First Occurrence = %d\n",f);
		printf("Last Occurrence = %d\n",l);
		count=l-f+1;
	    printf("Frequency of element is %d\n",count);
	}
 
    return 0;
}
