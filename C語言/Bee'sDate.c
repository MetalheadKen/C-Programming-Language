/*
 ============================================================================
 Name        : Bee'sDate.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define max(x, y) (x > y ? x : y)
void LCS(int [][100], int);

//Longest Common Subsequence �G �̱`�@�P�l�ǦC
void LCS(int array[][100], int n)
{
//void LCS(int (*array)[100], int n) {
//�p�G�O�G���}�C�A �h�ܤֻݭn��g�Ĥ@���פ������ӼơA �_�h�禡���L�k�s���쥿�T���ܼ�
//�ҡGint array[][]�N����A�n�g��int array[][10]�Aint array[2][]�]����
//�@���}�C�i�g��int array[]
//�Y�G���}�C�һ��ܼơA�h�nmalloc
    int i, j;
    int length[100][100];
    //int length[n][n]�bC99�зǤ��w�i�ϥΡA�H�e�O�����\���A�}�C���j�p���ݬ��w���`��
    //C99�зǤ���VLA(Variable-length array) �G �i�ܪ��Ʋ�

    for(i = 0; i != n; i++) {
        for(j = 0; j != n; j++) {
            if(array[0][i] == array[1][j]) {
                //�o�̥[�W1�O��e1�����׬�1
                length[i][j] = length[i - 1][j - 1] + 1;
            } else
                length[i][j] = max(length[i - 1][j], length[i][j - 1]);
        }
    }

    printf("LCS�����׬��G%d", length[n - 1][n - 1]);
}

int main(void)
{
    int n,i, j;

    printf("�п�J�ƦC�����סG");
    fflush(stdin);
    scanf("%d", &n);

    int array[2][100];

    for(i = 0; i != 2; i++) {
        for(j = 0; j != n; j++)
            scanf("%d", &array[i][j]);
    }

    LCS(array, n);

    return EXIT_SUCCESS;
}
