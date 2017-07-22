#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#define PI  3.14159
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n,r,n_r;
    	cin>>n>>r;
    	n_r=n-r;
    	int pow2num=0;
    	int pow2r=0;
    	int pow2n_r=0;
    	while(n>0){
    		n/=2;
    		pow2num+=n;
    	}
    	while(r>0){
    		r/=2;
    		pow2r+=r;
    	}
    	while(n_r>0){
    		n_r/=2;
    		pow2n_r+=n_r;
    	}
    	int ans=pow2num-pow2r-pow2n_r;
    	if(ans>0)cout<<"even"<<endl;
    	else cout<<"odd"<<endl;
	}
	return 0;
}	