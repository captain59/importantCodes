#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	printf("%d\n",a[n-m]);
	return 0;
}