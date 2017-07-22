#include <iostream>
#include <stdio.h>
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
		string pattern="",text="";
		cin>>text;
		cin>>pattern;
	int a[26]={0};
	for(int i=0;i<text.length();i++)
		a[text[i]-97]++;
	int flag=0;
	for(int i=0;i<pattern.length();i++)
	{
		if(a[pattern[i]-97]!=0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("YES\n");
	else
		printf("NO\n");
	}
	return 0;
}