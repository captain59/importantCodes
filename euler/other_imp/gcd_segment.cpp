#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define gcd(a,b)    __gcd(a,b)
#define MAX 100000
int tree[4*MAX+1];

int getMid(int s,int e){ return s+(e-s)/2;}

int build(int arr[],int ss,int se,int index)
{
	if(ss==se)
	{
		tree[index]=arr[ss];
		return arr[ss];
	}
	int mid=getMid(ss,se);
	tree[index]=gcd(build(arr,ss,mid,2*index),build(arr,mid+1,se,2*index+1));
}

int query(int ss,int se,int qs,int qe,int index)
{
	if(qs<=ss&&qe>=se)
		return tree[index];
	//does not lie in segment
	if(qs>se||ss>qe||ss>se)
		return 0;
	int mid=getMid(ss,se);
	return gcd(query(ss,mid,qs,qe,2*index),query(mid+1,se,qs,qe,2*index+1));
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		build(arr,0,n-1,1);
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			if(a==1)
				cout<<query(0,n-1,b,n-1,1)<<endl;
			else if(b==n)
				cout<<query(0,n-1,0,a-2,1)<<endl;
			else
				cout<<gcd(query(0,n-1,0,a-2,1),query(0,n-1,b,n-1,1))<<endl;
		}
	}	
	return 0;
}