#include <stdio.h>

#define KUTI  10000000
#define LAKH  100000
#define HAJAR 1000
#define SHATA 100

typedef unsigned long long int uint64;

void BanglaNumber(uint64);

int main(int argc, char *argv[])
{
    uint64 number;
    size_t testCaseTimes = 0;

    fflush(stdin);
    while (~scanf("%llu", &number)) {
        printf("%d.", ++testCaseTimes);

        if (number == 0) printf(" 0");
        BanglaNumber(number);
        printf("\n");
    }

    return 0;
}

void BanglaNumber(uint64 number)
{
    if (number >= KUTI) {
        BanglaNumber(number / KUTI);
        printf(" kuti");
        number %= KUTI;
    }

    if (number >= LAKH) {
        BanglaNumber(number / LAKH);  
        printf(" lakh");
        number %= LAKH;
    }

    if (number >= HAJAR) {
        BanglaNumber(number / HAJAR);  
        printf(" hajar");
        number %= HAJAR;
    }
        
    if (number >= SHATA) {
        BanglaNumber(number / SHATA);  
        printf(" shata");
        number %= SHATA;
    }

    if (number)
        printf(" %llu", number);
}
