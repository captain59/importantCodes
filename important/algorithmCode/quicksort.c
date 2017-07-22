#include <stdio.h>
#include <stdlib.h>
void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int partition(int arr[],int s,int e)
{
	int pivot=arr[e];
	int pind=s;
	for(int i=s;i<e;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(arr,i,pind);
			pind++;
		}
	}
	swap(arr,pind,e);
	return pind;
}
void quicksort(int arr[],int start,int end)
{
	if(start<end)
	{
		int tindex=partition(arr,start,end);//calling partition
		quicksort(arr,start,tindex-1);
		quicksort(arr,tindex+1,end);
	}
}
int main()
{
	int n;
	printf("Enter the number of terms\n");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	printf("\n\tSorted Array\n");
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}