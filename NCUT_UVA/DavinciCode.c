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

    printf("�п�J���T�Ʀr�G");
    scanf("%d", &answer);
    printf("�}�l�C��!!!\n\n1~1000\n");

    do {
        fflush(stdin);
        printf("\n�п�J�Ʀr�G");
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
