#include <stdio.h>

int CountDrink(int);

int main(int argc, char *argv[])
{
    int bottle;
    
    fflush(stdin);
    while (~scanf("%d%*c", &bottle)) {
        int drink = CountDrink(bottle);
        printf("%d\n", drink);
    }

    return 0;
}

int CountDrink(int bottle)
{
    int drink = 0, empty = 0;

    while (bottle) {
        drink += bottle;

        empty += bottle;
        bottle = empty / 3;
        empty %= 3;
    }

    return (empty == 2) ? drink + 1 : drink;
}
