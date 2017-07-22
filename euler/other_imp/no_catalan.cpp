#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

#define IOS     	ios_base::sync_with_stdio(false); 
#define pb 			push_back
#define mp      	make_pair
#define mod 		1000000009
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n)   for(int (i) = 0; (i) < (n); ++(i))
#define mem(i,n)	memset(i,n,sizeof(i))
#define gcd(a,b)	__gcd(a,b)
#define sz(a)		((int)(a.size()))
#define len(a)		((int)a.length())
#define all(vi)		vi.begin(), vi.end()
#define mem(i,n)	memset(i,n,sizeof(i))
#define ff      	first
#define ss      	second

ll arr[5002];
ll comb[5002][5002];
int main()
{
	IOS;
	mem(arr,0);
	arr[0]=1;
	arr[1]=1;
	for(int i=2;i<=5001;i++)
	{
		for(int j=1;j<i;j++)
			arr[i]=(arr[i]+(arr[j]*arr[i-j]))%mod;
	}
	FOR(i,1,5001)
	{
		comb[i][1]=i;
		comb[i][i]=1;
	}
	for(int i=3;i<=5001;i++)
	{
		for(int j=2;j<i;j++)
		{
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
		}
	}
	rep(i,40)cout<<arr[i]<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans=(ans+(arr[i+1]*comb[n][i])%mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}