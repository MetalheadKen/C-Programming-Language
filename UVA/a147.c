#include <stdio.h>
#include <stdlib.h>

#define SIZE 30000

int main(int argc, char *argv[])
{
    long long DynamicProgram[SIZE] = {1}; //建立一個動態規劃的陣列
    //dollar為存放貨幣的種類
    const int dollar[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    int i, j, money1, money2; //money1為輸入金額的整數，money2為輸入金額的浮點數

    for(i = 0; i < 11; i++) { //11種貨幣
        for(j = dollar[i]; j <= SIZE; j++)
            DynamicProgram[j] += DynamicProgram[j - dollar[i]];
    }

    fflush(stdin);
    while(scanf("%d.%d", &money1, &money2) != EOF) {
        if(money1 == 0 && money2 == 0) return 0;

        printf("%3d.%02d%17lld\n", money1, money2, DynamicProgram[money1 * 100 + money2]);
    }

    return 0;
}
