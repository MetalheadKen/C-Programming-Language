#include <stdio.h>

#define SWAP(X, Y) ((X) = (X) ^ (Y) ^ ((Y) = (X)))

typedef struct _Pair {
    int left;
    int right;
} Pair;

int CycleLength(int);

int main(int argc, char *argv[])
{
    Pair number;

    fflush(stdin);
    while (~scanf("%d %d", &number.left, &number.right)) {
        int maxCycleLength = 0;

        printf("%d %d ", number.left, number.right);
        if (number.left > number.right) SWAP(number.left, number.right);

        /* Find the maximum cycle-length */
        for (int i = number.left; i <= number.right; i++) {
            int temp = CycleLength(i);

            if (temp > maxCycleLength) maxCycleLength = temp;
        }

        printf("%d\n", maxCycleLength);
    }

    return 0;
}

int CycleLength(int number)
{
    int cycleLength = 0;

    while (number != 1) {
        /* If number is odd, then TRUE */
        if (number & 0x01)
            number = number * 3 + 1;
        else
            number = number / 2;

        cycleLength++;
    }
    
    return (number == 1 ) ? cycleLength + 1 : cycleLength;
}
