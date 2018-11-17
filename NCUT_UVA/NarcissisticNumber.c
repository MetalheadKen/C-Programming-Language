/*
 ============================================================================
 Name        : NarcissisticNumber.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void narcissisticnumber(int number)
{
    int i, temp, sum = 0, a[4];

    temp = number;

    for(i = 0; i < 4; i++) {
        a[i] = temp % 10;
        temp /= 10;
        sum += a[i] * a[i] * a[i] * a[i];
    }

    if(sum == number)
        printf("%d\n", number);
}

int main(void)
{
    int number;

    printf("請輸出所有1000~9999之內的所有水仙花數：\n");

    for(number = 1000; number <= 9999; number++)
        narcissisticnumber(number);

    return EXIT_SUCCESS;
}
