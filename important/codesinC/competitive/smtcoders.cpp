#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		string str="";
		cin>>str;
		str+='';
		string word="";
		int n=str.length();int sum=0;
		for(int i=0;i<n;i++)
		{
			if(str[i]!=' ')
				word+=str[i];
			else
			{
				int l=word.length();
				sum=sum*10+l;
				word="";
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}