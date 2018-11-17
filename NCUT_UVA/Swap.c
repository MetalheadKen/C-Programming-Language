/*
 ============================================================================
 Name        : Swap.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    *a ^= *b; //這個時候a是一個address, 但是*a則是一個int
    *b ^= *a; //所以把a, b的位址傳進來, 修改位址上的值
    *a ^= *b;

    /**a += *b;
    *b = *a - *b;
    *a -= *b;*/

    /**a -= *b;
    *b += *a;
    *a = *b - *a;*/

    /*a = *a + *b + *c;
     *b = *a - *b - *c;
     *c = *a - *b - *c;
     *a = *a - *b - *c;*/
}
int main(void)
{
    int a, b;

    printf("請數入兩個數字(請用空白隔開)：");
    scanf("%d %d", &a, &b);

    swap(&a, &b); //傳入是位址
    printf("\n a = %d \n b = %d", a, b);
    return EXIT_SUCCESS;
}
