#include <stdio.h>

typedef unsigned long long int uint64;

uint64 FindGroup(uint64, uint64);

int main(int argc, char *argv[])
{
    uint64 startGroup, day;
    
    fflush(stdin);
    while (~scanf("%lld %lld", &startGroup, &day))
        printf("%lld\n", FindGroup(startGroup, day));

    return 0;
}

uint64 FindGroup(uint64 startGroup , uint64 day)
{
    uint64 answerGroup = startGroup;

    for (int sum = 0; sum < day; answerGroup++)
        sum += answerGroup;

    return answerGroup - 1;
}
