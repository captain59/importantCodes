#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
boolean bin(int a[],int n,int x)
{
    int l=0;
    int h=n-1;int flag=0;
    while(l<=h)
    {
        int m=(l+h)/2;
        if(a[m]==x)
        {
            flag=1;
            break;
        }
        else if(a[m]<x)
        {
            l=l+1;
        }
        else
            h=h-1;
    }
    if(flag==1)
        return true;
    else
        return false;
}
int main() 
{
     int t;
     scanf("%d",&t);
     while(t-->0)
     {
        long long int n,k,p;
        long long int a[k+1];
        a[0]=1;
        vector<long long int> myVector;
        for (int i = 1; i < k+1; ++i)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+k);
        for(int i=0;i<k;i++)
        {
            for(int j=a[i];j<a[i+1]-1,j++)
            {
                myVector.push_back(i);
            }
        }
        if()
     }
    return 0;
}