/*
 ============================================================================
 Name        : PrimeAndEmirp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int isprime(int );

//不能用sqrt，因會比start更小
int isprime(int value) {
	int i;
	
	for(i = 2; i < value; i++)
	{
		if(value % i == 0) //成立非質數，為因數
			return 0;
	}
	
	return value;
}

int main(void) {
	int i, value, reverse, start, end;

	printf("請輸入一個範圍A~B：");
	fflush(stdin);
	scanf("%d %d", &start, &end);

	printf("同時是質數和反質數者為：\n");
	for(i = start; i <= end; i++)
	{
		value = isprime(i);
		if(value) //如果prime有回傳值的話
		{
			//反轉數值
			reverse = ((value % 10) *10) + (value / 10);
			//判斷反轉後的數字是否不同
			if(value == reverse)
				continue; //如果相同的話，做continue以找尋下一個數
			else
			{
				//再次判斷是否質數
				if(isprime(reverse))
					printf("%d\n", value);
			}
		}
	}

	return EXIT_SUCCESS;
}
