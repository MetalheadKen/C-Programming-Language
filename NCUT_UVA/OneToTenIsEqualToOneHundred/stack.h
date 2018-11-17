/*
 * stack.h
 *
 *  Created on: 2015/12/24
 *      Author: Ken
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>

struct _Node {
    double data;
    struct _Node *next;
};

typedef struct _Node Node;
Node *creatNode(void);
Node *Push(double, Node *);
Node *Pop(Node *);
Node *clearStack(Node *);
int isEmpty(Node *);
void printStack(Node *);
int getTopValue(Node *);

#endif /* STACK_H_ */
