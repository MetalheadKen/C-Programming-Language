/*
 ============================================================================
 Name        : DavinciCode.c
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
    int min = 1, max = 1000, answer, number = 0;

    printf("請輸入正確數字：");
    scanf("%d", &answer);
    printf("開始遊戲!!!\n\n1~1000\n");

    do {
        fflush(stdin);
        printf("\n請輸入數字：");
        scanf("%d", &number);
        if(number > answer) {
            max = number - 1;
            printf("%d~%d\n", min, max);
        } else if(number < answer) {
            min = number + 1;
            printf("%d~%d\n", min, max);
        } else
            printf("BINGO!!!\7\7\7");
    } while(number != answer);

    return EXIT_SUCCESS;
}
