/*
 ============================================================================
 Name        : Prime.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prime(int number)
{
    int i;

    for(i = 2; i <= /*sqrt(*/number/*)*/; i++) { //sqrt：平方根
        int count = 0;
        /*while(number != i)
        {*/
        /*if*/while(number % i == 0) {
            number /= i;
            count++;
        }
        if(count > 0) {
            printf("%d", i);
            if(count >= 2)
                printf(" ^ %d", count);
            if(number > 1)
                printf(" * ");
        }
        /*else
        	break;
        }*/
    }
}

int main(void)
{
    int number;

    printf("請輸入一個數值：");
    fflush(stdin);
    scanf("%d", &number);

    if(number <= 1)
        printf("\n請輸入大於1的數值！\7\7\7");
    else
        printf("\n%d = ", number);
    prime(number);

    return EXIT_SUCCESS;
}
