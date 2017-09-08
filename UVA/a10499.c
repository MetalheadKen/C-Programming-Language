#include <stdio.h>

//分兩塊的表面積會佔兩個半圓為50%，分三塊的表面積會多75%
int main(int argc, char *argv[])
{
    long long value;

    fflush(stdin);
    while(~scanf("%lld", &value) && value > 0) {
        if(value == 1)
            printf("0%%\n");
        else
            printf("%lld%%\n", value * 25);
    }

    return 0;
}
