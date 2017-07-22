#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int len=2;
#define mod 1000000007
typedef vector<vector<ll> > matrix; 

//computes A*B
matrix mul(matrix A,matrix B)
{
	matrix C(len+1,vector<ll>(len+1));
	for(int i=0;i<=len;i++)
	{
		for(int j=0;j<=len;j++)
		{
			for(int k=0;k<=len;k++)
			{
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
			}
		}
	}
	return C;
}
//recursive relation to computes A^P
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
ll fib(ll n)
{
	//create vector F1

	ll F1[len+1];
	F1[0]=1;
	F1[1]=1;
	F1[2]=1;

	//create transformation matrix
	matrix T(len+1,vector<ll>(len+1));
	T[0][0]=0; T[0][1]=1; T[0][2]=0;
	T[1][0]=0; T[1][1]=0; T[1][2]=1;
	T[2][0]=1; T[2][1]=0; T[2][2]=1;

	// raise T to n-1th power
	if(n==1)
		return 1;
	T=power(T,n-1);

	//answer is the first row of T*F1

	ll res=0;
	for(int i=0;i<=len;i++)
	{
		res=(res+T[0][i]*F1[i])%mod;
	}
	return res;

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		ll no;
		cin>>no;
		ll ans=fib(no);
		cout<<ans*ans<<endl;
	}
	return 0;
}