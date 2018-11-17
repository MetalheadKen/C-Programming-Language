/*
 ============================================================================
 Name        : CirculatingDecimal.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int, int );

#define max(x, y) ((x) > (y) ? (x) : (y))

int gcd(int m, int n)
{
    if(n == 0)
        return m;
    else
        return gcd(n, m % n);
}

int main(void)
{
    int i, m, n, n_temp; //m�N����l�An�N������An_temp�N��Ȯɦs��n���ƭ�
    int q, integer, length; //q�N��l�ơAinteger�N���X����Ƴ���Alength�N��D�`������@���X���
    //count�N���X�`���������X��ơAcount2�N����Ѧ�2�i�H���ѴX���Acount5�N����Ѧ�5�i�H���X��
    size_t count, count2, count5;

    printf("�п�J��ӥ���ơA���O�N����l�Τ����G\n");
    fflush(stdin);

    while(scanf("%d %d", &m, &n) == 2) { //��J��Ʀ��\�^�ǭȬ�2
        //��l��
        q = integer = length = count = count2 = count5 = 0;

        if(n < m || n == 0) {
            printf("��J���~\n");
            continue;
        }

        //����
        n_temp = gcd(m, n);
        m /= n_temp;
        n /= n_temp;
        n_temp = n; //�ƥ�n����

        //�վ�u����
        integer = m / n;
        m = q = m % n;

        //��X�u����
        printf("���׬��G\n%d.", integer);

        //�S���p�ƪ��ܸ��X
        if(q == 0)
            continue;

        //�P�_�D�`�����X���
        //�����i��2 5����
        //�D�`���`���� �� 2/5�ʽ�A�����Y�]�t�@��2�Τ@��5(����Ƴ̤j�X�{����)�A�D�`���`���״N + 1
        while(n % 2 == 0 && m != 0) {
            n /= 2;
            count2++;
        }

        while(n % 5 == 0 && m != 0) {
            n /= 5;
            count5++;
        }

        //�p��D�`���`����
        length = max(count2, count5);

        //��X�D�`����
        n = n_temp; //�]n�b�W���w��ʹL�A�٭�n����
        for(i = 0; i != length; i++) {
            q *= 10;
            printf("%d", q / n);
            q %= n;
        }

        //�p��`���`���רÿ�X�`����
        if((q * 10) / n != 0) { //�ݦ��S���`���p��
            m = q;
            do {
                q *= 10;
                printf("%d", q / n);
                q %= n;
                count++;
            } while(q != m);
        }

        printf("\n�`�������@��%d���\n", count);
    }

    return EXIT_SUCCESS;
}
