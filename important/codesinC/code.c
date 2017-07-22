#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
int search(int arr[],int x,int l,int h)
{
	if(l<=h)
	{
		int m=(l+h)/2;
		if(arr[m]==x)
			return 1;
		else if(arr[m]<x)
			search(arr,x,m+1,h);
		else if(arr[m]>x)
			search(arr,x,l,m-1);
	}
	else
		return -1;
}
int main()
{
	time_t t;
	srand((unsigned)time(&t));
	int n,x;
	scanf("%d",&n);
	int arr[n]={0};
	printf("\nBEFORE SORTING\n");
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%10;
		printf("%d\t",arr[i] );
	}
	printf("\n");
	scanf("%d",&x);
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int temp=arr[i];
		while(j>=0&&temp<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	printf("\nAFTER SORTING\n");
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i] );
	printf("\n");
	if(search(arr,x,0,n-1)==1)
		printf("Element is present\n");
	else
		printf("Element is not present\n");
	return 0;
}