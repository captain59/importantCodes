#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef long long int ll;
typedef long double ld;
#define mod         1000000009
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n)   for(int (i) = 0; (i) < (n); ++(i))
#define mem(i,n)    memset(i,n,sizeof(i))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) < (Y) ? (Y) : (X))

const int MAX_N=2e5+5;
int cmpfunction(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
int main(int argc, char const *argv[])
{
	int n,l;
	scanf("%d%d",&n,&l);
	int *list1=(int*)calloc(n,sizeof(int));
	int *list2=(int*)calloc(n,sizeof(int));
	rep(i,n)scanf("%d",&list1[i]);
	rep(i,n)scanf("%d",&list2[i]);
	int sum=0;
	rep(i,n-1)
	{
		list1[i]=list1[i+1]-list1[i];
		sum+=list1[i];
	}
	list1[n-1]=l-sum;
	sum=0;
	rep(i,n-1)
	{
		list2[i]=list2[i+1]-list2[i];
		sum+=list2[i];
	}
	list2[n-1]=l-sum;
	bool flag=true;
	//cyclic shift
	//shift list1 and comapre it with list2
	rep(i,n)
	{
		//compare
		flag=true;
		rep(j,n)
		{
			if(list2[j]!=list1[j])
			{
				flag=false;
				break;
			}
		}	
		if(flag)break;
		//else shift list1 right shift
		int temp=list1[0];
		rep(j,n-1)list1[j]=list1[j+1];
		list1[n-1]=temp;
		/*
		rep(j,n)
		{
			printf("list2 %d list 1 %d\n",list2[j],list1[j]);
		}
		*/
	}
	printf("%s\n",(flag)?"YES":"NO" );
	return 0;
}