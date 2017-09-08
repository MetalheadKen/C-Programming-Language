#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //t為輸入幾筆測資，n為有n個字元描述田地，scarecrow為稻草人的數量
    int i, j, t, n, scarecrow;
    char field[n];

    fflush(stdin);
    while(scanf("%d", &t) != EOF) {
        if(t > 100)	exit(1);

        for(i = 1; i <= t; i++) {
            scanf("%d", &n);
            if(n <= 0 || n >= 100) exit(1);

            scanf("%s", field);

            for(j= 0, scarecrow = 0; j < n; j++) {
                if(field[j] == '.') { //當判斷此田需守護
                    scarecrow++;
                    j += 2; //旁邊兩塊田都會守到
                }
            }

            printf("Case %d: %d\n", i, scarecrow);
        }
    }

    return 0;
}
