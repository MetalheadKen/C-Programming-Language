#include <stdio.h>

void Count_Stack(int);

int main(void)
{
    Count_Stack(0);

    return 0;
}

void Count_Stack(int count) {
    printf("now stack conter = %d\n", count);
    Count_Stack(count + 1);
}
