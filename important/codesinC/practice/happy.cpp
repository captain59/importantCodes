#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int sum=0;int count=0;
	while(n>9)
	{
		for(long long int i=n;i>0;i=i/10)
		{
			sum+=(i%10)*(i%10);
		}
		n=sum;
		sum=0;
		count++;
	}
	if(n==1)
		printf("%d\n",count);
	else if(n==7)
		printf("%d\n",count+5 );
	else
		printf("-1\n");
	return 0;
}