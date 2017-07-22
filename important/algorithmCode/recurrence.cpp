#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define mod 1000000007
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))

typedef vector<vector<ll> > matrix;

const int len=5;

matrix mult(matrix A,matrix B)
{
	matrix X(len+1,vector<ll>(len+1));
	
	rep(i,len) rep(j,len)
	X[i][j]=0;
	rep(i,len) rep(j,len) rep(k,len)
	X[i][j]=(X[i][j] + A[i][k] * B[k][j]) % mod;
	return X;
}

matrix power(matrix A,int p)
{
	if(p==1)
		return A;
	if(p&1)//odd
		return mult(A,power(A,p-1));
	matrix B=power(A,p/2);//even
	return mult(B,B);
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll a,b,c,d,e,f,f0,f1,g0,g1,n,c1,c2,c3,c4;
	cin>>a>>b>>c>>d>>e>>f>>f0>>f1>>g0>>g1;
	c1=(a*e)%mod;c2=(d*f)%mod;
	c3=(c*f)%mod;c4=(b*e)%mod;
	ll z=e*f0+f*g0;
	ll o=e*f1+f*g1;
	ll T1=(o+z)%mod;
	int t;ll ans=0;
	cin>>t;
	stringstream ss;
	matrix T(len+1,vector<ll> (len+1));
	rep(i,len+1) rep(j,len+1)
	T[i][j]=0;	
	T[0][0]=a;T[0][3]=b;
	T[1][0]=1;
	T[2][1]=d;T[2][2]=c;
	T[3][2]=1;
	T[4][0]=c1;T[4][1]=c2;T[4][2]=c3;T[4][3]=c4;T[4][4]=1;
	vector <ll> F(len+1);
	F[0]=f1,F[1]=f0,F[2]=g1,F[3]=g0,F[4]=T1;
	while(t--)
	{
		cin>>n;
		if(n==0)
			ans=z%mod;
		else if(n==1)
			ans=(o+z)%mod;
		else
		{
			matrix Tf(len+1,vector<ll>(len+1));
			Tf = power(T,n-1);
			ll res=0;
			rep(i, len)
			res = (res + Tf[4][i] * F[i]) % mod;
			ans=res;
		}
		ss<<ans;
		ss<<"\n";
	}
	cout<<ss.str();
	return 0;
}