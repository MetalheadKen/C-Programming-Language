#include <stdio.h>
#include <stdlib.h>

int Compare(const void *, const void *);

int main(int argc, char *argv[])
{
    int length;

    fflush(stdin);
    while (~scanf("%d", &length)) {
        int number[length];
        for (int i = 0; i < length; i++)
            scanf("%d", &number[i]);

        /* Find the middle number from array */
        qsort(number, length, sizeof(number[0]), Compare);

        int middleA = number[(length - 1) / 2];
        int middleB = number[length / 2];

        int count = 0;
        for (int i = 0; i < length; i++)
            count += (middleA == number[i] || middleB == number[i]);

        printf("%d %d %d\n", middleA, count, middleB - middleA + 1);
    }

    return 0;
}

int Compare(const void *numberA, const void *numberB)
{
    return (*(int *) numberA) - (*(int *) numberB);
}
