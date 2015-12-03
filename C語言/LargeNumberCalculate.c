/*
 ============================================================================
 Name        : LargeNumberCalculate.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 200

void calculate(int *, int);

//�j�ƭ����B��
void calculate(int *array, int n) {
	int i, j, carry = 0, value = 0; //carry���i��X�СAvalue��������Ʀ��

	array[0] = 1; //�n�����̤p�Ȭ�1
	for(i = 2; i <= n; i++)
	{
		for(j = 0; j <= value; j++)
		{
			array[j] = array[j] * i + carry;
			carry = array[j] / 10; //�Y���X��>=10���ܡAcarry�]1
			array[j] %= 10; //�C��}�C�s���@���
			if(carry != 0 && j == value) //�P�_��ƬO�_+1
				value++; //������Ʀ��
		}
	}

	printf("%d! = ", n);

	//�ϦV��X
	for(i = value; i >= 0; i--)
		printf("%d", array[i]);
}

int main(void) {
	int n, array[SIZE] = {0};

	printf("�мƤJ20~50���Ʀr�G");
	fflush(stdin);
	scanf("%d", &n);

	if(n < 20)
		printf("��J���~!!!\7\7\7");
	else
		calculate(array, n);

	return EXIT_SUCCESS;
}
