#include <stdio.h>
#include <stdlib.h>

int Compare(const void *, const void *);

int main(int argc, char *argv[])
{
    int testCase, relativeCount;

    fflush(stdin);
    scanf("%d", &testCase);

    while (testCase--) {
        scanf("%d", &relativeCount);

        int streetNumber[relativeCount];
        for (int i = 0; i < relativeCount; i++)
            scanf("%d", &streetNumber[i]);

        /* Find the minimal sum of distances */
        qsort(streetNumber, relativeCount, sizeof(*streetNumber), Compare);

        int minDistance = 0,
            middle = streetNumber[((1 + relativeCount) / 2) - 1];

        for (int i = 0; i < relativeCount; i++)
            minDistance += abs(middle - streetNumber[i]);

        printf("%d\n", minDistance);
    }

    return 0;
}

int Compare(const void *numberA, const void *numberB)
{
    return (*(int *) numberA) - (*(int *) numberB);
}
