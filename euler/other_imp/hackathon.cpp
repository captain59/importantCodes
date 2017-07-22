#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long int ll;

void help()
{
	cout<<"Rules:\nG-The number is present in the corect position	\nB-The number is present but not in correct position\nR:The number is not present in the position\n"<<endl;
}

int level()
{
	int n;
	cout<<"Enter the level you want to play 1-10\n";
	cin>>n;
	return n;
}
string inp(int t)
{
	string s;
	cout<<"Enter a number of length "<<t<<"\n";
	cin>>s;
	if(s.length()!=t)
	{
		cout<<"Wrong Input\nPlease enter again\n";
		inp(t);
	}
	return s;
}
int main()
{
	help();
	int n;
	n=level();
	while(n<0||n>10)
	{
		cout<<"Please enter a corect level\n";
		n=level();
	}
	srand(time(NULL));
	ll no;
	//ll no=rand()%((ll)pow(10,n))+1;
	cout<<"Enter the number\n";
	cin>>no;
	
	stringstream ss;
	ss << no;
	string str = ss.str();
	string temp;
	int g,b,r;int flag=0;
	while(1)
	{
		g=b=r=0;
		temp=str;
		string s=inp(n);
		for(int i=0;i<n;i++)
		{
			if(s[i]==temp[i])
			{
				g++;
				s[i]=10+s[i];
				temp[i]=100+temp[i];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(temp[i]==s[j])
				{
					b++;
					temp[i]=20+temp[i];
					s[j]=s[j]+200;
				}	
			}
		}
		r=n-b-g;
		s="";
		if(g==n)
		{
			cout<<"Congatulations You have won the Game\n";
			break;
		}
		else
		{
			cout<<"Green: "<<g<<"\nBlue: "<<b<<"\nRed: "<<r<<"\n";
			cout<<"Try Again\n";
		}
	}
	return 0;
}