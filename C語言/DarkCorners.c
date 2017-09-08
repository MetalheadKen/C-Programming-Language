/*
 ============================================================================
 Name        : DarkCorners.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

//void light(int *[], int, int);

//�P�_�O�Ө쨺��
//0�@���Ŧa�A1�@������A2�@���O�w�A3�@���Q�O�w�Ө쪺�զ�Ŧa
void light(int (*array)[SIZE], int x, int y)
{
    int Lx, Ly;

    //�̧ǧP�_���B�W�B�k�B�U�Q�Ө쪺����
    //��w��3�ɤ��A��
    for(Lx = x - 1, Ly = y; ((Lx >= 0 && array[Lx][Ly] == 0)
                             || array[Lx][Ly] == 3); Lx--)
        array[Lx][Ly] = 3;

    for(Lx = x, Ly = y - 1; ((Ly >= 0 && array[Lx][Ly] == 0)
                             || array[Lx][Ly] == 3); Ly--)
        array[Lx][Ly] = 3;

    for(Lx = x + 1, Ly = y; ((Lx < SIZE && array[Lx][Ly] == 0)
                             || array[Lx][Ly] == 3); Lx++)
        array[Lx][Ly] = 3;

    for(Lx = x, Ly = y + 1; ((Ly < SIZE && array[Lx][Ly] == 0)
                             || array[Lx][Ly] == 3); Ly++)
        array[Lx][Ly] = 3;
}

int main(void)
{
    int i, j, array[SIZE][SIZE];
    int count = 0; //count���p��S���Q�O���Ө쪺�զ����`��

    printf("��J�j�p��7*7�O�w�P�¦������t�m�x�}�G\n");
    fflush(stdin);

    //��J�x�}
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++)
            scanf("%d", &array[i][j]);
    }

    //�P�_���̿O�G
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(array[i][j] == 2)
                light(array, i, j);
        }
    }

    //�p��S���Q�O���Ө쪺�զ����`��
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(array[i][j] == 0)
                count++;
        }
    }

    //�C�L����
    printf("�S���Q�O���Ө쪺�զ��榳%d��", count);

    return EXIT_SUCCESS;
}
