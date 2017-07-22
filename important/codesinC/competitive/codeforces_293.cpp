#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	string s="";
	string t="";
	string temp="";int flag=0;
	getline(cin,s);
	getline(cin,t);
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(t[i]-s[i]!=1)
		{
			temp+=(t[i]+s[i])/2;
		}
		else
		{
			if(i==l-1)
			{
				printf("No such string");
				flag=1;
				break;
			}
			else
			{
				if(t[i]!=97)
				temp+=t[i]-1;
				else
				{
					if(s[i]!=122)
					temp+=s[i]+1;
					else
					temp+=s[i];
				}
			}
		}
	}
	if(flag==0)
	cout<<temp<<endl;
	return 0;
}