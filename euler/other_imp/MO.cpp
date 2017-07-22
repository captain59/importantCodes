#include <bits/stdc++.h>
using namespace std;

int block,answer;
int *arr=new int[50000];
int *cnt=new int[1000001];
typedef struct NODE
{
	int left,right,index;
}node;

bool cmp(node x,node y)
{
	if((x.left)/block!=(y.left)/block)
		return (x.left)/block<(y.left)/block;
	return (x.right)<(y.right);
}

void add(int pos)
{
	cnt[arr[pos]]++;
	if(cnt[arr[pos]]==1)
		answer++;
}
void remove(int pos)
{
	cnt[arr[pos]]--;
	if(cnt[arr[pos]]==0)
		answer--;
}
int main(int argc, char const *argv[])
{
	for(int i=0;i<1000001;i++)
		cnt[i]=0;
	int n,q;
	cin>>n;
	block=static_cast<int>(sqrt(n));
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>q;
	node *query=new node[q];
	int *disp=new int[q];
	for(int i=0;i<q;i++)
	{
		cin>>query->left>>query->right;
		query->left--;query->right--;
		query->index=i;
	}
	sort(query,query+q,cmp);
	int curl=0,curr=-1;
	for(int i=0;i<q;i++)
	{
		int l=query[i].left;
		int r=query[i].right;
		//applying MO's algorithm
		while(curl<l)
		{
			remove(curl);
			curl++;
		}
		while(curl>l)
		{
			add(curl-1);
			curl--;
		}
		while(curr<=r)
		{
			add(curr);
			curr++;
		}
		while(curr>r)
		{
			remove(curr);
			curr--;
		}
		disp[query[i].index]=answer;
	}
	for(int i=0;i<q;i++)
		cout<<disp[i]<<"\n";
	return 0;
}