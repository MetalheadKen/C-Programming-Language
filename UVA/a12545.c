#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(int argc, char *argv[])
{
    //n�����ꪺ�ƶq
    //step������s�r�ꦨt�r�ꪺ�̤p���ơAcount��s�r����ন1�����ơAcount_s��s�r��1���ӼơAcount_t��t�r��1���Ӽ�
    int i, j, n;
    char s[SIZE], t[SIZE];
    size_t step, count, count_s, count_t;

    fflush(stdin);
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        fflush(stdin);
        gets(s);
        gets(t);

        //��r����פ��ۦP�Ψ䤤�@�r����� > 100�ɵ����{��
        if((strlen(s) != strlen(t)) || (strlen(s) > 100) || (strlen(t) > 100))
            exit(1);

        //�p���r��'1'�X�{������
        for(j = step = count_s = count_t = 0; j < strlen(s); j++) {
            if(s[j] == '1') count_s++;
            if(t[j] == '1') count_t++;
        }

        //s�r��X�{'1'�����Ƥ����t�r��h�A�]'1'�����ର'0'
        if(count_s > count_t) {
            printf("Case %d:-1\n", i);
            continue;
        }

        //count���O����A��X��'1'�A'?'�P'0'�����ର'1'
        //step += 2�u���]���᭱��step / 2
        count = count_t - count_s;
        for(j = 0; j < strlen(s); j++) {
            if(s[j] == '?' && count > 0) {
                s[j] = '1';
                count--;
            } else if(s[j] == '?') {
                s[j] = '0';
                step += 2;
            }
        }

        for(j = 0; j < strlen(s); j++) {
            if(s[j] == '0' && count > 0) {
                s[j] = '1';
                count--;
            }
        }

        for(j = 0; j < strlen(s); j++) {
            if(s[j] != t[j])
                step++;
        }

        //�]�洫�O���洫��@���A�Gstep / 2
        //���ʪ����Ƭ��ഫ���� + �洫���� / 2
        printf("Case %d:%d\n", i, count_t - count_s + step / 2);
    }

    return 0;
}
