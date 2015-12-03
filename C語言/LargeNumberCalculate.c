/*
 ============================================================================
 Name        : LargeNumberCalculate.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 200

void calculate(int *, int);

//计经笲衡
void calculate(int *array, int n) {
	int i, j, carry = 0, value = 0; //carry秈篨夹value魁俱计计

	array[0] = 1; //璶程1
	for(i = 2; i <= n; i++)
	{
		for(j = 0; j <= value; j++)
		{
			array[j] = array[j] * i + carry;
			carry = array[j] / 10; //璝ㄓ>=10杠carry砞1
			array[j] %= 10; //–皚计
			if(carry != 0 && j == value) //耞计琌+1
				value++; //魁俱计计
		}
	}

	printf("%d! = ", n);

	//は块
	for(i = value; i >= 0; i--)
		printf("%d", array[i]);
}

int main(void) {
	int n, array[SIZE] = {0};

	printf("叫计20~50计");
	fflush(stdin);
	scanf("%d", &n);

	if(n < 20)
		printf("块岿粇!!!\7\7\7");
	else
		calculate(array, n);

	return EXIT_SUCCESS;
}
