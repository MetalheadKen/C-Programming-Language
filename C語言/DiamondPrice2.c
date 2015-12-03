/*
 ============================================================================
 Name        : DiamondPrice2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, price1[1000], price2[1000];

	printf("請輸入有幾行數值：");
	fflush(stdin);
	scanf("%d", &n);

	int i, j, price[1000];
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &price1[i], &price2[i]);
		for(j = price1[i]; j <= price2[i]; j++)
			price[i] += j * j;
	}

	for(i = 1; i <= n; i++)
	{
		if(price1[i] < price2[i])
			printf("%d\n", price[i]);
		else
			printf("輸入錯誤\n");
	}

	return EXIT_SUCCESS;
}
