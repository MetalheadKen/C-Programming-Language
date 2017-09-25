#include <stdio.h>

char *IsB2Sequence(int *, int);

int main(int argc, char *argv[])
{
    int count = 1, length;

    fflush(stdin);
    while (~scanf("%d", &length)) {
        int number[length];
        for (int i = 0; i < length; i++)
            scanf("%d", &number[i]);

        printf("Case #%d: %s\n\n", count++, IsB2Sequence(number, length));
    }

    return 0;
}

char *IsB2Sequence(int *number, int length)
{
    /* Permutation or Combination all possible situation */
    int sumArray[length * (length - 1) / 2];

    for (int i = 0, k = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            sumArray[k++] = number[i] + number[j];

            for (int l = 0; l < k - 1; l++) {
                if (sumArray[l] == sumArray[k - 1])
                    return "It is not a B2-Sequence.";
            }
        }
    }
    
    return "It is a B2-Sequence.";
}
