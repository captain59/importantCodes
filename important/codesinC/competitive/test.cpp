#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int add(int b[],int l,int r)
{
	int s=0;
	for(int i=l;i<=r;i++)
		s+=b[i];
	return s;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int x,y,n;
		scanf("%d %d %d",&x,&y,&n);
		switch(y)
		{
			case 0:
					printf("0\n");
					break;
			case 1:
					if(n<=x)
						printf("%d\n",x);
					else
					{
						int sum=0;
						int a[50]={1};
						for(int i=x+1;i<=n;i++)
						{
							sum=add(a,i-x-1,i-1);
							a[i-1]=sum;
						}
						printf("%d\n",sum );
					}
					break;
			case 3:
					if(n<=x)
						printf("%d\n",x);
					else
					{
						int sum=0;
						int a[50]={2};
						for(int i=x+1;i<=n;i++)
						{
							sum=add(a,i-x-1,i-1);
							a[i-1]=sum;
						}
						printf("%d\n",sum );
					}
					break;
		}
	}
	return 0;
}