#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j, n, count;	//n為單字數，count為one和three字母正確有幾個
    char array[5];

    fflush(stdin);
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        fflush(stdin);
        gets(array);

        count = 0;
        //判斷相同字元有幾個
        if(strlen(array) == 3) {
            if(array[0] == 'o')
                count++;
            if(array[1] == 'n')
                count++;
            if(array[2] == 'e')
                count++;
            //對兩個以上即輸出結果
            if(count > 1)
                printf("1\n");

            count = 0;
            if(array[0] == 't')
                count++;
            if(array[1] == 'o')
                count++;
            if(array[2] == 'w')
                count++;
            if(count > 1)
                printf("2\n");
        } else {
            if(array[0] == 't')
                count++;
            if(array[1] == 'h')
                count++;
            if(array[2] == 'r')
                count++;
            if(array[3] == 'e')
                count++;
            if(array[4] == 'e')
                count++;
            if(count > 3)
                printf("3\n");
        }
    }

    return 0;
}
