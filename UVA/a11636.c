#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int index = 1, n, print;

    while(~scanf("%d", &n) && n != -1) {
        if(n <= 0 || n >= 1001)
            return 1;

        //��Xn��2���X����A�è�����W�ɤ����
        print = ceil(log2(n));

        printf("Case %d�G %d\n", index++, print);
    }

    return 0;
}
