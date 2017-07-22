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

#define MAX_N 100005
typedef pair<ll,ll>ii;
typedef priority_queue<ll,vector<ll>,greater<ll> > heap_min;


typedef long long LL;
const int maxn=2e5+10;
int n,p,cnt=0,ha=0,head[maxn],sum[maxn],ans[maxn];
LL a[maxn],dis[maxn],tep[maxn],w;
std::vector<LL> ve;
struct Edge
{
    int to,next;LL val;
}edge[maxn];
inline void add_edge(int from,int to,LL val)
{
    edge[cnt].to=to;
    edge[cnt].next=head[from];
    edge[cnt].val=val;
    head[from]=cnt++;
}
inline int lowbit(int x){return x&(-x);}
inline void update(int x,int num)
{
    while(x)
    {
        sum[x]+=num;
        x-=lowbit(x);
    }
}
inline int query(int x)
{
    int s=0;
    while(x<=n)
    {
        s+=sum[x];
        x+=lowbit(x);
    }
    return s;
}
void dfs(int cur,int fa,LL dist)
{
    dis[cur]=dis[fa]+dist;
    int pos=lower_bound(ve.begin(),ve.end(),dis[cur]-a[cur])-ve.begin();
    if(pos>=0&&pos<=ve.size())update(pos,-1),update(ve.size(),1);
    ve.push_back(dis[cur]);
    for(int i=head[cur];i!=-1;i=edge[i].next)
    {
        int x=edge[i].to;
        dfs(x,cur,edge[i].val);
    }
    int g=ve.size();
    ans[cur]=query(g);
    update(g,-ans[cur]);
    update(g-1,ans[cur]);
    ve.pop_back();
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]),head[i]=-1;
    for(int i=2;i<=n;i++)
    {
        scanf("%d%I64d",&p,&w);
        add_edge(p,i,w);
    }
    dfs(1,1,0);
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}