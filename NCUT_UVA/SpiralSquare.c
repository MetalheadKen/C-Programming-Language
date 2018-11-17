/*
 ============================================================================
 Name        : SpiralSquare.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    double N[51];

    printf("請輸入有幾個正方形：");
    fflush(stdin);
    scanf("%d", &n);

    N[1] = 1;
    N[2] = 1;

    if((n > 0 ) && (n < 50)) {
        for(i = 3; i <= n; i++)
            N[i] = N[i - 1] + N[i - 2];

        printf("第%d個的邊長為：%.0lf", n, N[n]);
    } else
        printf("輸入錯誤\7\7\7");

    return EXIT_SUCCESS;
}
