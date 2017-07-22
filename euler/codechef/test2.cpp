#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;
 
int main()
{
	int t;
	cin >> t;
 
	while(t--)
	{
	int size,k;
	cin >> size >> k;
 
	string s;
	cin >> s;
 
	vector<int> v;
	int cnt = 1;
	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			v.push_back(cnt);
			cnt = 1;
		}
		else
		{
			cnt++;
		}
	}
	v.push_back(cnt);
	/*
	for(int i=0;i<v.size();i++)
		cout << v[i] << endl;
	*/
 
	sort(v.begin(),v.end(),std::greater<int>());
 
	if(k<=v.size())
	{
	for(int i=0;i<k;i++)
	{
		if(v[i]%2==0)
		{
			if(v[i] > 2)
				v[i] = v[i]/2;
		}
		else
		{
			v[i] = v[i]/2;
		}
	}
	}
	else
	{
		while(1)
		{
			k -= v.size();
			if(k>0){
			for(int i=0;i<v.size();i++)
			{
				if(v[i]%2==0)
				{
						if(v[i] > 2)
							v[i] = v[i]/2;
				}
				else
				{
						if(v[i]>1)
						v[i] = v[i]/2;
				}
			}}
			else
			{
				if(k!=0)
				{
					k=k*-1;
					k = v.size()-k;
 
					for(int i=0;i<k;i++)
				{
					if(v[i]%2==0)
					{
							if(v[i] > 2)
								v[i] = v[i]/2;
					}
					else
					{
							if(v[i]>1)
							v[i] = v[i]/2;
					}
				}
				break;
				}
				else if(k==0)
					break;
			}
		}
	}
	sort(v.begin(),v.end(),std::greater<int>());
	cout << v[0] << endl;
	}
	return 0;
} 