#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	scanf("%lld",&n);
	if(n==2)
		printf("Prime\n");
	else if(n%2==0)
		printf("Not Prime\n");
	else
	{
		ll val=n-1;
		int count=0;
		while(val%2==0)
		{
			count++;
			val>>=1;
		}
		ll x=2;
		for(int i=1;i<val;i++)
			x=(x*2)%n;
		if(x==1||x==n-1)
			printf("Prime\n");
		else
		{
			ll temp;int flag=0;
			for(int j=1;j<=count;j++)
			{
				temp=x;
				x=(x*x)%n;
				if(x==1)
				{
					if(temp==n-1)
						flag=1;
					break;
				}
			}
			if(flag==1)
				printf("Prime\n");
			else
				printf("Not Prime\n");
		}
	}
	return 0;
}