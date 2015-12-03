/*
 ============================================================================
 Name        : LongDivision.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// a：被除數, b：除數, c：商數, d：餘數
	int a, b, c, d; //c = a / b;

	printf("請輸入被除數與除數：");
	scanf("%d %d", &a, &b);

	//取商數
	c = a / b;

	int temp, i, j, nbsp;

	//na, nb, nc ：  分別代表 a, b, c 為幾位數
	int na, nb, nc, nd;

	//計算a有幾位數
	temp = a;
	for(na = 0; temp != 0; ++na)
		temp /= 10;

	//計算b有幾位數
	temp = b;
	for(nb = 0; temp != 0; ++nb)
		temp /= 10;

	//計算c有幾位數
	temp = c;
	for(nc = 0; temp != 0; ++nc)
		temp /= 10;

	int f, g, h, e;

	//列印前三行
	//%* 為變數方式代入指定輸出之寬度
	nbsp = 2 + na + nb + 3 + nc;
	printf("%*d\n", nbsp, c);
	putchar('\n');
	for(j = 0; j < na + 1; ++j)
		putchar('-');
	putchar('\n');
	printf("\n %10d ) %d", b, a);

	g = a;
	for(i = 0; i < nc; ++i)
	{
		//d為中間過程的商數
		d = c;
		for(j = 1; j < nc - i; ++j)
			d /= 10;
		d %= 10;

		if(d != 0)
		{
			putchar('\n');

			//f為中間過程的商數與除數的乘積
			f = 1;
			for(j = 1; j < nc - i; ++j)
				f *= 10;
			f *= d * b;

			//g為中間過程的餘數，將g右邊的0去除就是h
			g = g - f;
			h = g;
			for(j = 1; j < nc - i - 1; ++j)
				h /= 10;

			//nd是中間過程的商數與除數的乘積為幾位數
			temp = b * d;
			for(nd = 0; temp != 0; ++nd)
				temp /= 10;

			//列印 b d 乘積
			printf("%10d", b * d);
			//printf("%*", 2 + nb + 3 + i - 1);
			putchar('\n');
			for(j = 0; j < na - nc + 2; ++j)
				putchar('-');
			putchar('\n');

			//列印中間過程的餘數
			if(i < nc - 1)
			{
				//nbsp = 2 + nb + 3 (na - nc + i + 2);
				printf("%10d", h);
			}
			else
			{
				//nbsp = 2 + nb + 3 (na - nc + i + 1);
				printf("%10d", h);
				if(h != a % b)
					printf("> not correct!!!\7\7\7\n");
			}
		}
		else
		{
			e = a;
			for(j = 1; j < (nc - (i + 1)); ++j)
				e /= 10;
			e %= 10;
			if(i < nc - 1)
				printf("%d", e);
		}
	}

	putchar('\n');

	return EXIT_SUCCESS;
}
