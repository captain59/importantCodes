#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m<=n)
	{
		printf("%d\n",n-m);
	}
	else
	{
		count=0;
		if(m%2==0)
		{
			int i=m;
			while(i>n)
			{
				i=i/2;
				count++;
				if(i%2==1)
				{
					i--;
					count++;
				}
			}

		}
	}
	return 0;
}