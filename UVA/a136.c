#include <stdio.h>
#include <stdlib.h>

#define SIZE 1500
inline int min(int x, int y)
{
    return (x < y) ? x : y;
}

int main(int argc, char *argv[])
{
    //m2, m3, m5���q�eN�����@���h* 2, * 3, * 5�Apre_number���n�䪺�e�@��
    int i, m2, m3, m5, pre_number;
    int number[SIZE] = {1};

    m2 = m3 = m5 = 0;
    i = pre_number = number[0] = 1;

    //�q�ĤG���}�l��(i = 1)
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

        //��eN-1������X�U* 2�A* 3�A* 5�|�j���N-1�����̤p�ȧY����N��
        pre_number = min(number[m2] * 2, min(number[m3] * 3, number[m5] * 5));
        number[i] = pre_number;
    }

    printf("The 1500'th ugly number is <%d>", number[1499]);

    return 0;
}
