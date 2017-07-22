#include <stdio.h>

typedef struct COMPLEX
{
	int x;
	float y;
}com;
int main()
{
	com a,b;
	scanf("%d%f",&a.x,&a.y);
	b=a;
	printf("%f\n",b.y);
	return 0;
}