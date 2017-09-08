#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, n, m, turnoff; //n為每一列表示共有n個地區，m為第m個地區為下一個斷電的地方

    fflush(stdin);
    while(~scanf("%d", &n) && n != 0) {
        if(n < 13 || n >= 100)	return 1;

        n--;
        for(m = 1; m < n; m++) {
            turnoff = 0;

            for(i = 1; i <= n; i++)
                turnoff = (turnoff + m) % i;

            if(turnoff == 11)
                break;
        }

        printf("%d\n", m);
    }

    return 0;
}
