/*
 ============================================================================
 Name        : PerfectNumber.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int number1, number2, sum;

	printf("請輸出所有1000~9999之內的所有水仙花數：\n");

	for(number1 = 2; number1 < 10000; number1++)
	{
		sum = 0;
		for(number2 = 1; number2 < number1; number2++)
		{
			if(number1 % number2 == 0)
				sum += number2;
		}
		if(number1 == sum)
			printf("%d\n", number1);
	}

	return EXIT_SUCCESS;
}
