#include <bits/stdc++.h>
using namespace std;

int merge(int *arr,int low,int mid,int high)
{
	int count=0;
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
			count++;
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
	return count;
}
int partition(int *arr,int low,int high)
{
	int mid;
	int count=0;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		count+=merge(arr,low,mid,high);
	}
	return count;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++)cin>>arr[i];
		int count=partition(arr,0,n-1);
		for(int i=0;i<n;i++)cout<<arr[i]<<" ";
		cout<<"\n"<<count<<endl;
	}
	return 0;
}