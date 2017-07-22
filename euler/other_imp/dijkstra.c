#include <stdio.h>
#include <stdlib.h>
#define infinity 9999

int main()
{
	int n,v,i,j,u,w,minimum,countsubl;
	scanf("%d",&n);
	int **cost=(int**)malloc((n+1)*sizeof(int*));
	for(i=0;i<=n;i++)
		cost[i]=(int*)malloc((n+1)*sizeof(int));
	int *dist=(int*)malloc((n+1)*sizeof(int));
	int *flag=(int*)malloc((n+1)*sizeof(int));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=infinity;
		}
	}
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",cost[i][j] );
		printf("\n");
	}
	scanf("%d",&v);

	for(i=1;i<=n;i++)
	{
		flag[i]=0;
		dist[i]=cost[v][i];
		printf("%d\n",cost[v][i] );
	}
	flag[v]=1;
	count=2;
	while(count<=n)
	{
		minimum=infinity;
		for(w=1;w<=n;w++)
		{
			if(dist[w]<minimum&&flag[w]==0)
			{
				minimum=dist[w];
				u=w;
			}
		}
		flag[u]=1;
		for(w=1;w<=n;w++)
		{
			if(((dist[u]+cost[u][w])<dist[w])&&flag[w]==0)
				dist[w]=dist[u]+cost[u][w];
		}
		count++;
	}
	printf("\n Shortest Path: \n");
	for(i=1;i<=n;i++)
	{
		if(i!=v)
			printf("%d->%d, cost=%d\n",v,i,dist[i]);
	}
	return 0;
}