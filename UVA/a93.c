#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000000

int main(int argc, char *argv[]) {
	int i, j, t, n; //t代戈计ヘn块计
	
	fflush(stdin);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		if(n < 0 || n > MAX) exit(1);
		if(n == 1) { printf("1\n"); continue; }
		
		int ans[10] = {0}; //ans计皚 
		for(i = 9, j = 9; i >= 2; i--) //眖秨﹍埃 2 * 4 = 8 
		{
			if(!(n % i))
			{
				n /= i;
				ans[j] = i;
				j--;
			}
		}
		
		if(n == 1)
		{
			for(i = 0; i < 10; i++)
				if(ans[i])
					printf("%d", ans[i]);
					
			putchar('\n');
		}
		else
			printf("-1\n");
	}
	
	return 0;
}
