#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n;int flag=0;
		scanf("%d",&n);
		string colors[n];
		for(int i=0;i<n;i++)
			cin>>colors[i];
		string str="";
		cin>>str;
		int a[26]={0};
		for(int i=0;i<str.length();i++)
			a[str[i]-97]++;
		for(int i=0;i<n;i++)
		{
			string word=colors[i];
			for(int j=0;j<26;j++)
			{
				if(a[j]!=0)
				{
					int c=count(word.begin(),word.end(),(char)(j+97));
					if(c<a[j])
					{
						flag=1;
						break;
					}
				}
			}
			if(flag==0)
			{
				cout<<word<<" ";
			}
			flag=0;
		}
		cout<<endl;
	}
	return 0;
}