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

void computeLps(char *pat,int *lps)
{
	int M=strlen(pat);
	int len=0,i=1;
	lps[0]=0;
	while(i<M)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

int KMPSearch(char *pat,char *txt)
{
	int M=strlen(pat),N=strlen(txt);
	int *lps=(int*)calloc(M,sizeof(int));
	int j=0,i=0,count=0;
	computeLps(pat,lps);
	while(i<N)
	{
		if(pat[j]==txt[i])
		{
			j++;
			i++;
		}
		if(j==M)
		{
			count++;
			j=0;
			//i++;
			//j=lps[j-1];
		}
		else if(i<N && pat[j]!=txt[i])
		{
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
	free(lps);
	return count;
}
int main(int argc, char const *argv[])
{
	char str[100005];
	char pat[32];
	scanf("%s",str);
	scanf("%s",pat);
	printf("%d\n",KMPSearch(pat,str));
	return 0;
}