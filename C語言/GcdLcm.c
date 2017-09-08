/*
 ============================================================================
 Name        : GcdLcm.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{
    while(n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;

    /*while(m % n != 0)
    {
    	int r = n;
    	n = m % n;
    	m = r;
    }
    return n;*/
}

int lcm(int m, int n)
{
    //�̤p������ = ��Ƭۭ� / �̤j���]��
    return (m * n) / gcd(m,n);
}

int main(void)
{
    int m, n;

    printf("�п�J��ӼƦr(�ХΪťչj�})�G");
    scanf("%d %d", &m, &n);
    printf("\n�̤j���]�Ƭ��G%d \n�̤p�����Ƭ��G%d", gcd(m,n), lcm(m,n));

    return EXIT_SUCCESS;
}
