#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(int argc, char *argv[])
{
    int i, j, size; //size為方格的邊長
    int *array = (int *)calloc(N, sizeof(*array));

    fflush(stdin);

    j = 0;
    while(scanf("%d", &size) != EOF) {
        if(size < 0 || size > 100)
            exit(1);
        else if(size == 0) {
            putchar('\n');
            for(i = 0; i < N; i++) {
                if(array[i] == 0) {
                    system("pause");
                    return 0;
                }

                printf("%d\n", array[i]);
            }
        }

        //1到n的平方和等於n(n + 1)(2n + 1) / 6
        array[j] = (size * (size + 1) * (2 * size + 1)) / 6;
        j++;
    }

    return 0;
}
