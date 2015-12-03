/*
 ============================================================================
 Name        : SearchArray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define number 20

int main(void) {
	int data[number], search, i, count = 0;

	for(i = 0; i < number; i++)
		scanf("%d", &data[i]);

	fflush(stdin);
	printf("請輸入欲搜尋的數字：");
	scanf("%d", &search);

	for(i = 0; i < number; i++)
	{
		if(search == data[i])
		{
			printf("%d\n", i);
			count++;
		}
	}

	if(count == 0)
		printf("-1");

	return EXIT_SUCCESS;
}
