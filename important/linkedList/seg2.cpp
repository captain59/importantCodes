#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		long long int n;
		string str;
		scanf("%lld",&n);
		cin>>str;
		long long int arr[n+1]={0};
		arr[0]=str[0]-'0';
		long long int count=0;
		for(int i=1;i<str.length();i++)
		{
			arr[i]=arr[i-1]+(str[i]-'0');
		}
		for(int i=0;i<n+1;i++)
			printf("%d\t",arr[i] );
		for(int i=0;i<n+1;i++)
		{
			if(arr[i]<i)
			{
				count+=abs(i-arr[i]);
			}
		}
		printf("%lld\n",count );
	}
	return 0;
}