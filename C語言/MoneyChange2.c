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
	int i, value, amount; //value����J���`���B�Aamount�������B�i�I�����ƶq
	int price[] = {50, 20, 10}; //price���i���������B
	int maxamount[] = {100, 100, 500}; //maxamount���i���������B���̤j�ƶq
	int length = sizeof(price) / sizeof(price[0]); //�����k�O���F�i���

	printf("�п�J�@�ӥ���ƪ���`���B�G\n");
	fflush(stdin);

	while(~scanf("%d", &value)) //�P(scanf("%d", &value) != EOF)�ۦP
	{
		printf("�i�I�����G\n");

		switch(value)
		{
			case 50:
				printf("50��0��\n20��2��\n10��1��\n"); break;
			case 20:
				printf("50��0��\n20��0��\n10��2��\n"); break;
			default:
				for(i = 0; i < length; i++)
				{
					amount = min(value / price[i], maxamount[i]);
					value -= amount * price[i];

					printf("%d��%d��\n", price[i], amount);
				}
		}
	}

	return EXIT_SUCCESS;
}
