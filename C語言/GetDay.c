/*
 ============================================================================
 Name        : GetDay.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //m���e��1~12��U�Ѽ�
	int i, y, number, d, ans; //y�N��ĴX�~�Anumber�N��ĴX��Ad�N��ĴX��Aans���[�`�᪺����

	printf("�п�J�褸�X�~�B��B��G\n");
	fflush(stdin);

	while(scanf("%d %d %d", &y, &number, &d) != EOF) //EOF(End Of File)���UCtrl+Z�Y�i���X
	{
		if((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))) //�P�_�|�~
			m[2] = 29;
		else
			m[2] = 28;

		ans = 0;
		for(i = 1; i <= number - 1; i++) //number - 1�A�]��J�뤣��
			ans += m[i];

		printf("%d��%d�鬰��~����%d��\n", number, d, ans + d);
	}

	return EXIT_SUCCESS;
}
