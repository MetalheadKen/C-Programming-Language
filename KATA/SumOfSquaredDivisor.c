#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Pair {
    long long first;
    long long divisorSquare;
} Pair;

Pair *ListSquaredDivisor(int, int, int *);

int main(int argc, char *argv[])
{
    int start, end, length = 1;

    fflush(stdin);
    scanf("%d %d", &start, &end);

    Pair *result = ListSquaredDivisor(start, end, &length);

    for(int i = 0; i < length; i++) {
        printf("%lld, %lld\n", result[i].first, result[i].divisorSquare);
    }

    free(result);

    return 0;
}

Pair *ListSquaredDivisor(int start, int end, int *length)
{
    /* Step 1: Find all divisors between start and end.
    ** Step 2: Sum of all squared divisors.
    ** Step 3: If sum is a square, Print that. */

    long long sum = 0;
    Pair *result  = (Pair *)malloc((*length) * sizeof(Pair));

    /* Do Step 1 and Step 2 */
    for(int number = start; number <= end; number++) {
        sum = 0;
        for(int j = 1; j <= number; j++) {
            if(number % j == 0) {
                sum += j * j;
            }
        }

        /* Do Step 3 */
        if((long long)sqrt(sum) * sqrt(sum) == sum) {
            result = (Pair *)realloc(result, (*length) * sizeof(Pair));

            (*(result + *length - 1)).first = number;
            (*(result + *length - 1)).divisorSquare = sum;

            (*length)++;
        }
    }

    (*length)--;

    return result;
}
