#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linsrch(int a[], int n, int el)
{
    if(n>=0)
    {
        if(a[n-1] == el)
        {
            return n;
        }
 
        else
        {
            return linsrch(a, n-1, el);
        }
 
        n--;
    }
    else return -1;
}
int binsrch(int arr[], int l, int h, int x)
{
   if (h >= l)
   {
        int mid = (l + h)/2;
        if (arr[mid] == x)  
        return mid;
        
        else if (arr[mid] > x) 
        return binsrch(arr, l, mid-1, x);
        
        else return binsrch(arr, mid+1, h, x);
   }
  
   else return -1;
}
int main()
{
	 clock_t lstart,lend,bstart,bend;
    double btimetaken,ltimetaken;
	int rand(void);
	int ele,pos,pos1,i,j,n;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("Creating array of  random numbers from range[1,1000]\n");
	for(j=0;j<=n-1;j++)
	{
		arr[j]=rand() % 1000 + 1;
	}
	printf("Printing the numbers...\n");
	for(j=0;j<=n-1;j++)
	{
		printf("%d\t",arr[j]);
	}
		printf("Performing linear search\n");
			printf("enter the number to be searched[1-1000]\n");
			scanf("%d",&ele);
			lstart=clock();
			pos=linsrch(arr,n,ele);
			lend=clock();
			if((pos)==-1)
			printf("Element not found!\n");
			else printf("element found at %d position \n",pos);
		printf("Performing binary search\n");
			printf("enter the number to be searched[1-100]\n");
			scanf("%d",&ele);
			int min,temp;
	        printf("Sorting the array to perform binary search\n");
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
        	for (i = 0; i <= n-1; i++) 
            { 
        		printf("%d\t",arr[i]);
        	}
        	bstart=clock();
			pos1=binsrch(arr,0,n-1,ele);
			bend=clock();
			if((pos1)==-1)
			printf("Element not found!\n");
			else printf("element found at %d index \n",pos1);
			
			ltimetaken=((double)(lend-lstart))/CLOCKS_PER_SEC;
			printf("\ntime taken linear search = %f\n",ltimetaken);
			btimetaken=((double)(bend-bstart))/CLOCKS_PER_SEC;
			printf("\ntime taken binary search = %f\n",btimetaken);
			
	return 0;
}

