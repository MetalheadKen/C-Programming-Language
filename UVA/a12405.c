#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //t����J�X������An����n�Ӧr���y�z�Цa�Ascarecrow���_��H���ƶq
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
                if(field[j] == '.') { //��P�_���лݦu�@
                    scarecrow++;
                    j += 2; //�������г��|�u��
                }
            }

            printf("Case %d: %d\n", i, scarecrow);
        }
    }

    return 0;
}
