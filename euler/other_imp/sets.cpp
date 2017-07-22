#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define IOS     	ios_base::sync_with_stdio(false); 
#define pb 			push_back
#define mp      	make_pair
#define mod 		1000000007
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n)   for(int (i) = 0; (i) < (n); ++(i))
#define mem(i,n)	memset(i,n,sizeof(i))
#define gcd(a,b)	__gcd(a,b)
#define sz(a)		((int)(a.size()))
#define len(a)		((int)a.length())
#define all(vi)		vi.begin(), vi.end()
#define mem(i,n)	memset(i,n,sizeof(i))
#define ff      	first
#define ss      	second
int main()
{
	IOS;
	/*
	set <int> myset;
	set<int>::iterator it;
	pair<set<int>::iterator,bool> ret;
	for(int i=1;i<=10;i++)
		myset.insert(i*20);
	ret=myset.insert(30);
	if(ret.second == true)
		it=ret.first;
	
	myset.insert(it,25);
	myset.insert(it,40);
	myset.insert(it,50);
	int arr[]={12,30,40,24};
	it=myset.find(12);
	if(it!=myset.end())
		cout<<"Found\n"<<*it;
	else
		cout<<"NOty\n"<<*it;
	myset.insert(arr,arr+4);
	for(it=myset.begin();it!=myset.end();it++)
		cout<<*it<<endl;
	it=myset.find(20);
	myset.erase(it);
	cout<<"second\n";	
	*/
	cout<<"MAPS WORKING\n";
	map<string,int> mymap;
	mymap["anirban"]=1007;
	mymap["nayan"]=1995;
	mymap.insert(pair<string,int>("arunima",1993));
	mymap.insert(make_pair("aru",993));
	//declaring a iterator
	// maps store in alphabatical order
	map<string,int>::iterator it;
	for(it=mymap.begin();it!=mymap.end();it++)
		cout<<it->ff<<" "<<it->ss<<"\n";
	cout<<sz(mymap)<<"\n";
	it=mymap.find("aru");
	cout<<it->first<<" "<<it->second;
	return 0;
}