#include <stdio.h>

#define SWAP(X, Y) ((X) = (X) ^ (Y) ^ ((Y) = (X)))

int SortCarriages(int *, int);

int main(int argc, char *argv[])
{
    int times, length;

    fflush(stdin);
    while (~scanf("%d", &times)) {
        while (times--) {
            scanf("%d", &length);

            int carriages[length];
            for (int i = 0; i < length; i++)
                scanf("%d", carriages + i);
            
            int swapTimes = SortCarriages(carriages, length);
            printf("Optimal train swapping takes %d swaps.\n", swapTimes);
        }
    }

    return 0;
}

int SortCarriages(int *array, int length)
{
    int swapTimes = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i; j++) {
            if (array[j] > array[j + 1]) {
                SWAP(array[j], array[j + 1]);
                swapTimes++;
            }
        }
    }

    return swapTimes;
}
