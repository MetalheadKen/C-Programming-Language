/*
 ============================================================================
 Name        : PaintPoster.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void intesect(int *, int *, int *, int *);
void area(int *, int *, int *, int *);

#define max(x, y) (x > y ? x : y)
#define min(x, y) (x > y ? y : x)

void intesect(int *x1, int *y1, int *x2, int *y2) {
	int wx[2], wy[2], x3[2], y3[2];

	//矩形1長與寬
	wx[0] = abs(x1[0] - x2[0]);
	wy[0] = abs(y1[0] - y2[0]);

	//矩形2長與寬
	wx[1] = abs(x1[1] - x2[1]);
	wy[1] = abs(y1[1] - y2[1]);

	//矩形1的中心座標
	x3[0] = (x1[0] + x2[0]) / 2;
	y3[0] = (y1[0] + y2[0]) / 2;

	//矩形2的中心座標
	x3[1] = (x1[1] + x2[1]) / 2;
	y3[1] = (y3[1] + y3[1]) / 2;

	//判斷兩矩形是否相交
	//矩形兩中心座標相減所得的值，會小於等於兩矩形各別的一半長或一半寬即是
	if((abs(x3[0] - x3[1]) <= wx[0] / 2 + wx[1] / 2)
			&& (abs(y3[0] - y3[1]) <= wy[0] / 2 + wy[1] / 2))
		area(x1, y1, x2, y2);
	else
		printf("油漆的面積為：\n%d", wx[0] * wy[0] + wx[1] * wy[1]);
}

void area(int *x1, int *y1, int *x2, int *y2) {
	int paintarea, x3, y3, x4, y4;

	//相交矩形的座標
	x3 = max(x1[0], x1[1]);
	y3 = max(y1[0], y1[1]);
	x4 = min(x2[0], x2[1]);
	y4 = min(y2[0], y2[1]);

	//兩矩形面積相加-重複的面積
	paintarea =abs(x1[0] - x2[0]) * abs(y1[0] - y2[0]) +
			abs(x1[1] - x2[1]) * abs(y1[1] - y2[1]) -
			abs(x3 - x4) * abs(y3 - y4);

	printf("油漆的面積為：\n%d", paintarea);
}

int main(void) {
	int count, postercount, x1[2] = {0}, y1[2] = {0}, x2[2] = {0}, y2[2] = {0};

	printf("請輸入測資的數量：");
	scanf("%d", &count);

	int i, j;
	if(count > 0 && count <= 100)
	{
		for(i = 0; i < count; i++)
		{
			printf("測資開始!!!\n請輸入傳單的數量：");
			scanf("%d", &postercount);
			if(postercount > 0 && postercount <= 300)
			{
				for(j = 0; j < postercount; j++)
				{
					printf("請輸入左上角與右下角座標：");
					scanf("%d %d %d %d", &x1[0], &y1[0], &x2[0], &y2[0]);
					scanf("%d %d %d %d", &x1[1], &y1[1], &x2[1], &y2[1]);

					/*if(((-1000 <= x1[0] && x1[0] < x2[0] && x2[0] <= 1000) &&
							(-1000 <= y1[0] && y1[0] < y2[0] && y2[0] <= 1000)) &&
							((-1000 <= x1[1] && x1[1] < x2[1] && x2[1] <= 1000) &&
							(-1000 <= y1[1] && y1[1] < y2[1] && y2[1] <= 1000)))*/
						intesect(x1, y1, x2, y2);
					/*else
					{
						printf("座標輸入錯誤!!!\7\7\7");
						return 0;
					}*/
				}
			}
			else
			{
				printf("輸入傳單的數量錯誤!!!\7\7\7");
				return 0;
			}
		}
	}
	else
		printf("輸入測資錯誤!!!\7\7\7");

	getchar();

	return EXIT_SUCCESS;
}
