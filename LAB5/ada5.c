#include <stdio.h>

int main()
{
    int i,j,n,key;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Sorting the array using insertion sort\n");
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("Array has been sorted as...\n");
    for (i = 0; i < n; i++) 
    { 
        printf("%d\n",arr[i]);
    }

    return 0;
}
