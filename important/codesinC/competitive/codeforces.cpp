#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	char str[n];
	scanf("%s",str);
	int a[26]={0};char c;
	for (int i = 0; i < n; ++i)
	{
		if(str[i]>=65&&str[i]<=90)
		{
			a[str[i]-65]++;
		}
		else if(str[i]>=97&&str[i]<=122)
		{
			a[str[i]-97]++;
		}
	}
	int flag=0;
	for(int i=0;i<26;i++)
	{
		if(a[i]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}