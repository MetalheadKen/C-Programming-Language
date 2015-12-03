/*
 ============================================================================
 Name        : NineMultiple.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	//不能宣告unsign double，因浮點數是不能用unsigned來宣告的
	//不能 double number; 因double型態做除法不會有餘數
	static char string[30];
	int i, sum, number = 0, degree = 0;

	printf("請輸入一正整數：");
	fflush(stdin);
	//scanf("%s", string);
	gets(string);

	for(i = 0; i < strlen(string); i++)
		number += string[i] - '0';

	if(number % 9 == 0)
		degree = 1;
	else
	{
		printf("9-degree為：\n%d", degree);
		return 0;
	}

	while((number % 9 == 0) && (number != 9))
	{
		sum = 0;
		for(; number >= 1; number /= 10)
			sum += number % 10;
		number = sum;
		degree++;
	}

	printf("9-degree為：\n%d", degree);

	return EXIT_SUCCESS;
}
