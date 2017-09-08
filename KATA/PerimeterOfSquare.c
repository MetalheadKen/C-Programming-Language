#include <stdio.h>

typedef unsigned long long uint64;

uint64 PerimeterOfSquare(int);
uint64 FibonacciSequence(int);

int main(int argc, char *argv[])
{
    int number = 0;

    fflush(stdin);
    scanf("%d", &number);

    printf("%llu\n", PerimeterOfSquare(number));

    return 0;
}

uint64 PerimeterOfSquare(int number)
{
    uint64 perimeter = 0;

    /* Add All Perimeter of Square */
    for(int i = 0; i <= number + 1; i++) {
        perimeter += FibonacciSequence(i);
    }

    return perimeter * 4;
}

uint64 FibonacciSequence(int number)
{
    if(number == 0) {
        return 0;
    } else if(number == 1) {
        return 1;
    }

    return FibonacciSequence(number - 1) + FibonacciSequence(number - 2);
}
