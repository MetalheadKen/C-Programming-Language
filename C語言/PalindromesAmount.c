/*
 ============================================================================
 Name        : PalindromesAmount.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int layer(long int);
long int ispalindrome(char string[]);

//�p�ⶥ�����ȡA�ݦ��X�رƦC�զX
long int layer(long int level)
{
    if(level == 1)
        return 1;
    else
        return (level * layer(level - 1));
}

long int ispalindrome(char string[])
{
    int i, num[26] = {0}; //num���p��a~z��26�Ӧr���U�X�{����

    for(i = 0; i < strlen(string); i++)
        num[string[i] - 'a']++; //�a�r���A�X�{���� + 1

    size_t time = 0; //time���p�⦳�X�Ӧr���X�{�_�Ʀ�
    long int sum = 0;

    sum = layer(strlen(string) / 2);

    for(i = 0; i < 26; i++) {
        if(num[i] == 0) //�S���r���X�{�A���L
            continue;

        if(num[i] % 2) { //�p�G���r���X�{�����Ƭ��_�ƪ���
            time++;

            if(time > 1) //�p�G����ӥH�W�r���X�{�ӼƬ��_�ƪ��ܡA�h���i�঳�j��
                return 0;

            if(num[i] == 1) //�p�G���r���u�X�{�@�����ܡA���L�A�񤤶�
                continue;
        }

        //�p�G�X�{���ƬO���ƪ��ܡA�N�⥦������b�A��e���o�@�b���h�ֺزզX�A�᭱�o�@�b�h�]�P�e���@�b�ۤϡA�G���βz��
        //�Y�X�{�_�Ʀ����@�����ܡA�h�j�奿�������r���@�w�N�O���ө_�Ʀ����r���A��n����P���Ʀ���k�ۦP
        sum /= layer(num[i] / 2);
    }

    return sum;
}

int main(void)
{
    int n;
    char string[50] = {0};
    long int ans;

    printf("�п�J���ꪺ�ƶq�G\n");
    fflush(stdin);

    while(scanf("%d", &n) != EOF) {
        while(n--) {
            printf("�п�J���צܤ֬�1�B���W�L20���r��G\n");
            scanf("%s", string);

            ans = ispalindrome(string);

            printf("�s�b%ld�ذj��榡\n", ans);
        }
    }

    return EXIT_SUCCESS;
}
