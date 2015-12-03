/*
 ============================================================================
 Name        : GetDay.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //m內容為1~12月各天數
	int i, y, number, d, ans; //y代表第幾年，number代表第幾月，d代表第幾日，ans為加總後的答案

	printf("請輸入西元幾年、月、日：\n");
	fflush(stdin);

	while(scanf("%d %d %d", &y, &number, &d) != EOF) //EOF(End Of File)按下Ctrl+Z即可跳出
	{
		if((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))) //判斷閏年
			m[2] = 29;
		else
			m[2] = 28;

		ans = 0;
		for(i = 1; i <= number - 1; i++) //number - 1，因輸入月不算
			ans += m[i];

		printf("%d月%d日為當年的第%d天\n", number, d, ans + d);
	}

	return EXIT_SUCCESS;
}
