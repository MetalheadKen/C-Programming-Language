#include <stdio.h>

int main(int argc, char *argv[])
{
    int v, t; //v為速度，t為時間

    fflush(stdin);
    while(~scanf("%d %d", &v, &t))
        printf("%d\n", 2 * v * t); //位移 = 平均速度 * 時間

    return 0;
}
