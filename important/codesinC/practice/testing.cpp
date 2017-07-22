#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int temp;
	if(b>a)
	{
		temp=a;
		a=b;
		b=temp;
	}
	int diff=a-b;
	string str=to_string(diff);
	int l=str.length();
	if(diff%10>=0&&diff%10<9)
		str[l-1]=(diff%10)+1;
	else
		str[l-1]=(diff%10)-1;
	cout<<str<<endl;
	return 0;
}