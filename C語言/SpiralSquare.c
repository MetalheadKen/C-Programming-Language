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

    printf("�п�J���X�ӥ���ΡG");
    fflush(stdin);
    scanf("%d", &n);

    N[1] = 1;
    N[2] = 1;

    if((n > 0 ) && (n < 50)) {
        for(i = 3; i <= n; i++)
            N[i] = N[i - 1] + N[i - 2];

        printf("��%d�Ӫ�������G%.0lf", n, N[n]);
    } else
        printf("��J���~\7\7\7");

    return EXIT_SUCCESS;
}
