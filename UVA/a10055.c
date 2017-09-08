#include <stdio.h>
#include <stdlib.h>

#define MAX 4294967296 //2 ^ 32 = 4294967296

int main(int argc, char *argv[])
{
    long long int warrior1, warrior2;

    while(scanf("%lld %lld", &warrior1, &warrior2) != EOF) {
        if(warrior1 > MAX || warrior2 > MAX) exit(1);

        printf("%lld\n", abs(warrior1 - warrior2));
    }

    return 0;
}
