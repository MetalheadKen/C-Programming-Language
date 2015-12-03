/*
 ============================================================================
 Name        : TowerOfHanoi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void Hanoi(int, char, char, char);

//Hanoi(�����ƶq, �ӷ��W, �Ȧs�W, �ت��W)
void Hanoi(int n, char A, char B, char C) {
	//�ѩ󻼰j���Y�A�Y�u�ŧiint count = 0 �N�|�@�����]���s
	//count �u���Ĥ@���|��l�Ʀ�0
	static int count = 0;

	if(n == 1)
	{
		count++;
		//������q�ӷ��W�h��ت��W (A ��> C)�A���ƥu���@��
		printf("��%d�B�G����%d�q��%c���%c\n", count, 1, A, C);
	}
	else
	{
		//Hanoi(�����ƶq, �ӷ��W��, �Ȧs�W��, �ت��W��)
		//Hanoi(n - 1, �ӷ��W, �ت��W, �Ȧs�W)
		Hanoi(n - 1, A, C, B); //���n - 1�Ӷ����q�ӷ��W�h��Ȧs�W (A ��> B)
		count++;
		//�C�L�A�åB���n�Ӷ����q�ӷ��W�h��ت��W
		printf("��%d�B�G����%d�q��%c���%c\n", count, n, A, C);
		//Hanoi(n - 1, �Ȧs�W, �ӷ��W, �ت��W)
		Hanoi(n - 1, B, A, C); //���n - 1�Ӷ����q�Ȧs�W�h��ت��W (B ��> C)
	}
}

/*Hannoi Function�b���j���N�Ƶ{���A�i�}��Ӥp���l�Ƶ{���A
 �ҥH�Y��J3�Ӷ����A�䲾�ʦ��ƱN��2^3-1�A�Y��Jn�Ӷ����A�䲾�ʦ��ƱN��2^n-1*/

int main(void) {
	int n;

	printf("�п�J�Ĥ@�ڬW�l�W���X�Ӷ����G");
	fflush(stdin);
	scanf("%d", &n);

	Hanoi(n, 'a', 'b', 'c');

	return EXIT_SUCCESS;
}
