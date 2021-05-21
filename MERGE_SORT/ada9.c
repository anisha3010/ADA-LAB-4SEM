#include <stdio.h>
#include <time.h>
void sort(int a[],int,int);
void merge(int a[],int,int,int,int);
 
int main()
{
	int a[1000],n,i;
	int rand(void);
	clock_t start,end;
    double timetaken;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Entering array of random elements:");
	
	for(i=0;i<n;i++)
		a[i]=rand() % 2000 + 1;
	printf("unsorted array\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n\n");
	start=clock();	
	sort(a,0,n-1);
	end=clock();
	printf("\nSorted array is :");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
		
		timetaken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\ntime taken = %f seconds",timetaken);
		
	return 0;
}
 
void sort(int a[],int low,int high)
{
	int mid;
		
	if(low<high)
	{
		mid=(low+high)/2;
		sort(a,low,mid);		
		sort(a,mid+1,high);	
		merge(a,low,mid,mid+1,high);
	}
}
 
void merge(int a[],int low1,int high1,int low2,int high2)
{
	int temp[1000];	
	int i,j,k;
	i=low1;	
	j=low2;	
	k=0;
	
	while(i<=high1 && j<=high2)	
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=high1)	
		temp[k++]=a[i++];
		
	while(j<=high2)	
		temp[k++]=a[j++];
		
	
	for(i=low1,j=0;i<=high2;i++,j++)
		a[i]=temp[j];
}

