#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <utility>
#include <math.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>
#include <set>
#include <queue>
using namespace std;
 
#define loop(i,a,b) for(i=a;i<b;i++)
#define lp(i,n) for(i=0;i<n;i++)
#define lli long long int
#define us unsigned
#define tup2 pair <int,int>
#define dtup2 pair <double, double>
#define tup3 pair <tup2,int>
#define MAX(a,b) ((a)>=(b)?a:b)
#define MIN(a,b) ((a)<=(b)?a:b)
#define X first
#define Y second
#define pb push_back
#define pob pop_back
#define dist(a,b) sqrt((b.X - a.X)*(b.X - a.X) +(b.Y - a.Y)*(b.Y - a.Y))
 
 
int main()
{
	std::ios_base ::sync_with_stdio(false);
 
	int t;
	cin >> t;
	while(t--)
	{
		int n,k, i;
		cin >> n >> k;
 
		priority_queue<int> q;
 
		int ct = 0;
		char prev, next_exp;
 
		string inp;
		cin >> inp;
 
		prev = inp[0];
		loop(i,1,n)
		{
			next_exp = ((prev =='1') ? '0': '1');
 
			if(inp[i] != next_exp)
				ct++;
			prev = next_exp;
		}
 		//cout<<ct<<endl;
		if(ct <= k)
		{
			cout << '1' << '\n';
			continue;
		}
 
		prev = ((inp[0]=='1') ? '0': '1');
		ct = 1;
 
		loop(i,1,n)
		{
			next_exp = ((prev =='1') ? '0': '1');
 
			if(inp[i] != next_exp)
				ct++;
			prev = next_exp;
		}
 
		if(ct <= k)
		{
			cout << '1' << '\n';
			continue;
		}
 
		prev = inp[0]; ct = 1;
 
		loop(i,1,n)
		{
			if(inp[i] == prev)
				ct++;
			else
			{
				if(ct > 1)
					q.push(ct);
				prev = inp[i];
				ct = 1;
			}
		}
 
		if(ct > 1)
			q.push(ct);
 
		if(q.empty())
			cout << '1' << '\n';
 
		int ans;
		while(k>0 && !q.empty())
		{
			int x = q.top();
 
			if(x == 2)
			{
				ans = x;
				break;
			}
 
			k--;
			q.pop();
 
			int y = (x-1)/2;
			if(y > 1)
				q.push(y);
 
			y = x/2;
			if(y > 1)
				q.push(y);
		}
 
		ans = q.top();
		cout << ans << '\n' ;
	}
	return 0;
}