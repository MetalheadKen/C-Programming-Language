#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j, t, need, amount, length; //t為測資數量

    fflush(stdin);
    scanf("%d", &t);

    while(t--) {
        int bars[1002] = {0};

        scanf("%d", &need);
        scanf("%d", &amount);

        bars[0] = 1;
        for(i = 0; i < amount; i++) {
            scanf("%d", &length);
            for(j = need - length; j >= 0; j--) {
                if(bars[j] && !bars[j + length])
                    bars[j + length] = 1;
            }
        }

        if(bars[need])
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
