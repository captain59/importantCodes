#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		string str;
		cin>>str;
		int n;
		scanf("%d",&n);
		int count=0;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='T')
				count+=2;
			else
				count++;
		}
		long long int output=0;long long int d;long long int k=(12*n)/count;
		while(k>=1)
		{
			for(long long int i=12*n-1;i>=count*k;i--)
			{
				d=i/(count*k);
				if(d==0)
					break;

				output+=1;
			}
			k--;
		}
		printf("%lld\n",output);
		
	}
	return 0;
}