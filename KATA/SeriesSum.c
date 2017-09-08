#include <stdio.h>
#include <stdlib.h>

#define LENGTH 3

char *SeriesSum(int times);

int main(int argc, char *argv[])
{
    int times = 0;

    fflush(stdin);
    scanf("%d", &times);

    puts(SeriesSum(times));

    return 0;
}

char *SeriesSum(int times)
{
    char *result = (char *)malloc(LENGTH * sizeof(char));
    int denominator = 1;
    double sum = 0.0;

    /* Sum of Fraction */
    while(times--) {
        sum += 1.0 / denominator;
        denominator += 3;
    }

    /* Fraction to String */
    /* It will Automatic Rounding Output upto Two Decimal Places */
    sprintf(result, "%.2f", sum);

    return result;
}
