#include <stdio.h>  
#include <time.h>
int temp;  
  
void heap(int arr[], int size, int i)  
{  
	int largest = i;    
	int left = 2*i + 1;    
	int right = 2*i + 2;    
	  
	if (left < size && arr[left] >arr[largest])  
	largest = left;  
	  
	if (right < size && arr[right] > arr[largest])  
	largest = right;  
	  
	if (largest != i)  
	{  
	    temp = arr[i];  
		arr[i]= arr[largest];   
		arr[largest] = temp;  
		heap(arr, size, largest);  
	}  
}  
  
void heapSort(int arr[], int size)  
{  
	int i;  
	for (i = size / 2 - 1; i >= 0; i--)  
	heap(arr, size, i);  
	for (i=size-1; i>=0; i--)  
	{  
		temp = arr[0];  
		arr[0]= arr[i];   
		arr[i] = temp;  
		heap(arr, i, 0);  
	}  
}  
  
int main()  
{  

	int n;
	clock_t start,end;
    double timetaken;
    int rand(void);
	printf("enter the number of elements of array\n");
	scanf("%d",&n);
	int arr[n];  
	int i;  
	printf("Enter the array\n");
	for(i=0;i<n;i++)
	arr[i]=rand() % 2000 + 1; 
	 start=clock(); 
	heapSort(arr, n);  
	 end=clock(); 
	printf("printing sorted elements\n");  
	for (i=0; i<n; ++i)  
	printf("%d\n",arr[i]); 
	timetaken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\ntime taken = %f seconds",timetaken); 
	return 0;
}  
