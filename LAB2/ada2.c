#include <stdio.h>
#include <stdlib.h>

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
	int arr[20],ch,ele,pos,pos1,i,j;
	printf("Creating array of 20 random numbers from range[1,100]\n");
	for(j=0;j<=19;j++)
	{
		arr[j]=rand() % 100 + 1;
	}
	printf("Printing the numbers...\n");
	for(j=0;j<=19;j++)
	{
		printf("%d\n",arr[j]);
	}
	do
	{
		printf("Performing linear search(1) and binary search(2), 3-Exit\nEnter option\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("enter the number to be searched[1-100]\n");
			scanf("%d",&ele);
			pos=linsrch(arr,20,ele);
			if((pos)==-1)
			printf("Element not found!\n");
			else printf("element found at %d position \n",pos);
			break;
			
			case 2:
			printf("enter the number to be searched[1-100]\n");
			scanf("%d",&ele);
			int min,temp;
	        printf("Sorting the array to perform binary search\n");
        	for (i = 0; i < 19; i++) 
            { 
                min = i; 
                for (j = i+1; j < 20; j++) 
                {
        			if (arr[j] < arr[min]) 
        				min = j;
        		}
          
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            } 
        	printf("Array has been sorted as...\n");
        	for (i = 0; i <= 19; i++) 
            { 
        		printf("%d\n",arr[i]);
        	}
			pos1=binsrch(arr,0,19,ele);
			if((pos1)==-1)
			printf("Element not found!\n");
			else printf("element found at %d index \n",pos1);
			break;
			
			case 3:
			break;
			
			default:
			printf("Wrong choice!\n");
		}
	}while(ch!=3);
	return 0;
}
