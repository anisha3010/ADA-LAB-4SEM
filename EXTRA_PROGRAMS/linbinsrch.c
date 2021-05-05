#include <stdio.h>
#include <stdlib.h>
void linsrch(int arr[], int n)
{
	int flag=0;
	for(int i=0;i<20;i++)
	{
		if(arr[i]==n)
		{
			printf("Number found at %d index of array\n",i);
			flag=1;
			return;
		}
	}
	if(flag==0)
	printf("Sorry! number doesn't exist\n");
}
void binsrch(int arr[], int n)
{
	int f,l,m,i,j,min,temp;
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
	for (i = 0; i < 19; i++) 
    { 
		printf("%d\n",arr[i]);
	}
	f = 0;
    l = 19;
    m = (f+l)/2;

    while (f <= l) 
    {
		if (arr[m] < n)
		  f = m + 1;
		else if (arr[m] == n) 
		{
		  printf("%d found at location %d.\n", n, m+1);
		  break;
		}
		else
		  l = m - 1;

		m = (f + l)/2;
	  }
	  if (f > l)
		printf("Not found! %d isn't present in the list.\n", n);
}
int main()
{
	int arr[20],ch,ele,j;
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
			linsrch(arr,ele);
			break;
			
			case 2:
			printf("enter the number to be searched[1-100]\n");
			scanf("%d",&ele);
			binsrch(arr,ele);
			break;
			
			case 3:
			break;
			
			default:
			printf("Wrong choice!\n");
		}
	}while(ch!=3);
	return 0;
}
