/*
 ============================================================================
 Name        : PrimeAndEmirp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int isprime(int );

//�����sqrt�A�]�|��start��p
int isprime(int value) {
	int i, count; //count���p��O�_�����

	count = 0;
	for(i = 2; i < value; i++)
	{
		if(value % i == 0) //���߫D��ơA���]��
			count++;
	}

	if(count) //count���D�s�Ȫ���
		return 0;
	else
		return value;
}

int main(void) {
	int i, value, reverse, start, end;

	printf("�п�J�@�ӽd��A~B�G");
	fflush(stdin);
	scanf("%d %d", &start, &end);

	printf("�P�ɬO��ƩM�Ͻ�ƪ̬��G\n");
	for(i = start; i <= end; i++)
	{
		value = isprime(i);
		if(value) //�p�Gprime���^�ǭȪ���
		{
			//����ƭ�
			reverse = ((value % 10) *10) + (value / 10);
			//�P�_����᪺�Ʀr�O�_���P
			if(value == reverse)
				continue; //�p�G�ۦP���ܡA��continue�H��M�U�@�Ӽ�
			else
			{
				//�A���P�_�O�_���
				if(isprime(reverse))
					printf("%d\n", value);
			}
		}
	}

	return EXIT_SUCCESS;
}
