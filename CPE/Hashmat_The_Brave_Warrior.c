#include <stdio.h>
#include <stdlib.h>

#define MAX 4294967296 //2 ^ 32 = 4294967296

int main(int argc, char *argv[])
{
    /* Because unsigned int can't stored 2 ^ 32, so we use long long int  */
    long long int warrior1, warrior2;

    fflush(stdin);
    while (~scanf("%lld %lld", &warrior1, &warrior2)) {
        if (warrior1 > MAX || warrior2 > MAX) exit(1);

        printf("%lld\n", (long long int) abs(warrior1 - warrior2));
    }

    return 0;
}
