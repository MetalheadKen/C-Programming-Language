/*
 ============================================================================
 Name        : LongDivision.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// a�G�Q����, b�G����, c�G�Ӽ�, d�G�l��
	int a, b, c, d; //c = a / b;

	printf("�п�J�Q���ƻP���ơG");
	scanf("%d %d", &a, &b);

	//���Ӽ�
	c = a / b;

	int temp, i, j, nbsp;

	//na, nb, nc �G  ���O�N�� a, b, c ���X���
	int na, nb, nc, nd;

	//�p��a���X���
	temp = a;
	for(na = 0; temp != 0; ++na)
		temp /= 10;

	//�p��b���X���
	temp = b;
	for(nb = 0; temp != 0; ++nb)
		temp /= 10;

	//�p��c���X���
	temp = c;
	for(nc = 0; temp != 0; ++nc)
		temp /= 10;

	int f, g, h, e;

	//�C�L�e�T��
	//%* ���ܼƤ覡�N�J���w��X���e��
	nbsp = 2 + na + nb + 3 + nc;
	printf("%*d\n", nbsp, c);
	putchar('\n');
	for(j = 0; j < na + 1; ++j)
		putchar('-');
	putchar('\n');
	printf("\n %10d ) %d", b, a);

	g = a;
	for(i = 0; i < nc; ++i)
	{
		//d�������L�{���Ӽ�
		d = c;
		for(j = 1; j < nc - i; ++j)
			d /= 10;
		d %= 10;

		if(d != 0)
		{
			putchar('\n');

			//f�������L�{���ӼƻP���ƪ����n
			f = 1;
			for(j = 1; j < nc - i; ++j)
				f *= 10;
			f *= d * b;

			//g�������L�{���l�ơA�Ng�k�䪺0�h���N�Oh
			g = g - f;
			h = g;
			for(j = 1; j < nc - i - 1; ++j)
				h /= 10;

			//nd�O�����L�{���ӼƻP���ƪ����n���X���
			temp = b * d;
			for(nd = 0; temp != 0; ++nd)
				temp /= 10;

			//�C�L b d ���n
			printf("%10d", b * d);
			//printf("%*", 2 + nb + 3 + i - 1);
			putchar('\n');
			for(j = 0; j < na - nc + 2; ++j)
				putchar('-');
			putchar('\n');

			//�C�L�����L�{���l��
			if(i < nc - 1)
			{
				//nbsp = 2 + nb + 3 (na - nc + i + 2);
				printf("%10d", h);
			}
			else
			{
				//nbsp = 2 + nb + 3 (na - nc + i + 1);
				printf("%10d", h);
				if(h != a % b)
					printf("> not correct!!!\7\7\7\n");
			}
		}
		else
		{
			e = a;
			for(j = 1; j < (nc - (i + 1)); ++j)
				e /= 10;
			e %= 10;
			if(i < nc - 1)
				printf("%d", e);
		}
	}

	putchar('\n');

	return EXIT_SUCCESS;
}
