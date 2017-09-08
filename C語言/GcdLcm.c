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
    //程そ计 = ㄢ计 / 程そ计
    return (m * n) / gcd(m,n);
}

int main(void)
{
    int m, n;

    printf("叫块ㄢ计(叫ノフ筳秨)");
    scanf("%d %d", &m, &n);
    printf("\n程そ计%d \n程そ计%d", gcd(m,n), lcm(m,n));

    return EXIT_SUCCESS;
}
