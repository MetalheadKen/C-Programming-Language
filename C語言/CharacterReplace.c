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

//因NULL要重新定義，故用
#ifdef NULL //因原有定義NULL，故成立
#undef NULL //消除定義
#define NULL '\0'
#endif NULL //結束#ifdef

#define number 21
int main(void) {
	int i = 0;
	char string[number], character, replace;

	printf("請輸入一組字串：");
	fflush(stdin);

	gets(string); //最好不要用scanf，因為用空白或者TAB是代表這行輸入的結束

	printf("請輸入被取代與取代的字：");
	scanf("%c %c", &character, &replace);

	do
	{
		if(string[i] == character)
			string[i] = replace;
		i++;
	}while(string[i] != NULL);

	printf("改變後的字串為：\n%s", string); //輸出字串，用%s

	return EXIT_SUCCESS;
}
