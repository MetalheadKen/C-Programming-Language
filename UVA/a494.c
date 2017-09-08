#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char *argv[])
{
    //flag為判斷是字元還是符號的旗標，count為幾個字母
    int i, flag, count;
    char string[SIZE];

    fflush(stdin);
    gets(string);

    i = flag = count = 0;
    do {
        //65 ~ 90 與 97 ~ 122 為英文字母ASCII區間，32 ~ 47 與 58 ~ 63 為符號ASCII區間
        if(((90 >= string[i] && string[i] >= 65) || (122 >= string[i] && string[i] >= 97)) && flag == 0) {
            count++;
            flag = 1;
        } else if((47 >= string[i] && string[i] >= 32) || (63 >= string[i] && string >= 58))
            flag = 0;

        i++;
    } while(i < strlen(string));

    printf("%d\n", count);

    return 0;
}
