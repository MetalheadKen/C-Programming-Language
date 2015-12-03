/*
 ============================================================================
 Name        : DiamondPrice.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

double diamondprice(double m, double n) {
	double price;

	for(; m <= n; m++)
		price += m * m;

	return price;
}

int main(void) {
	int n, count;
	double price1, price2;

	printf("請輸入接下來要輸入幾行數字：");
	fflush(stdin);
	scanf("%d", &n);

	for(count = 1; count <= n; count++)
	{
		printf("請輸入兩個數值(請用空白隔開)：");
		fflush(stdin);
		scanf("%lf %lf", &price1, &price2);

		if(price1 < price2)
			printf("%.0lf\n", diamondprice(price1, price2));
		else
		{
			printf("輸入錯誤");
			break;
		}
	}
	return EXIT_SUCCESS;
}
