#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int start, end;

    fflush(stdin);
    while (~scanf("%d %d", &start, &end)) {
        if (start == 0 && end == 0) return 0;

        int count = 0;
        for (int i = start; i <= end; i++) {
            if ((float) sqrt(i) * sqrt(i) == i)
                count++;
        }

        printf("%d\n", count);
    }

    return 0;
}
