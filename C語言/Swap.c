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
    *a ^= *b; //�o�Ӯɭ�a�O�@��address, ���O*a�h�O�@��int
    *b ^= *a; //�ҥH��a, b����}�Ƕi��, �ק��}�W����
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

    printf("�мƤJ��ӼƦr(�ХΪťչj�})�G");
    scanf("%d %d", &a, &b);

    swap(&a, &b); //�ǤJ�O��}
    printf("\n a = %d \n b = %d", a, b);
    return EXIT_SUCCESS;
}
