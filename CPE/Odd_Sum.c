#include <stdio.h>

int main(int argc, char *argv[])
{
    int times, start, end;

    fflush(stdin);
    while (~scanf("%d", &times)) {
        for (int i = 1; i <= times; i++) {
            scanf("%d %d", &start, &end);

            /* Turn variable start and end to odd number */
            start += (!(start & 1));
            end -= (!(end & 1));
            
            printf("Case %d: %d\n", i, (start + end) * ((end - start) + 2) / 4);
        }
    }

    return 0;
}
