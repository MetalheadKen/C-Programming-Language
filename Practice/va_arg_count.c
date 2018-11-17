#include <stdio.h>
#include <stdarg.h>

#define VA_NARG_IMPL(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N

/* Delete preceding comma if __VA_ARGS__ is empty */
#define VA_NARG(...) VA_NARG_IMPL(_, ## __VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
//#define VA_NARG(...) (sizeof((int []) { __VA_ARGS__ }) / sizeof(int))

#define PRINT_ARGS(...) print_args(VA_NARG(__VA_ARGS__), __VA_ARGS__)

void print_args(int, ...);

int main(void)
{
    PRINT_ARGS(3, 5, 7, 9, 11);

    return 0;
}
 
void print_args(int count, ...)
{
    va_list list;

    va_start(list, count);

    while (count--) {
        int num = va_arg(list, int);
        printf("%d ", num);
    }
    printf("\n");

    va_end(list);
}

