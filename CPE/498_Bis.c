#include <stdio.h>
#include <math.h>

#define LENGTH 100000

int EvaluatePolynomial(int, int *, int);

int main(int argc, char *argv[])
{
    int x, coefficient[LENGTH] = {0};

    fflush(stdin);
    while (~scanf("%d", &x)) {
        int length = 0;

        while (~scanf("%d", coefficient + length))
            length++;
        
        printf("%d\n", EvaluatePolynomial(x, coefficient, length - 1));
    }

    return 0;
}

int EvaluatePolynomial(int x, int *coefficient, int length)
{
    int sum = 0;
    for (int i = 0; i <= length; i++)
        sum += coefficient[i] * (length - i) * pow(x, length - i - 1);

    return sum;
}
