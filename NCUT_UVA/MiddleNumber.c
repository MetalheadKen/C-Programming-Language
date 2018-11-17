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

//�ƦC�Ƨ�
int compare(const void *number1, const void *number2)
{
    //�p��j
    if(*(int *)number1 - *(int *)number2 == 0)
        return (*(int *)number1 + 1) - (*(int *)number2 + 1);

    return (*(int *)number1) - (*(int *)number2);

    /*//�j��p
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

    printf("�п�J�ƦC���סG");
    fflush(stdin);
    scanf("%d", &size);

    printf("�п�J���׬�%d���@��ƼƦC�G", size);
    for(i = 0; i < size; i++)
        scanf("%d", &number[i]);

    if(size & 1)
        answer = 1;
    else
        answer = 2;


    //�ƦC�Ƨ�(�n�ƧǪ��}�C, �Ӱ}�C���Ӽ�, �Ӱ}�C�����Ҧ����O����Ŷ�, ��ƫ���)
    qsort(number, size, sizeof(int), compare);

    middle = middlenumber(number, size);

    printf("����Ƭ��G%d\n�b�ƦC�W�ŦX�����צ��G%d��\n", middle, answer);
    return EXIT_SUCCESS;
}
