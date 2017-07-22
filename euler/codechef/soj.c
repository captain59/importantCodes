#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;
typedef long double ld;
#define mod         1000000009
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n)   for(int (i) = 0; (i) < (n); ++(i))
#define mem(i,n)    memset(i,n,sizeof(i))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) < (Y) ? (Y) : (X))
//qsort(values, 5, sizeof(int), cmpfunc);
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}
typedef struct NODE
{
	char kind;
	int x,y;
}node;
int n;
ll xconst,yconst;
const int MAX_N=100005;


//gettig directions
int directions(node *cur)
{
//vertical
if((xconst==(*cur).x)&&(*cur).y>yconst)
	return 1;
if((xconst=(*cur).x)&&(*cur).y<yconst)
	return 2;
//horizonta;
if((yconst==(*cur).y)&&(*cur).x>xconst)
	return 3;
if((yconst==(*cur).y)&&(*cur).x<xconst)
	return 4;
//right diagonal
if(((*cur).y-yconst)==((*cur).x-xconst)&&(*cur).x>xconst)
	return 5;//first quad
if(((*cur).y-yconst)==(xconst-(*cur).x)&&(*cur).x<xconst)
	return 6;//second quad
if((yconst-(*cur).y)==(xconst-(*cur).x)&&(*cur).x<xconst)
	return 7;//third quadrant
if((yconst-(*cur).y)==((*cur).x-xconst)&&(*cur).x>xconst)
	return 8;//4th quad
return -1;
}

ll distance(ll x1,ll y1,ll x2,ll y2)
{
	return MAX(abs(x1-y1),abs(x2-y2));
}
void update_nearest(node *existing,node *cur)
{
	if((*existing).kind=='?'||distance(xconst,yconst,(*cur).x,(*cur).y)<distance(xconst,yconst,(*existing).x,(*existing).y))
		*existing=*cur;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	scanf("%lld",&xconst,&yconst);
	node *neighbour=(node*)malloc(8*sizeof(node));
	rep(i,8)neighbour->kind='?';
	node current;
	rep(i,n)
	{
		scanf("%c%lld%lld",&current.kind,&current.x,&current.y);
		int dir= directions(&current);
		if(dir>=0)
			update_nearest(&neighbour[dir],&current);
	}
	bool ans=false;
	FOR(i,1,4)
	{
		if(neighbour[i].kind=='R'||neighbour[i].kind=='Q')
			ans=true;
	}
	FOR(i,5,8)
	{
		if(neighbour[i].kind=='B'||neighbour[i].kind=='Q')
			ans=true;
	}
	if(ans)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}