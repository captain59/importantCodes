#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int x,y,k,n;
		scanf("%d%d%d%d",&x,&y,&k,&n);
		int remaining=x-y;
		int a,b;int flag=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a>=remaining&&b<=k)
				flag=1;
		}
		if(remaining==0)
			flag=1;
		if(flag==1)
			printf("LuckyChef\n");
		else
			printf("UnluckyChef\n");
	}
	return 0;
}