/*
 * stack.c
 *
 *  Created on: 2015/12/24
 *      Author: Ken
 */
#include "stack.h"

Node *creatNode(void) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	if(newNode == NULL)
		printf("No available Memory!\n");

	return newNode;
}

int isEmpty(Node *stack) {
	return stack == NULL;
}

Node *Push(double entry, Node *stack) {
	Node *newNode = creatNode();

	if(newNode == NULL)
		printf("No available Memory!\n");

	newNode->data = entry;
	newNode->next = stack;
	stack = newNode;
	return stack;
}

Node *Pop(Node *stack) {
	Node *tempNode;

	if(isEmpty(stack))
	{
		printf("Stack is Empty!\n");
		return stack;
	}

	tempNode = stack;
	stack = stack->next;

	free(tempNode);

	return stack;
}

Node *clearStack(Node *stack) {
	Node *tempNode;

	while(tempNode != NULL)
	{
		tempNode = stack;
		stack = stack->next;

		free(tempNode);
	}

	printf("Stack cleared!\n");
	return stack;
}

void printStack(Node *stack) {
	if(isEmpty(stack))
		return;

	Node *newStack = stack;

	printf("Stack:\n");
	while(newStack != NULL)
	{
		printf("%d\n", newStack->data);
		newStack = newStack->next;
	}
}

int getTopValue(Node *stack) {
	return stack->data;
}
