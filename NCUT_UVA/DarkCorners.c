/*
 ============================================================================
 Name        : DarkCorners.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

//void light(int *[], int, int);

//判斷燈照到那些
//0作為空地，1作為牆壁，2作為燈泡，3作為被燈泡照到的白色空地
void light(int (*array)[SIZE], int x, int y)
{
    int Lx, Ly;

    //依序判斷左、上、右、下被照到的部分
    //當已為3時不再做
    for(Lx = x - 1, Ly = y; ((Lx >= 0 && array[Lx][Ly] == 0)
                             || array[Lx][Ly] == 3); Lx--)
        array[Lx][Ly] = 3;

    for(Lx = x, Ly = y - 1; ((Ly >= 0 && array[Lx][Ly] == 0)
                             || array[Lx][Ly] == 3); Ly--)
        array[Lx][Ly] = 3;

    for(Lx = x + 1, Ly = y; ((Lx < SIZE && array[Lx][Ly] == 0)
                             || array[Lx][Ly] == 3); Lx++)
        array[Lx][Ly] = 3;

    for(Lx = x, Ly = y + 1; ((Ly < SIZE && array[Lx][Ly] == 0)
                             || array[Lx][Ly] == 3); Ly++)
        array[Lx][Ly] = 3;
}

int main(void)
{
    int i, j, array[SIZE][SIZE];
    int count = 0; //count為計算沒有被燈光照到的白色方格總數

    printf("輸入大小為7*7燈泡與黑色方塊的配置矩陣：\n");
    fflush(stdin);

    //輸入矩陣
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++)
            scanf("%d", &array[i][j]);
    }

    //判斷哪裡燈亮
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(array[i][j] == 2)
                light(array, i, j);
        }
    }

    //計算沒有被燈光照到的白色方格總數
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(array[i][j] == 0)
                count++;
        }
    }

    //列印答案
    printf("沒有被燈光照到的白色方格有%d個", count);

    return EXIT_SUCCESS;
}
