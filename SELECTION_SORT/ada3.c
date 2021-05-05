#include <stdio.h>
#include <time.h>


int main(){
    clock_t start,end;
    double timetaken;
	int rand(void);
    
    int  n,temp,min,i,j;
    printf("SELECTION SORT\n");
    printf("Enter the total elements ");
    scanf("%d", &n);
    int arr[n];
    printf("Generating array elements\n");
    for (i = 0; i < n; i++)
    {
        arr[i]=rand() % 1000 + 1;
        printf("%d\t",arr[i]);
    }
    start=clock();
    
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
	 end=clock();			
      
    printf("\n\n\nSorted Array:\n");
    for (i=0; i < n; i++)
    {
      printf("%d\t",arr[i]);
    }  
      
   
    timetaken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\ntime taken = %f",timetaken);
    return 0;
}

