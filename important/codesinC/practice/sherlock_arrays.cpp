#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n;
		scanf("%d",&n);
		int a[n];long long int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(n==1)
			printf("YES");
		else
		{
		long long int s=0,sum1;int flag=0;
		for(int i=1;i<n;i++)
		{
			s=s+a[i-1];
			sum1=sum-s-a[i];
			if(sum1==s)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	}
	return 0;
}