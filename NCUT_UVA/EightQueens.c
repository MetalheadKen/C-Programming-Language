/*
 ============================================================================
 Name        : EightQueens.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define N 8 //8 * 8���ѽL

void Queen(int );

int *column;
int *right;
int *left;
char **board;
char *board_y;

//�C��m�@�ӬӦZ�N�аO��۹������T���ܼƭ�(��B�k�׻P����)
void Queen(int x)
{
    int i, j, k;

    if(x < N) { //�P�_�C���S���W�X�ѽL�d��
        for(i = 0; i < N; i++) { //�C���ܡA��C�� + 1
            j = i - x + N - 1; //�P�@�k�ת����A��渹�P�C�����t�۵�
            k = i + x; //�P�@���ת����A��渹�P�C�����M�۵�
            if(column[i] && right[j] && left[k]) {
                //�аO�ӦZ��m�A�û��j��m�U�@��
                column[i] = right[j] = left[k] = 0; //���ӦZ�A= 0�A�ϤU���禡���X
                board[x][i] = 'Q'; //�аO

                Queen(x + 1); //�M��U�@�ӡA+ 1���U�@�C

                column[i] = right[j] = left[k] = 1; //�L�ӦZ�A����
                board[x][i] = '.';
            }
        }
    } else {
        //��X�ѽL
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++)
                printf("%c", board[i][j]);

            putchar('\n');
        }
    }
}

int main(void)
{
    int i, j;

    //�ʺA�t�m��B�k�סB���ת��}�C
    column = (int *)malloc(N * sizeof(*column)); //�P��O�_���ӦZ
    right = (int *)malloc((2 * N - 1) * sizeof(*right)); //�k�W�ܥ��U�O�_���ӦZ
    left = (int *)malloc((2 * N - 1) * sizeof(*left)); //���W�ܥk�U�O�_���ӦZ
    //�ʺA�t�m8 * 8���ѽL�A�̭��O��JQ�M.��
    board = (char **)malloc(N * sizeof(*board) + N * N * sizeof(**board)); //�`�q
    board_y = (char *)(board + N); //�[�W�C�A�Ĥ@������

    for(i = 0; i < N; i++, board_y += N) //�[�W��A�ŧi�@�C���X��
        board[i] = board_y;

    //��l��
    for(i = 0; i < N; i++) {
        column[i] = 1;
        for(j = 0; j < N; j++)
            board[i][j] = '.';
    }

    for(i = 0; i < 2 * N + 1; i++)
        right[i] = left[i] = 1;

    Queen(0); //�q��0�C�Ĥ@�Ӽƶ}�l��P�M��

    //����O����Ŷ�
    free(column);
    free(right);
    free(left);
    free(board);

    return EXIT_SUCCESS;
}