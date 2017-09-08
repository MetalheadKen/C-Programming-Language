#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

int FindMultipleSum(int);

int main(int argc, char *argv[])
{
    int number = 0;

    fflush(stdin);
    scanf("%d", &number);

    printf("%d\n", FindMultipleSum(number));

    return 0;
}

int FindMultipleSum(int number)
{
    int sum = 0;

    /* Sum of All Multiple of Three and Five */
    sum = ((3 + (number / 3) * 3) * (number / 3)) / 2
          + ((5 + (number / 5) * 5) * (number / 5)) / 2
          - ((15 + (number / 15) * 15) * (number / 15)) / 2;

    return sum;
}
