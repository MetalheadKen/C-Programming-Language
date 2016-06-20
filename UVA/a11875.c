#include <stdio.h>

#define TIME 15

int main(int argc, char *argv[]) {
	int i, j, t, n, number[TIME]; //t為測資數量，n為此次將要輸入多少個數
	
	fflush(stdin);
	scanf("%d", &t);
	
	for(i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		for(j = 0; j < n; j++)
			scanf("%d", &number[j]);
			
		printf("Case %d: %d\n", i, number[n / 2]); //因題目事先排序過，固可直接輸出結果 
	}
	
	return 0;
}
