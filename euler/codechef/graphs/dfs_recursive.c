//dfs using recursion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DFS(int i,int n,int *visited,int **graph)
{
	int j;
	printf("%d\n",i );
	visited[i]=1;
	for(j=1;j<=n;j++)
	{
		if(!visited[j]&&graph[i][j]==1)
			DFS(j,n,visited,graph);
	}
}

int main()
{
	int n,i,j,a,b,t,v;
	scanf("%d",&n);
	int **graph=(int**)malloc((n+1)*sizeof(int*));
	for(i=0;i<=n;i++)
		graph[i]=(int*)malloc((n+1)*sizeof(int));
	int *visited=(int*)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
			graph[i][j]=0;
		visited[i]=0;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		graph[a][b]=1;
		graph[b][a]=1;
	}
	scanf("%d",&v);
	DFS(v,n,visited,graph);
	return 0;
}