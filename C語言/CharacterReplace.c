/*
 ============================================================================
 Name        : CharacterReplace.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//�]NULL�n���s�w�q�A�G��
#ifdef NULL //�]�즳�w�qNULL�A�G����
#undef NULL //�����w�q
#define NULL '\0'
#endif NULL //����#ifdef

#define number 21
int main(void) {
	int i = 0;
	char string[number], character, replace;

	printf("�п�J�@�զr��G");
	fflush(stdin);

	gets(string); //�̦n���n��scanf�A�]���ΪťթΪ�TAB�O�N��o���J������

	printf("�п�J�Q���N�P���N���r�G");
	scanf("%c %c", &character, &replace);

	do
	{
		if(string[i] == character)
			string[i] = replace;
		i++;
	}while(string[i] != NULL);

	printf("���ܫ᪺�r�ꬰ�G\n%s", string); //��X�r��A��%s

	return EXIT_SUCCESS;
}
