#include <stdio.h>

int main(int argc, char *argv[])
{
    int velocity, times;

    fflush(stdin);
    while (~scanf("%d %d", &velocity, &times)) {
        printf("%d\n", velocity * times * 2);
    }

    return 0;
}
