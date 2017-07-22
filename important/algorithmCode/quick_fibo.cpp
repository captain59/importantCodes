#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
#define len 1
typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix mul(matrix A,matrix B)
{
	matrix C(len+1,vector<ll>(len+1));
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
			C[i][j]=0;
	}
	
	for(int i=0;i<=len;i++)
	{
		for(int j=0;j<=len;j++)
		{
			for(int k=0;k<=len;k++)
			{
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	}
	return C;
}
//recursive relation to find A^P
matrix power(matrix A,ll p)
{
	if(p==1)
		return A;
	if(p%2==1)
		return mul(A,power(A,p-1));
	else
	{	matrix X=power(A,p/2);
		return mul(X,X);
	}
}
//fibonacci function
ll fib(ll n)
{
	ll F1[len+1]={0};
	F1[0]=1;
	F1[1]=1;
	//create transformation matrix
	matrix T(len+1,vector<ll>(len+1));
	T[0][0]=0,T[0][1]=1;
	T[1][0]=1,T[1][1]=1;

	if(n==1)
		return 1;
	T=power(T,n-1);
	//the answer is the first row of T.F1
	long long res=T[0][0]*F1[0]+T[0][1]*F1[1];
	return res;
}
int main()
{
	long long n;
	scanf("%lld",&n);
	cout<<fib(n)<<endl;
	return 0;
}