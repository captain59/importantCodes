#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define mod 1000000007
int main()
{
	long long int two[100001];
	two[0]=1;
	for(int i=1;i<100001;i++)
		two[i]=(two[i-1]*2)%mod;
	
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n;
		scanf("%d",&n);
		long long int arr[n];
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		sort(arr,arr+n);
		long long int ans=0,val;
		for(int i=1;i<n+1;i++)
		{
			if(i-1>=n-i)
			{
				if(two[i-1]<two[n-i])
					val=arr[i-1]*(two[i-1]+mod-two[n-i]);
				else
					val=arr[i-1]*(two[i-1]-two[n-i]);
			}
			else
				{
					if(two[i-1]>two[n-i])
						val=arr[i-1]*(two[i-1]-two[n-i]-mod);
					else
						val=arr[i-1]*(two[i-1]-two[n-i]);
				}
			if(val>mod)
				val=val%mod;
			if(val<(-1)*mod)
				val+=mod;
			ans+=val;
			ans=ans%mod;

		}
		if(ans<0)
			ans=ans+mod;
		ans=ans%mod;
		printf("%lld\n",ans);
	}
	return 0;
} 