#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char character[3];
    int n, ans, number; //n為輸入幾筆資料

    fflush(stdin);
    scanf("%d", &n);

    while(n--) {
        fflush(stdin);
        scanf("%3s-%d", character, &number);

        ans = ((character[0] - 'A') * 26 * 26 + (character[1] - 'A') * 26 + (character[2] - 'A') * 1);

        if(abs(ans - number) <= 100)
            printf("nice\n");
        else
            printf("not nice\n");
    }

    return 0;
}
