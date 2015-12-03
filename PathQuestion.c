/*
 ============================================================================
 Name        : PathQuestion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void path (int **array, const int x, const int y) {
	int i, j;

	//��l��
	array[0][0] = 1;
	for(i = 1; i != x; ++i)
	{
		array[i][0] = 1;
		for(j = 1; j != y; ++j)
			array[0][j] = 1;
	}

	//�p��
	for(i = 1; i != x; ++i)
	{
		for(j = 1; j != y; ++j)
		{
			array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
			if (j != i)
				array[i][j] += array[i][j - 1];
		}
	}

	printf("�`�@��%d�ب��k\n", array[x - 1][y - 1]);
}

int main(void) {
	int x, y, i, j;

	printf("�п�J��ӥ����x�By�N����I��m���y�СG\n");
	fflush(stdin);
	scanf("%d %d", &x, &y);

	if(x >= y)
	{
		//�y�Х]�t
		x++;
		y++;
	}
	else
	{
		printf("0");
		return 0;
	}

	/*�ʺA�إߤG���}�C�A�Ѥ@���}�C�����G���}�C
	malloc(�ƶq * ���A�j�p���O����)
	malloc()�B��l�|�t�m�@��int�һݭn���Ŷ��A�öǦ^�ӪŶ�����}�A
	�ҥH�z�ϥΫ��Ш��x�s�o�Ӧ�}�A�o�q�{���u�t�m�Ŷ�������l�Ŷ��� ���x�s�ȡC
	calloc(�ƶq, ���A�j�p���O����)�A�Ҧ����Ŷ��Ȫ�l��0*/
	//int **array = (int **)malloc(x * sizeof(void *));
	/*int **array = (int **)calloc(x, sizeof(int *));
	int *array_y = (int *)calloc(x * y, sizeof(int *)); */
	int **array = (int **)calloc(x + x * y, sizeof(**array));
	//	int **array = (int **)calloc(x + x * y, sizeof(int *));
	int *array_y = (int *)(array + x); //��array_y����l�ơA����C��Loop��array_y�|�H��x�ӻ��W
	//����b�� array_y += y�Aarray_y�C���H��y�ӻ��W�A�p��array[i]�N����o�A���O�����}�F�C
	for(i = 0; i != x; ++i, array_y += y)
		array[i] = array_y;

	path(array, x, y);

	for(i = 0; i != x; ++i)
	{
		for(j = 0; j != y; ++j)
			printf("%3d ", array[i][j]);

		putchar('\n');
	}


	//�k�ٵ��O����
	//free(array[0]);
	free(array);

	return EXIT_SUCCESS;
}
