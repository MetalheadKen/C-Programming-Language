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

#define min(x, y) ((x) < (y) ? x : y)

int main(void) {
	int i, value, amount; //value块羆肂amount肂传计秖
	int price[] = {50, 20, 10}; //price传Θ肂
	int maxamount[] = {100, 100, 500}; //maxamount传Θ肂程计秖
	int length = sizeof(price) / sizeof(price[0]); //暗猭琌拟┦

	printf("叫块タ俱计ボ羆肂\n");
	fflush(stdin);

	while(~scanf("%d", &value)) //籔(scanf("%d", &value) != EOF)
	{
		printf("传Θ\n");

		switch(value)
		{
			case 50:
				printf("50じ0\n20じ2\n10じ1\n"); break;
			case 20:
				printf("50じ0\n20じ0\n10じ2\n"); break;
			default:
				for(i = 0; i < length; i++)
				{
					amount = min(value / price[i], maxamount[i]);
					value -= amount * price[i];

					printf("%dじ%d\n", price[i], amount);
				}
		}
	}

	return EXIT_SUCCESS;
}
