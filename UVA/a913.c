#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    long  long n; //n為某列會有n個數字

    fflush(stdin);
    while(scanf("%lld", &n) != EOF) {
        if(n <= 1 || n >= 1000000000)
            return 1;

        long long row = 0, final = 0;

        //算總共有多少數字
        for(i = 1; i <= n; i += 2)
            row += i;

        //算最後一個數字為多少
        final = row * 2 - 1;

        //final + final - 2 + final - 4
        printf("%d\n", final * 3 - 6);
    }


    return 0;
}
