#include <stdio.h>
 int findPivot(int arr[], int low, int high)
{

    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}

int binsrch(int arr[], int low, int high, int ele)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2; 
    if (ele == arr[mid])
        return mid;
    if (ele > arr[mid])
        return binsrch(arr, (mid + 1), high, ele);
    return binsrch(arr, low, (mid - 1), ele);
}

int pivbinsrch(int arr[], int n, int ele)
{
    int pivot = findPivot(arr, 0, n - 1);
    if (pivot == -1)
        return binsrch(arr, 0, n - 1, ele);
    if (arr[pivot] == ele)
        return pivot;
    if (arr[0] <= ele)
        return binsrch(arr, 0, pivot - 1, ele);
    return binsrch(arr, pivot + 1, n - 1, ele);
}
 
int main()
{
    int n,key,el;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("enter the element to be searched\n");
    scanf("%d",&key);
    el=pivbinsrch(arr,n,key);
    if(el==-1)
    printf("element not found\n");
    else
    {
    printf("Index of the element is : %d", el);
    }
    return 0;
}
