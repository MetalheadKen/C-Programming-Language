#include <stdio.h>
#include <stdlib.h>

#define MAX 2147483648 //2 ^ 31 = 2147483648

int main(int argc, char *argv[])
{
    //n���X�մ���Astep���ֻ̤ݨ����B�ơAlength���U�@�B�ҭn��������
    //sum���ثe�Ҩ����Z���Adistance��x����y���Z��
    int n, step, length;
    long long int x, y, sum, distance;

    fflush(stdin);
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &x, &y);
        if(x < 0 || x > y || y >= MAX) exit(1);

        sum = step = 0, distance = y - x;
        for(length = 0;;) {
            ++length;
            if(sum + 2 * length > distance) break;

            sum += 2 * length;
            step += 2;
        }

        if(sum + length < distance)
            step += 2;
        else if(sum != distance)
            step += 1;

        printf("%d\n", step);
    }

    return 0;
}
