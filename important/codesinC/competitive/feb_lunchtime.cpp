#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		long maxr,maxs;int n;
		scanf("%ld%ld%d",&maxr,&maxs,&n);
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);int countr=0,counts=0;long remr,rems;
		for(int i=0;i<n;i++)
		{
			remr=maxr-a[i];
			rems=maxs-a[i];
			maxr-=a[i];
			maxs-=a[i];
			if(remr>=0)
				countr++;
			if(rems>=0)
				counts++;
		}
		if(countr>counts)
			printf("Raghu Won\n");
		else if(counts>countr)
			printf("Sayan Won\n");
		else
			printf("Tie\n");
	}
	return 0;
}