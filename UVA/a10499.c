#include <stdio.h>

//����������n�|����ӥb�ꬰ50%�A���T�������n�|�h75%
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
