#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, n, m, turnoff; //n���C�@�C��ܦ@��n�Ӧa�ϡAm����m�Ӧa�Ϭ��U�@���_�q���a��

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
