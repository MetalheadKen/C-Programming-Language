#include <stdio.h>

#define MAX 100000

int main(int argc, char *argv[]) {
	int i, square[MAX + 1] = {0}, rang1, rang2, count;
	
	for(i = 1; i * i < MAX; i++)
		square[i * i]++;
		
	fflush(stdin);
	while(~scanf("%d %d", &rang1, &rang2) && (rang1 != 0 || rang2 != 0))
	{
		count = 0;
		for(; rang1 <= rang2; rang1++)
		{
			if(square[rang1])
				count++;
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}
