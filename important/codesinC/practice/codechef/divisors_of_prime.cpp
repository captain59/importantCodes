#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int check(int n)
{
 int p=0,f=2;
 if((n%f)==0) {
  p++;
  while((n%f)==0)
   n/=f;
 }
 for(f=3;f<sqrt(n);f+=2)
  if((n%f)==0) {
   p++;
   while((n%f)==0)
    n/=f;
  }
 return (n==1)?p:(p+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	int arr[100001];int k=0;
	for(int i=2;i<=100000;i++)
		arr[i]=check(i);
	while(t-->0)
	{
		int a,b,k;int count=0;
		scanf("%d%d%d",&a,&b,&k);
		for(int i=a;i<=b;i++)
		{
			if(arr[i]==k)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}