#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(int argc, char *argv[])
{
    //n代戈计秖
    //step簿笆s﹃Θt﹃程Ω计counts﹃惠锣Θ1Ω计count_ss﹃1计count_tt﹃1计
    int i, j, n;
    char s[SIZE], t[SIZE];
    size_t step, count, count_s, count_t;

    fflush(stdin);
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        fflush(stdin);
        gets(s);
        gets(t);

        //ㄢ﹃ぃ┪ㄤい﹃ > 100挡祘Α
        if((strlen(s) != strlen(t)) || (strlen(s) > 100) || (strlen(t) > 100))
            exit(1);

        //璸衡ㄢ﹃'1'瞷Ω计
        for(j = step = count_s = count_t = 0; j < strlen(s); j++) {
            if(s[j] == '1') count_s++;
            if(t[j] == '1') count_t++;
        }

        //s﹃瞷'1'Ω计ぃゑt﹃'1'ぃΘ锣'0'
        if(count_s > count_t) {
            printf("Case %d:-1\n", i);
            continue;
        }

        //count癘魁锣碭'1''?'籔'0'常锣'1'
        //step += 2莱step / 2
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

        //ユ传琌ㄢㄢユ传衡Ω珿step / 2
        //簿笆Ω计锣传Ω计 + ユ传Ω计 / 2
        printf("Case %d:%d\n", i, count_t - count_s + step / 2);
    }

    return 0;
}
