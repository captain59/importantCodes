#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define IOS         ios_base::sync_with_stdio(false); 
#define pb          push_back
#define mp          make_pair
#define mod         1000000007
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n)   for(int (i) = 0; (i) < (n); ++(i))
#define gcd(a,b)    __gcd(a,b)
#define first 		ff
#define second		ss

typedef vector<vector<ll> > matrix;
typedef pair<int,int> NODE;
#define len 2
#define MAX 100002
typedef struct STORE
{
	int ff;
	int ss;
}NODE;
NODE tree=new NODE[4*MAX];
ll arr[MAX];
int getMid(int s,int e){ return s+(e-s)/2;}

NODE add(NODE a,NODE b){ return mp(a.ff+b.ff,a.ss+b.ss);}
NODE build(int start,int end,int index)
{
	if(start==end)
	{
		if(arr[start]&1)
		{
			tree[index].ss=1;
			tree[index].ff=0;
		}
		else
		{
			tree[index].ss=0;
			tree[index].ff=1;
		}
		return tree[index];
	}
	int mid=getMid(start,end);
	tree[index]=add(build(start,mid,2*index),build(mid+1,end,2*index+1));
}
NODE query(int start,int end,int qs,int qe,int index)
{
	if(qs<=start&&qe>=end)
		return tree[index];
	// does not lie in the segment
	if(qs>end||qe<start||start>end)
		return mp(0,0);
	int mid=getMid(start,end);
	return add(query(start,mid,qs,qe,2*index),query(mid+1,end,qs,qe,2*index+1));
}
int main()
{
	IOS;
	int n;
	cin>>n;
	rep(i,n)cin>>arr[i];

	return 0;
}