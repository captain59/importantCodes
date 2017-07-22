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
#define pp pair<int,int>
#define trav(container, it)      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
typedef pair<ll,ll>ii;
typedef priority_queue<ll,vector<ll>,greater<ll> > heap_min;
const int 	MAX_SIZE = 15;
vector<vector<pp> > arr(MAX_SIZE, vector<pp> (MAX_SIZE,mp(0,0)));

pp MIN_PAIR(pp a,pp b) {
	return (b>a)?a:b;
}

pp ADD_PAIR(pp a,pp b) {
	return mp(a.ff+b.ff,a.ss+b.ss);
}
int ROW,COL;
bool isInsideGrid(int i, int j)
{
    return (i >= 0 && i < ROW && j >= 0 && j < COL);
}
pp minCost(int n, int m) {
	priority_queue<pair<pp, pp>,vector<pair<pp, pp> >, greater<pair<pp, pp> > >pq;

	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};
	pp dist[n+1][m+1];
	int visit[n+1][m+1];

	rep(i,n+1)rep(j,m+1) {
		dist[i][j] = mp(INT_MAX,INT_MAX);
		visit[i][j] = 0;
	}
	pq.push(mp(arr[0][0],mp(0,0)));
	dist[0][0] = arr[0][0];
	while(!pq.empty()) {
		pp cost = pq.top().ff;
		int x = pq.top().ss.ff;
		int y = pq.top().ss.ss;
		visit[x][y] = 1;
		pq.pop();
		rep(i,4) {
			int newx = dx[i]+x;
			int newy = dy[i]+y;
			if (isInsideGrid(newx,newy) && dist[newx][newy]>ADD_PAIR(dist[x][y],arr[newx][newy])
				&& visit[newx][newy]==0) {
				dist[newx][newy] = ADD_PAIR(dist[x][y],arr[newx][newy]);
				pq.push(mp(dist[newx][newy],mp(newx,newy)));
			}
		}
	}
	return dist[n-1][m-1];
}
int main()
{
	IOS;
	int t;
	cin>>t;
	while(t--) {
		int m,n;
		cin>>n>>m;
		ROW = n;
		COL = m;
		int cost[n][m];
		int time[n][m];
		rep(i,n)rep(j,m)cin>>cost[i][j];
		rep(i,n)rep(j,m)cin>>time[i][j];
		rep(i,n)rep(j,m) {
			arr[i][j] = mp(cost[i][j], time[i][j]);
		}
		pp ans = minCost(n,m);
		cout<<ans.ff<<" "<<ans.ss<<"\n";
	}
	return 0;
} 