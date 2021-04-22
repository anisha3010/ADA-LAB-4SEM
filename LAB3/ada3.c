#include <stdio.h>

int main()
{
    int i,j,min,n,temp;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Sorting the array using selection sort\n");
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
        {
        	if (arr[j] < arr[min]) 
        	min = j;
        }
          
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    } 
    printf("Array has been sorted as...\n");
    for (i = 0; i < n; i++) 
    { 
        printf("%d\n",arr[i]);
    }

    return 0;
}
