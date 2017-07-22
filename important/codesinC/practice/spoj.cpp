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
		long long int a,b,rem;
		scanf("%lld%lld",&a,&b);
		if(sqrt(a)==floor(sqrt(a)))
			printf("YES\n");
		else
		{
		rem=a%b;
		if(sqrt(rem)==floor(sqrt(rem)))
			printf("YES\n");
		else
			printf("NO\n");
		}
	}
	return 0;
}