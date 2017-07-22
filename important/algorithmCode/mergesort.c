#include <stdio.h>
#include <stdlib.h>
void merge(int arr[],int low,int mid,int high)
{
	int n=sizeof(arr)/sizeof(arr[0]);
	int temp[n];
	int i=low,l=low,m=mid+1;
	while(l<=mid&&m<=high)
	{
		if(arr[l]<=arr[m])
		{
			temp[i]=arr[l];
			l++;
		}
		else
		{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}
	if(l>mid)
	{
		for(int k=m;k<=high;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(int k=l;k<=mid;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	for(int k=low;k<=high;k++)
		arr[k]=temp[k];	
}
void partition(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		merge(arr,low,mid,high);
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
	partition(arr,0,n-1);
	printf("\n\tSorted Array\n");
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}