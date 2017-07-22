#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<vi> vvi; 

#define IOS         ios_base::sync_with_stdio(false); 
#define pb          push_back
#define mp          make_pair
#define mod         1000000007
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n)   for(int (i) = 0; (i) < (n); ++(i))
#define mem(i,n)    memset(i,n,sizeof(i))
#define gcd(a,b)    __gcd(a,b)
#define sz(a)       ((int)(a.size()))
#define len(a)      ((int)a.length())
#define all(vi)     vi.begin(), vi.end()
#define mem(i,n)    memset(i,n,sizeof(i))
#define ff          first
#define ss          second
#define trav(container, it)      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

ll fast_exp(ll base,ll p)
{
    ll res=1;
    while(p>0)
    {
        if(p&1)res=(res*base)%mod;
        base=(base*base)%mod;
        p/=2;
    }
    return res%mod;
}

int main()
{
    IOS;
    ll arr[100005];
    FOR(i,1,100000)arr[i]=fast_exp(i,mod-2)%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,count=0,data;
        cin>>n>>k;
        ll current=1,sum_even=1,sum_odd=0,sum=1;
        rep(i,n)cin>>data,count+=(data==0)?1:0;
        if(!count)
        {
            if(k>n)k=n;
            FOR(i,1,k)
            {
                current=(((current*(n-i+1))%mod)*arr[i])%mod;
                if(i&1)sum_odd=(sum_odd+current)%mod;
                else sum_even=(sum_even+current)%mod;
            }
            ll ans=(k&1)?sum_odd:sum_even;
            cout<<ans%mod<<endl;
        }
        else
        {
            n=n-count;
            if(k>n)k=n;
            FOR(i,1,k)
            {
                current=(((current*(n-i+1))%mod)*arr[i])%mod;
                sum=(sum+current)%mod;
            }
            cout<<sum%mod<<endl;
        }
    }
    return 0;
}