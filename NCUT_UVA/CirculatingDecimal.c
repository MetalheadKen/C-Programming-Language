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
    int i, m, n, n_temp; //m代表分子，n代表分母，n_temp代表暫時存放n的數值
    int q, integer, length; //q代表餘數，integer代表輸出的整數部位，length代表非循環部位共有幾位數
    //count代表輸出循環部分有幾位數，count2代表分解成2可以分解幾次，count5代表分解成5可以有幾次
    size_t count, count2, count5;

    printf("請輸入兩個正整數，分別代表分子及分母：\n");
    fflush(stdin);

    while(scanf("%d %d", &m, &n) == 2) { //輸入兩數成功回傳值為2
        //初始化
        q = integer = length = count = count2 = count5 = 0;

        if(n < m || n == 0) {
            printf("輸入錯誤\n");
            continue;
        }

        //約分
        n_temp = gcd(m, n);
        m /= n_temp;
        n /= n_temp;
        n_temp = n; //備份n的值

        //調整真分數
        integer = m / n;
        m = q = m % n;

        //輸出真分數
        printf("答案為：\n%d.", integer);

        //沒有小數的話跳出
        if(q == 0)
            continue;

        //判斷非循環有幾位數
        //分母進行2 5分解
        //非循環節長度 － 2/5性質，分母若包含一個2或一個5(取兩數最大出現次數)，非循環節長度就 + 1
        while(n % 2 == 0 && m != 0) {
            n /= 2;
            count2++;
        }

        while(n % 5 == 0 && m != 0) {
            n /= 5;
            count5++;
        }

        //計算非循環節長度
        length = max(count2, count5);

        //輸出非循環數
        n = n_temp; //因n在上面已更動過，還原n的值
        for(i = 0; i != length; i++) {
            q *= 10;
            printf("%d", q / n);
            q %= n;
        }

        //計算循環節長度並輸出循環數
        if((q * 10) / n != 0) { //看有沒有循環小數
            m = q;
            do {
                q *= 10;
                printf("%d", q / n);
                q %= n;
                count++;
            } while(q != m);
        }

        printf("\n循環部分共有%d位數\n", count);
    }

    return EXIT_SUCCESS;
}
