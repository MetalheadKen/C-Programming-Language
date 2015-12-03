/*
 ============================================================================
 Name        : PathQuestion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void path (int **array, const int x, const int y) {
	int i, j;

	//初始化
	array[0][0] = 1;
	for(i = 1; i != x; ++i)
	{
		array[i][0] = 1;
		for(j = 1; j != y; ++j)
			array[0][j] = 1;
	}

	//計算
	for(i = 1; i != x; ++i)
	{
		for(j = 1; j != y; ++j)
		{
			array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
			if (j != i)
				array[i][j] += array[i][j - 1];
		}
	}

	printf("總共有%d種走法\n", array[x - 1][y - 1]);
}

int main(void) {
	int x, y, i, j;

	printf("請輸入兩個正整數x、y代表終點位置的座標：\n");
	fflush(stdin);
	scanf("%d %d", &x, &y);

	if(x >= y)
	{
		//座標包含
		x++;
		y++;
	}
	else
	{
		printf("0");
		return 0;
	}

	/*動態建立二維陣列，由一維陣列模擬二維陣列
	malloc(數量 * 型態大小的記憶體)
	malloc()運算子會配置一個int所需要的空間，並傳回該空間的位址，
	所以您使用指標來儲存這個位址，這段程式只配置空間但不初始空間中 的儲存值。
	calloc(數量, 型態大小的記憶體)，所有的空間值初始為0*/
	//int **array = (int **)malloc(x * sizeof(void *));
	/*int **array = (int **)calloc(x, sizeof(int *));
	int *array_y = (int *)calloc(x * y, sizeof(int *)); */
	int **array = (int **)calloc(x + x * y, sizeof(**array));
	//	int **array = (int **)calloc(x + x * y, sizeof(int *));
	int *array_y = (int *)(array + x); //對array_y做初始化，之後每個Loop的array_y會隨著x而遞增
	//關鍵在於 array_y += y，array_y每次隨著y而遞增，如此array[i]就能取得適當的記憶體位址了。
	for(i = 0; i != x; ++i, array_y += y)
		array[i] = array_y;

	path(array, x, y);

	for(i = 0; i != x; ++i)
	{
		for(j = 0; j != y; ++j)
			printf("%3d ", array[i][j]);

		putchar('\n');
	}


	//歸還給記憶體
	//free(array[0]);
	free(array);

	return EXIT_SUCCESS;
}
