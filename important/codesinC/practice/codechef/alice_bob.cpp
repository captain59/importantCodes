#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	long long int n,sum=0;int count=0;
	scanf("%lld",&n);
	while(n>9)
	{
		for(long long int i=n;i>0;i/=10)
			sum+=(long long int)pow(n%10,2);
		n=sum;
		sum=0;
		count++;
	}
	if(n==1)
		printf("%d\n",count );
	else if(n==7)
		printf("%d\n",count+5);
	else
		printf("-1\n");
	return 0;
}