#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char *argv[])
{
    //flag���P�_�O�r���٬O�Ÿ����X�СAcount���X�Ӧr��
    int i, flag, count;
    char string[SIZE];

    fflush(stdin);
    gets(string);

    i = flag = count = 0;
    do {
        //65 ~ 90 �P 97 ~ 122 ���^��r��ASCII�϶��A32 ~ 47 �P 58 ~ 63 ���Ÿ�ASCII�϶�
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
