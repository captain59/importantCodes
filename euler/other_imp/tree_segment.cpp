#include <bits/stdc++.h>
using namespace std;

int get_mid(int l,int r)
{
	return l+(r-l)/2;
}
/*  A recursive function to get the sum of values in given range
    of the array. The following are parameters for this function.
 
    st    --> Pointer to segment tree
    si    --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                 by current node, i.e., st[si]
    qs & qe  --> Starting and ending indexes of query range 
*/
int getSumUtil(int *st,int ss,int se,int qs,int qe,int si)
{
	if(qs<=ss&&qe>=se)
		return st[si];
	if(qs>se||qe<ss)
		return 0;
	int mid=get_mid(ss,se);
	return getSumUtil(st,ss,mid,qs,qe,2*si+1)+getSumUtil(st,mid+1,se,qs,qe,2*si+2);
}

int getSum(int *st,int n,int qs,int qe)
{
	if(qs<0||qe>n-1||qs>qe)
	{
		cout<<"Invalid Input\n";
		return -1;
	}
	return getSumUtil(st,0,n-1,qs,qe,0);
}
void update(int *st,int *arr,int si,int ss,int se,int idx,int val)
{
	if(ss==se)
	{
		arr[idx]+=val;
		st[si]+=val;
	}
	else
	{
		int mid=get_mid(ss,se);
		if(se<=idx)
	}
}
int constructSTUtil(int arr[],int ss,int se,int *st,int si)
{
	//if one element store it in current node
	if(ss==se)
	{
		st[si]=arr[ss];
		return arr[ss];
	}
	// if there are more than 2 elements the recurse to the left and right
	int mid=get_mid(ss,se);
	st[si]=constructSTUtil(arr,ss,mid,st,2*si+1)+constructSTUtil(arr,mid+1,se,st,2*si+2);
	return st[si];
}
int *ConstructST(int arr[],int n)
{
	//height of segment tree
	int x=(int)ceil(log2(n));
	//size of segment tree
	int max_size=(int)pow(2,x)-1;
	//allocate memory
	int *st= new int[max_size];
	//fill the allocated memory
	constructSTUtil(arr,0,n-1,st,0);
	return st;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	rep(i,n)cin>>arr[i];
	int *segment=ConstructST(arr,n);
	return 0;
}