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

    for(i = 2; i <= /*sqrt(*/number/*)*/; i++) { //sqrt�G�����
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

    printf("�п�J�@�ӼƭȡG");
    fflush(stdin);
    scanf("%d", &number);

    if(number <= 1)
        printf("\n�п�J�j��1���ƭȡI\7\7\7");
    else
        printf("\n%d = ", number);
    prime(number);

    return EXIT_SUCCESS;
}
