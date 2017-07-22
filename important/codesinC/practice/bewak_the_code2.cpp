#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		string str="";
		cin>>str;
		int l=str.length();
		string word1="";
		string word2="";
		if(l%2==1)
		{
			word1=str.substr(0,l/2);
			word2=str.substr(l/2+1,l);
		}
		else
		{
			word1=str.substr(0,l/2);
			word2=str.substr(l/2,l);
		}
		reverse(word2.begin(),word2.end());
		int p=word1.length();int count=0;
		for(int i=0;i<p;i++)
		{
			if(word1[i]!=word2[i])
				count++;
		}
		if(count>1)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}