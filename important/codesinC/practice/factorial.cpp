#include<stdio.h>
 
int main(void)
{
	int t,n,m,i,j,k,temp,x,y;
	int a[200];
 
	scanf("%d",&t);
 
	for(i=1;i<=t;i++)
	{
		m=1;
		scanf("%d",&n);
		a[0] = 1;
		for(j=1;j<=n;j++)
		{
			temp = 0;
			for(k=1;k<=m;k++)
			{
				y = a[k-1]*j+temp;
				a[k-1] = y%10;
				temp = y/10;
			}
			if(temp > 0)
			{
				while(temp > 0)
				{	a[m]=temp%10;
					temp=temp/10;
					m=m+1; }
			}
		}
		for(j=m-1;j>=0;j--)
		{
			printf("%d",a[j]);
		}
		printf("\n");
 
	}
	return 0;
 
}