#include <stdio.h>
#include "inline.h" 

int main(void)
{
    int a = 1, b = 2;
    int c = add(a, b);

    printf("%d\n\n", c);

    return 0;
}
