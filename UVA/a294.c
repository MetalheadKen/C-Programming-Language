#include <stdio.h>

#define MAX 10000

int Factor(int);

int main(int argc, char *argv[])
{
    int i, n, rang1, rang2, max, max_index; //n為測資數量

    fflush(stdin);
    scanf("%d", &n);

    while(n--) {
        int divisor[MAX + 1] = {0};

        max = max_index = 0;
        scanf("%d %d", &rang1, &rang2);

        if((rang2 - rang1) > 10000)
            return 1;

        printf("Between %d and %d, ", rang1, rang2);

        for(i = rang1; i <= rang2; i++) {
            divisor[i - rang1] = Factor(i); //從0開始放數字

            if(max < divisor[i - rang1]) {
                max = divisor[i - rang1];
                max_index = i;
            }
        }

        printf("%d has a maximum of %d divisors.\n", max_index, max);
    }

    return 0;
}

int Factor(int number)
{
    int i, count = 0;

    for(i = 1; i <= number; i++) {
        if(number % i == 0)
            count++;
    }

    return count;
}
