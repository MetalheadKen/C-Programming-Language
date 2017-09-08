#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int index = 1, n, print;

    while(~scanf("%d", &n) && n != -1) {
        if(n <= 0 || n >= 1001)
            return 1;

        //找出n為2的幾次方，並取次方上界之整數
        print = ceil(log2(n));

        printf("Case %d： %d\n", index++, print);
    }

    return 0;
}
