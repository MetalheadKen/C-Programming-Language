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
    //limit為四則運算所有可能的情況 = 4 ^ 9(因運算元有4種可能性(+、-、*、/)，又有9個運算元出現) = 2 ^ 18
    //operator為目前為第幾種可能性
    //oper為在第幾個運算元位置
    unsigned int limit, operators, oper;

    //1 << 18 = 2 ^ 18
    for(operators = 0, limit = 1 << 18; operators < limit; operators++) {
        if(calculate(operators)) {
            oper = operators;

            count++;
            printf("[%d] 1", count);

            //做2到10的四則運算
            //oper >>= 2 為 oper / 4 因每個四則運算的位置皆有4種可能性，藉以除4來找到在哪一個位置
            //oper & 0b11 為藉以 AND 11 來知道現在是什麼運算
            for(i = 2; i <= 10; i++, oper >>= 2)
                printf(" %c %d", OPER[oper & 0b11], i);

            printf(" = 100\n");
        }
    }

    return EXIT_SUCCESS;
}
