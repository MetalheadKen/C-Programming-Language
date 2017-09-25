#include <stdio.h>

void DeduceScore(int, int);

int main(int argc, char *argv[])
{
    int times, scoreSum, scoreSubtract;

    fflush(stdin);
    while (~scanf("%d", &times)) {
        while (times--) {
            scanf("%d %d", &scoreSum, &scoreSubtract);
            DeduceScore(scoreSum, scoreSubtract);
        }
    }

    return 0;
}

void DeduceScore(int sum, int subtract)
{
    int scoreA = (sum + subtract) / 2;
    int scoreB = sum - scoreA;
    
    if (scoreB < 0)
        printf("impossible\n");
    else
        printf("%d %d\n", scoreA, scoreB);
}
