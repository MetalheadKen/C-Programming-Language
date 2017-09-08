#include <stdio.h>
#include <stdlib.h>

#define SIZE 1500
inline int min(int x, int y)
{
    return (x < y) ? x : y;
}

int main(int argc, char *argv[])
{
    //m2, m3, m5為從前N項中一項去* 2, * 3, * 5，pre_number為要找的前一項
    int i, m2, m3, m5, pre_number;
    int number[SIZE] = {1};

    m2 = m3 = m5 = 0;
    i = pre_number = number[0] = 1;

    //從第二項開始找(i = 1)
    for(i = 1; i < SIZE; i++) {
        for(; m2 < i; m2++) {
            if(number[m2] * 2 > pre_number)
                break;
        }
        for(; m3 < i; m3++) {
            if(number[m3] * 3 > pre_number)
                break;
        }
        for(; m5 < i; m5++) {
            if(number[m5] * 5 > pre_number)
                break;
        }

        //把前N-1項中找出各* 2，* 3，* 5會大於第N-1項的最小值即為第N項
        pre_number = min(number[m2] * 2, min(number[m3] * 3, number[m5] * 5));
        number[i] = pre_number;
    }

    printf("The 1500'th ugly number is <%d>", number[1499]);

    return 0;
}
