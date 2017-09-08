/*
 ============================================================================
 Name        : Bee'sDate.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define max(x, y) (x > y ? x : y)
void LCS(int [][100], int);

//Longest Common Subsequence ： 最常共同子序列
void LCS(int array[][100], int n)
{
//void LCS(int (*array)[100], int n) {
//如果是二維陣列， 則至少需要填寫第一維度元素的個數， 否則函式內無法存取到正確的變數
//例：int array[][]就不行，要寫成int array[][10]，int array[2][]也不行
//一維陣列可寫成int array[]
//若二維陣列皆需變數，則要malloc
    int i, j;
    int length[100][100];
    //int length[n][n]在C99標準中已可使用，以前是不允許的，陣列的大小必需為已知常數
    //C99標準中的VLA(Variable-length array) ： 可變長數組

    for(i = 0; i != n; i++) {
        for(j = 0; j != n; j++) {
            if(array[0][i] == array[1][j]) {
                //這裡加上1是指e1的長度為1
                length[i][j] = length[i - 1][j - 1] + 1;
            } else
                length[i][j] = max(length[i - 1][j], length[i][j - 1]);
        }
    }

    printf("LCS的長度為：%d", length[n - 1][n - 1]);
}

int main(void)
{
    int n,i, j;

    printf("請輸入數列的長度：");
    fflush(stdin);
    scanf("%d", &n);

    int array[2][100];

    for(i = 0; i != 2; i++) {
        for(j = 0; j != n; j++)
            scanf("%d", &array[i][j]);
    }

    LCS(array, n);

    return EXIT_SUCCESS;
}
