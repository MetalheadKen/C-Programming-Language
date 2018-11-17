#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr)         \
    (sizeof(arr) / sizeof(((typeof(arr)){})[0]))

#define TYPE_CHECK(TYPE, VAR)   \
    ({  TYPE X;                 \
        typeof(VAR) Y;          \
        (void) (&X == &Y);      \
        1;                      \
     })

int main(void)
{
    int a[100] = {0};
    int *b = (int *) malloc(100 * sizeof(*b));

    printf("%lu\n", ARRAY_SIZE(a));
    TYPE_CHECK(typeof(int [100]), a);

    return 0;
}
