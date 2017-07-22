#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		long long int l,d,s,c;
		scanf("%lld%lld%lld%lld",&l,&d,&s,&c);
		if(s>=d)
			printf("ALIVE AND KICKING\n");
		else
		{
			int flag=0;
			while(--d>0)
			{
				s=s+c*s;
				if(s>l)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				printf("ALIVE AND KICKING\n");
			else
				printf("DEAD AND ROTTING\n");
		}
	}
	return 0;
}