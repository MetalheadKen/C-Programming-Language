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

//計算階乘的值，看有幾種排列組合
long int layer(long int level)
{
    if(level == 1)
        return 1;
    else
        return (level * layer(level - 1));
}

long int ispalindrome(char string[])
{
    int i, num[26] = {0}; //num為計算a~z的26個字元各出現次數

    for(i = 0; i < strlen(string); i++)
        num[string[i] - 'a']++; //減掉a字元，出現次數 + 1

    size_t time = 0; //time為計算有幾個字元出現奇數次
    long int sum = 0;

    sum = layer(strlen(string) / 2);

    for(i = 0; i < 26; i++) {
        if(num[i] == 0) //沒有字元出現，跳過
            continue;

        if(num[i] % 2) { //如果此字元出現的次數為奇數的話
            time++;

            if(time > 1) //如果有兩個以上字元出現個數為奇數的話，則不可能有迴文
                return 0;

            if(num[i] == 1) //如果此字元只出現一次的話，跳過，放中間
                continue;
        }

        //如果出現次數是偶數的話，就把它分成兩半，算前面這一半有多少種組合，後面這一半則因與前面一半相反，故不用理它
        //若出現奇數次為一次的話，則迴文正中央的字元一定就是那個奇數次的字元，放好之後與偶數次算法相同
        sum /= layer(num[i] / 2);
    }

    return sum;
}

int main(void)
{
    int n;
    char string[50] = {0};
    long int ans;

    printf("請輸入測資的數量：\n");
    fflush(stdin);

    while(scanf("%d", &n) != EOF) {
        while(n--) {
            printf("請輸入長度至少為1且不超過20的字串：\n");
            scanf("%s", string);

            ans = ispalindrome(string);

            printf("存在%ld種迴文格式\n", ans);
        }
    }

    return EXIT_SUCCESS;
}
