/*
 ============================================================================
 Name        : OneToTenIsEqualToOneHundred.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

const char OPER[] = {'+', '-', '*', '/'};

_Bool calculate(unsigned int operators)
{
    Node *stack = NULL;
    double i, temp, result = 0;

    stack = Push(1.0, stack);

    for(i = 2.0; i <= 10.0; i += 1.0, operators >>= 2) {
        switch(operators & 0b11) {
            case 0:
                stack = Push(i, stack);
                break;
            case 1:
                stack = Push(-i, stack);
                break;
            case 2:
                temp = getTopValue(stack) * i;
                stack = Pop(stack);
                stack = Push(temp, stack);
                break;
            case 3:
                temp = getTopValue(stack) / i;
                stack = Pop(stack);
                stack = Push(temp, stack);
                break;
        }
    }

    while(!isEmpty(stack)) {
        result += getTopValue(stack);
        stack = Pop(stack);
    }

    return (result == 100.0);
}

int main(void)
{
    int i;
    size_t count = 0;
    //limit���|�h�B��Ҧ��i�઺���p = 4 ^ 9(�]�B�⤸��4�إi���(+�B-�B*�B/)�A�S��9�ӹB�⤸�X�{) = 2 ^ 18
    //operator���ثe���ĴX�إi���
    //oper���b�ĴX�ӹB�⤸��m
    unsigned int limit, operators, oper;

    //1 << 18 = 2 ^ 18
    for(operators = 0, limit = 1 << 18; operators < limit; operators++) {
        if(calculate(operators)) {
            oper = operators;

            count++;
            printf("[%d] 1", count);

            //��2��10���|�h�B��
            //oper >>= 2 �� oper / 4 �]�C�ӥ|�h�B�⪺��m�Ҧ�4�إi��ʡA�ǥH��4�ӧ��b���@�Ӧ�m
            //oper & 0b11 ���ǥH AND 11 �Ӫ��D�{�b�O����B��
            for(i = 2; i <= 10; i++, oper >>= 2)
                printf(" %c %d", OPER[oper & 0b11], i);

            printf(" = 100\n");
        }
    }

    return EXIT_SUCCESS;
}
