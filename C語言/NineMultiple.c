/*
 ============================================================================
 Name        : NineMultiple.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	//����ŧiunsign double�A�]�B�I�ƬO�����unsigned�ӫŧi��
	//���� double number; �]double���A�����k���|���l��
	static char string[30];
	int i, sum, number = 0, degree = 0;

	printf("�п�J�@����ơG");
	fflush(stdin);
	//scanf("%s", string);
	gets(string);

	for(i = 0; i < strlen(string); i++)
		number += string[i] - '0';

	if(number % 9 == 0)
		degree = 1;
	else
	{
		printf("9-degree���G\n%d", degree);
		return 0;
	}

	while((number % 9 == 0) && (number != 9))
	{
		sum = 0;
		for(; number >= 1; number /= 10)
			sum += number % 10;
		number = sum;
		degree++;
	}

	printf("9-degree���G\n%d", degree);

	return EXIT_SUCCESS;
}
