/*
 ============================================================================
 Name        : EightQueens.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define N 8 //8 * 8的棋盤

void Queen(int );

int *column;
int *right;
int *left;
char **board;
char *board_y;

//每放置一個皇后就標記其相對應的三個變數值(行、右斜與左斜)
void Queen(int x) {
	int i, j, k;

	if(x < N) //判斷列有沒有超出棋盤範圍
	{
		for(i = 0; i < N; i++) //列不變，行每次 + 1
		{
			j = i - x + N - 1; //同一右斜的方格，其行號與列號之差相等
			k = i + x; //同一左斜的方格，其行號與列號之和相等
			if(column[i] && right[j] && left[k])
			{
				//標記皇后位置，並遞迴放置下一個
				column[i] = right[j] = left[k] = 0; //有皇后，= 0，使下次函式跳出
				board[x][i] = 'Q'; //標記

				Queen(x + 1); //尋找下一個，+ 1跳下一列

				column[i] = right[j] = left[k] = 1; //無皇后
				board[x][i] = '.';
			}
		}
	}
	else
	{
		//輸出棋盤
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
				printf("%c", board[i][j]);

			putchar('\n');
		}
	}
}

int main(void) {
	int i, j;

	//動態配置行、右斜、左斜的陣列
	column = (int *)malloc(N * sizeof(*column)); //同行是否有皇后
	right = (int *)malloc((2 * N - 1) * sizeof(*right)); //右上至左下是否有皇后
	left = (int *)malloc((2 * N - 1) * sizeof(*left)); //左上至右下是否有皇后
	//動態配置8 * 8的棋盤，裡面是放入Q和.的
	board = (char **)malloc(N * sizeof(*board) + N * N * sizeof(**board)); //總量
	board_y = (char *)(board + N); //加上列，第一維先建

	for(i = 0; i < N; i++, board_y += N) //加上行，宣告一列有幾行
		board[i] = board_y;

	//初始化
	for(i = 0; i < N; i++)
	{
		column[i] = 1;
		for(j = 0; j < N; j++)
			board[i][j] = '.';
	}

	Queen(0); //從第0列第一個數開始放與尋找

	//釋放記憶體空間
	free(column);
	free(right);
	free(left);
	free(board);

	return EXIT_SUCCESS;
}
