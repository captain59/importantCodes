#include <iostream>
using namespace std;
int fact(int x)
{
	if(x==0)
		return 1;
	else
		return fact(x-1)*x;
}
int main()
{
	cout<<"Enter number of terms.\n"<<endl;
	int n;long long int f;
	cin>>n;
	for (int i = 0; i =< n; ++i)
	{
		for(int j=0;j<=i;j++)
		{
			f=fact(i)/(fact(j)*fact(i-j));
			cout<<f<<"\t";
		}
		cout<<endl;

	}
	return 0;
}
