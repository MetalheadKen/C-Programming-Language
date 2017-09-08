#include <stdio.h>

#define MAX 10

int main(int argc, char *argv[])
{
    int i, n, number[MAX], count1, count2, flag = 1; //n為測資數量

    fflush(stdin);
    scanf("%d", &n);

    while(n--) {
        for(i = 0; i < MAX; i++)
            scanf("%d", &number[i]);

        count1 = count2 = 0;
        for(i = 0; i < MAX - 1; i++) {
            if(number[i] < number[i + 1])
                count1++;
            else
                count2++;
        }

        if(flag-- > 0)
            printf("Lumberjacks:\n");

        if(count1 == 9 || count2 == 9)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }

    return 0;
}
