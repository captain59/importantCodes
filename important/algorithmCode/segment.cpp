#include <iostream>
#include <math.h>
using namespace std;
#define m 1000000

void construct(int input[],int segtree[],int low,int high,int pos)
{
	if(low==high)
	{
		segtree[pos]=input[low];
		return;
	}
	int mid=(low+high)/2;
	construct(input,segtree,low,mid,2*pos+1);
	construct(input,segtree,mid+1,high,2*pos+2);
	segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
}
int rangeMinQuery(int tree[],int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow<=low&&qhigh>=high)//total overlap
		return tree[pos];
	if(qlow>high||qhigh<low)//no overlap
		return m;
	int mid=(low+high)/2;
	return min(rangeMinQuery(tree,qlow,qhigh,low,mid,2*pos+1),rangeMinQuery(tree,qlow,qhigh,mid+1,high,2*pos+2));
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	int x = (int)(ceil(log2(n))); //Height of segment tree
    int l = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
	int tree[l]={0};
	int inp[n];
	for(int i=0;i<n;i++)
		cin>>inp[i];
	construct(inp,tree,0,n-1,0);
	while(q-->0)
	{
		int l,r;
		cin>>l>>r;
		int ans=rangeMinQuery(tree,l-1,r-1,0,n-1,0);
		cout<<ans<<"\n";
	}
	return 0;
}