#include <stdio.h>
#include <time.h>
int main()
{
    clock_t start,end;
    double timetaken;
	int rand(void);
    int i,j,n,key;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Printing random valued array\n");
    for(i=0;i<n;i++)
    {
        arr[i]=rand() % 1000 + 1;
        printf("%d\t",arr[i]);
    }
    printf("Sorting the array using insertion sort\n");
    start=clock();
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
     end=clock();
    printf("Array has been sorted as...\n");
    for (i = 0; i < n; i++) 
    { 
        printf("%d\t",arr[i]);
    }
	timetaken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\ntime taken = %f",timetaken);
    return 0;
}
