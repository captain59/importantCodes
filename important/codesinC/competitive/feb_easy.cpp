#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string s1="",s2="";
	cin>>s1; cin>>s2;
	string temp="";
	if(s1.length()<s2.length())
	{
		temp=s1;
		s1=s2;
		s2=temp;
	}
	s2=s2+" ";
	int l=s2.length();
	vector <string> v;
	string word="";char c;
	for(int i=0;i<l;i++)
	{
		c=s2[i];
		if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!=' ')
			word+=c;
		else 
		{
			v.push_back(word);
			word="";
		}
	}
	int max=0;word="";int max_temp=0;
	if(v.size()==0)
		max=0;
	else
	{
		for(int i=0;i<v.size();i++)
		{
			temp=v[i];
			for(int j=0;j<temp.length();j++)
			{
				if(s1.find(temp)!=-1)
				{
					max_temp=temp.length();
					break;
				}
				else
				temp=temp.substr
			}
			if(max_temp>max)
			max=max_temp;
		}
	}
	printf("%d\n",max);
	return 0;
}