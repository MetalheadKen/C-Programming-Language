#include <stdio.h>
#include <stdlib.h>

char *IsJolly(int *, int);

int main(int argc, char *argv[])
{
    int length;

    fflush(stdin);
    while (~scanf("%d", &length)) {
        int number[length];
        for (int i = 0; i < length; i++)
            scanf("%d", number + i);

        printf("%s\n", IsJolly(number, length));
    }

    return 0;
}

char *IsJolly(int *number, int length)
{
    for (int i = 0; i < length - 1; i++) {
        if (abs(number[i] - number[i + 1]) <= 0 || abs(number[i] - number[i + 1]) >= length)
            return "Not jolly";
    }

    return "Jolly";
}
