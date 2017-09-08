#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10

int  Compare(const void *, const void *);
void ConvertThreeSeven(int *);
int *SortTwistedThreeSeven(const int *, int);

int main(int argc, char *argv[])
{
    int array[LENGTH] = {0};

    fflush(stdin);
    for(int i = 0; i < LENGTH; i++) {
        scanf("%d", &array[i]);
    }

    int *ptr = SortTwistedThreeSeven(array, sizeof(array) / sizeof(array[0]));

    for(int i = 0; i < LENGTH; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr);

    return 0;
}

int *SortTwistedThreeSeven(const int *sequence, int length)
{
    int *array = (int *)malloc(length * sizeof(int));

    memcpy(array, sequence, length * sizeof(int));

    /* Convert Number Three and Number Seven */
    for(int i = 0; i < length; i++) {
        ConvertThreeSeven(&array[i]);
    }

    qsort(array, length, sizeof(int), Compare);

    /* Convert Back Number Three and Number Seven */
    for(int i = 0; i < length; i++) {
        ConvertThreeSeven(&array[i]);
    }

    return array;
}

void ConvertThreeSeven(int *number)
{
    int temp = *number;

    for(int i = 1; temp != 0; i *= 10, temp /= 10) {
        if(temp % 10 == 3 || temp % 10 == -7) {
            *number += 4 * i;
        } else if(temp % 10 == 7 || temp % 10 == -3) {
            *number -= 4 * i;
        }
    }
}

int Compare(const void *numberA, const void *numberB)
{
    return (*(int *)numberA) - (*(int *)numberB);
}
