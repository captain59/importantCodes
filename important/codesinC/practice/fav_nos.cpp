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
		long long int n,s,k;
		scanf("%lld%lld",&n,&s);
		k=n;
		while(s>0)
		{
			s=s-k;
			k--;
			if(s-k<0)
				break;
		}
		printf("%lld\n",k);
	}
	return 0;
}