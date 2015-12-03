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

	//�x��1���P�e
	wx[0] = abs(x1[0] - x2[0]);
	wy[0] = abs(y1[0] - y2[0]);

	//�x��2���P�e
	wx[1] = abs(x1[1] - x2[1]);
	wy[1] = abs(y1[1] - y2[1]);

	//�x��1�����߮y��
	x3[0] = (x1[0] + x2[0]) / 2;
	y3[0] = (y1[0] + y2[0]) / 2;

	//�x��2�����߮y��
	x3[1] = (x1[1] + x2[1]) / 2;
	y3[1] = (y3[1] + y3[1]) / 2;

	//�P�_��x�άO�_�ۥ�
	//�x�Ψ⤤�߮y�Ь۴�ұo���ȡA�|�p�󵥩��x�ΦU�O���@�b���Τ@�b�e�Y�O
	if((abs(x3[0] - x3[1]) <= wx[0] / 2 + wx[1] / 2)
			&& (abs(y3[0] - y3[1]) <= wy[0] / 2 + wy[1] / 2))
		area(x1, y1, x2, y2);
	else
		printf("�o�������n���G\n%d", wx[0] * wy[0] + wx[1] * wy[1]);
}

void area(int *x1, int *y1, int *x2, int *y2) {
	int paintarea, x3, y3, x4, y4;

	//�ۥ�x�Ϊ��y��
	x3 = max(x1[0], x1[1]);
	y3 = max(y1[0], y1[1]);
	x4 = min(x2[0], x2[1]);
	y4 = min(y2[0], y2[1]);

	//��x�έ��n�ۥ[-���ƪ����n
	paintarea =abs(x1[0] - x2[0]) * abs(y1[0] - y2[0]) +
			abs(x1[1] - x2[1]) * abs(y1[1] - y2[1]) -
			abs(x3 - x4) * abs(y3 - y4);

	printf("�o�������n���G\n%d", paintarea);
}

int main(void) {
	int count, postercount, x1[2] = {0}, y1[2] = {0}, x2[2] = {0}, y2[2] = {0};

	printf("�п�J���ꪺ�ƶq�G");
	scanf("%d", &count);

	int i, j;
	if(count > 0 && count <= 100)
	{
		for(i = 0; i < count; i++)
		{
			printf("����}�l!!!\n�п�J�ǳ檺�ƶq�G");
			scanf("%d", &postercount);
			if(postercount > 0 && postercount <= 300)
			{
				for(j = 0; j < postercount; j++)
				{
					printf("�п�J���W���P�k�U���y�СG");
					scanf("%d %d %d %d", &x1[0], &y1[0], &x2[0], &y2[0]);
					scanf("%d %d %d %d", &x1[1], &y1[1], &x2[1], &y2[1]);

					/*if(((-1000 <= x1[0] && x1[0] < x2[0] && x2[0] <= 1000) &&
							(-1000 <= y1[0] && y1[0] < y2[0] && y2[0] <= 1000)) &&
							((-1000 <= x1[1] && x1[1] < x2[1] && x2[1] <= 1000) &&
							(-1000 <= y1[1] && y1[1] < y2[1] && y2[1] <= 1000)))*/
						intesect(x1, y1, x2, y2);
					/*else
					{
						printf("�y�п�J���~!!!\7\7\7");
						return 0;
					}*/
				}
			}
			else
			{
				printf("��J�ǳ檺�ƶq���~!!!\7\7\7");
				return 0;
			}
		}
	}
	else
		printf("��J������~!!!\7\7\7");

	getchar();

	return EXIT_SUCCESS;
}
