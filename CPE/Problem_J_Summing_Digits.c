#include <stdio.h>

int SumDigits(int);

int main(int argc, char *argv[])
{
    int number;
    
    fflush(stdin);
    while (~scanf("%d", &number) && number != 0) {
        while (number / 10)
            number = SumDigits(number);
        printf("%d\n", number);
    }

    return 0;
}

int SumDigits(int number)
{
    if (number / 10 == 0)
        return number;
    else
        return number % 10 + SumDigits(number / 10);
}
