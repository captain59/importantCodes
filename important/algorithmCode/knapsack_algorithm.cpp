#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n,w;
		scanf("%d%d",&n,&w);
		int weight[n],value[n];
		for(int i=0;i<n;i++)
			scanf("%d",&weight[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&value[i]);
		int ans=knapsack(w,weight,value,n);
		printf("%d\n",ans );
	}
	return 0;
}