/*
 ============================================================================
 Name        : MiddleNumber.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//數列排序
int compare(const void *number1, const void *number2)
{
    //小到大
    if(*(int *)number1 - *(int *)number2 == 0)
        return (*(int *)number1 + 1) - (*(int *)number2 + 1);

    return (*(int *)number1) - (*(int *)number2);

    /*//大到小
    if(*(int *)number2 - *(int *)number1 == 0)
    		return (*(int *)number2 + 1) - (*(int *)number1 + 1);

    	return (*(int *)number2 - *(int *)number1);*/
}

int middlenumber(int *number, int size)
{
    int middle;

    middle = number[((1 + size) / 2) - 1];

    return middle;
}

int main(void)
{
    int i, middle, answer, number[20], size;

    printf("請輸入數列長度：");
    fflush(stdin);
    scanf("%d", &size);

    printf("請輸入長度為%d的一整數數列：", size);
    for(i = 0; i < size; i++)
        scanf("%d", &number[i]);

    if(size & 1)
        answer = 1;
    else
        answer = 2;


    //數列排序(要排序的陣列, 該陣列的個數, 該陣列元素所佔的記憶體空間, 函數指標)
    qsort(number, size, sizeof(int), compare);

    middle = middlenumber(number, size);

    printf("中位數為：%d\n在數列上符合的答案有：%d個\n", middle, answer);
    return EXIT_SUCCESS;
}
