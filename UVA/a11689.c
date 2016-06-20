#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, have, collection, change, all, drink; //n為測資數量
	
	fflush(stdin);
	scanf("%d", &n);
	
	while(n--)
	{
		all = 0;
		scanf("%d %d %d", &have, &collection, &change);
		
		have += collection;
		while(have >= change)
		{
			drink = have / change;
			all += drink;			
			have = have % change + drink;
		}
		
		printf("%d\n", all);
	}
	
	return 0;
}
