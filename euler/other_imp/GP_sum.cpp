#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
//containers
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<vi> vvi; 
 
#define IOS         ios_base::sync_with_stdio(false); 
#define pb          push_back
#define mp          make_pair
//#define mod         1000000007
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n)   for(int (i) = 0; (i) < (n); ++(i))
#define mem(i,n)    memset(i,n,sizeof(i))
#define gcd(a,b)    __gcd(a,b)
#define sz(a)       ((int)(a.size()))
//#define len(a)      ((int)a.length())
#define all(vi)     vi.begin(), vi.end()
#define ff          first	
#define ss          second
#define pp pair<int,int>
#define trav(container, it)      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
typedef vector<vector<ll> > matrix;
int MOD;
const int len = 3;
ll fast_exp(ll base, ll exp) {
	ll res = 1;
	while (exp>0) {
		if(exp&1) {
			res = (res*base)%MOD;
		}
		base = (base*base)%MOD;
		exp=exp/2;
	}
	return res%MOD;
}

matrix mul(matrix A,matrix B) {
	matrix C(len,vector<ll>(len));
	rep(i,len)rep(j,len)C[i][j]=0;
	FOR(i,1,len-1)FOR(j,1,len-1)FOR(k,1,len-1)C[i][j]=(C[i][j]+(A[i][k]*B[k][j])%MOD)%MOD;
	return C;
}
//recursive relation to find A^P
matrix power(matrix A,ll p)
{
	if(p==1)
		return A;
	if(p&1)
		return mul(A,power(A,p-1));
	else{	
		matrix X=power(A,p/2);
		return mul(X,X);
	}
}

ll calcGPSum(ll n, ll val) {
	matrix T(len,vector<ll>(len));
	ll x = fast_exp(val, MOD);
	T[1][1] = x; T[1][2] = 1;
	T[2][1] = 0; T[2][2] = 1;
	if (n==1) {
		return 1;
	}
	else {
		T = power(T, n-1);
		return (T[1][1]%MOD + T[1][2]*1)%MOD;
	}
}
int main()
{
	IOS;
	int t;
	cin>>t;
	while(t--) {
		ll n, value, mod;
		cin>>n>>mod;
		MOD = mod;
		vector<ll > freq(mod,(ll)(n/MOD));
		FOR(i,1,n%MOD)freq[i]++;
		value = 1;
		FOR(i,1,mod-1) {
			if(freq[i]) {
				value=(value+(fast_exp(i,i)*calcGPSum(freq[i],i))%MOD)%MOD;
			}
		}
		cout<<value<<endl;
	}
	return 0;
} 