#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int t, no =1;
	scanf("%d",&t);
	char *str = (char*)malloc(10005*sizeof(char));
	while(t--) {
		int k, l, i = 0, count = 0, flag = 1;
		scanf("%s%d",str,&k);
		l = strlen(str);
		for(i=0; i<l-k+1; i++) {
			if (str[i]=='-') {
				int j = i;
				while(j<i+k) {
					str[j]=(str[j]=='+')?'-':'+';
					j++;
				}
				count++;
			}
		}
		for(i=0; i<l; i++) {
			if (str[i]=='-') {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("Case #%d: %d\n", no, count);
		}
		else
			printf("Case #%d: IMPOSSIBLE\n",no);
		no++;
	}
	return 0;
}