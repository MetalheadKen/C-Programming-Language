/*
 ============================================================================
 Name        : MoneyChange2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

int main(void) {
	int i, value, amount; //value為輸入的總金額，amount為此金額可兌換的數量
	int price[] = {50, 20, 10}; //price為可換成的金額
	int maxamount[] = {100, 100, 500}; //maxamount為可換成的金額的最大數量
	int length = sizeof(price) / sizeof(price[0]); //此做法是為了可攜性

	printf("請輸入一個正整數表示總金額：\n");
	fflush(stdin);

	while(~scanf("%d", &value)) //與(scanf("%d", &value) != EOF)相同
	{
		printf("可兌換成：\n");

		switch(value)
		{
			case 50:
				printf("50元0個\n20元2個\n10元1個\n"); break;
			case 20:
				printf("50元0個\n20元0個\n10元2個\n"); break;
			default:
				for(i = 0; i < length; i++)
				{
					amount = min(value / price[i], maxamount[i]);
					value -= amount * price[i];

					printf("%d元%d個\n", price[i], amount);
				}
		}
	}

	return EXIT_SUCCESS;
}
