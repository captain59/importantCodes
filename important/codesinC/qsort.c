#include <stdio.h>
#include <stdlib.h>

int partition(int arr[],int l,int h)
{
	int x=arr[h-1];
	int pos=l-1;;
	for(int i=l;i<h;i++)
	{
		if(arr[i]<=x)
		{
			pos++;
			swap(&arr[i],&arr[pos]);
		}
	}
}

void quicksort(int arr[],int l,int h)
{
	if(l<h)
	{
		int m=partition(arr,l,h);
		quicksort(arr,l,p);
		quicksort(arr,p+1,h);
	}
}
int main()
{
	srand( (unsigned)time( NULL ) );
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=rand()%100;
	quicksort(arr,0,n);
	return 0;
}