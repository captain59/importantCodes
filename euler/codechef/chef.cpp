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
#define mod         1000000007
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n)   for(int (i) = 0; (i) < (n); ++(i))
#define mem(i,n)    memset(i,n,sizeof(i))
#define gcd(a,b)    __gcd(a,b)
#define sz(a)       ((int)(a.size()))
#define len(a)      ((int)a.length())
#define all(vi)     vi.begin(), vi.end()
#define ff          first
#define ss          second
#define trav(container, it)      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
typedef pair<ll,ll>ii;
typedef priority_queue<ll,vector<ll>,greater<ll> > heap_min;


int main()
{
	IOS;
	int m,n,total=0;
	cin>>m>>n;
	char arr[m+1][n+1];
	FOR(i,1,m)FOR(j,1,n)
	{
		cin>>arr[i][j];
		if(arr[i][j]=='*')
			total++;
	}
	int row[m+1],col[n+1];
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	int count;
	FOR(i,1,m)
	{
		count=0;
		FOR(j,1,n)
		{
			if(arr[i][j]=='*')
				count++;
		}
		row[i]=count;
	}
	FOR(i,1,n)
	{
		count=0;
		FOR(j,1,m)
		{
			if(arr[j][i]=='*')
				count++;
		}
		col[i]=count;
	}
	bool flag=false;
	int x,y;
	FOR(i,1,m)
	{
		FOR(j,1,n)
		{
			count=row[i]+col[j];
			if(arr[i][j]=='*')
				count--;
			if(count==total)
			{
				x=i;
				y=j;
				flag=true;
				break;
			}
		}
		if(flag)
			break;
	}
	if(flag)
		cout<<"YES\n"<<x<<" "<<y<<endl;
	else
		cout<<"NO\n";
	return 0;
} 