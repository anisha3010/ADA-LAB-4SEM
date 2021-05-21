#include <stdio.h>
#include <time.h>
void quicksort(int arr[1000],int f,int l)
{
   int i, j, pivot, temp;

   if(f<l)
   {
      pivot=f;
      i=f;
      j=l;

      while(i<j)
      {
         while(arr[i]<=arr[pivot]&&i<l)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j)
         {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,f,j-1);
      quicksort(arr,j+1,l);

   }
}

int main(){
   int i, n, arr[1000];
   int rand(void);
	clock_t start,end;
    double timetaken;
    
   printf("Enter the number of elements?:\n");
   scanf("%d",&n);

   printf("Entering random elements: \n");
   for(i=0;i<n;i++)
      arr[i]=rand() % 2000 + 1;
	printf("unsorted array\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
		printf("\n\n");
	start=clock();
   quicksort(arr,0,n-1);
   end=clock();

   printf("Order of Sorted elements:\n");
   for(i=0;i<n;i++)
      printf(" %d",arr[i]);
      
      timetaken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\ntime taken = %f seconds",timetaken);

   return 0;
}
