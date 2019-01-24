#include<stdio.h>

int binarySearch(int a[], int key, int low, int high)
{
    if (high <= low)
        { 
          if(key > a[low])
         	return (low +1);
          else
          	return low;
 		}
    int mid = (low + high)/2;
 
    if(key == a[mid])
        return mid+1;
 
    if(key > a[mid])
        return binarySearch(a, key, mid+1, high);
    else
    return binarySearch(a, key, low, mid-1);
}

void insertionSort(int a[],int n)
{
	int i,j,location,number;

    for(i=1;i<n;i++)
    {
        j = i - 1;
        number = a[i];
        location = binarySearch(a ,number, 0, j);

        while (j >= location)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = number;
    }
}
	



void main()
{
	int a[100];
	int n,i;
	printf("Enter no. of data:");
	scanf("%d",&n);
	printf("Now enter Data:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	insertionSort(a,n);
	printf("Sorted Data:\n");
	for(i=0;i<n;i++)
		printf("%d,",a[i] );

}