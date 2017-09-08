#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char *argv[])
{
    int i, sum; //sum為數字總和
    char number[SIZE] = {0};

    fflush(stdin);
    while(gets(number) != NULL	&& number[0] != '0') {
        //if(number[0] == '0' && number[1] == '\0')	break;

        //34 -> 3 - 5 * 4 ， 201 -> 20 - 5 * 1
        //sum = (number[2] * 10 + number[1] - 5 * number[0]) % 17;
        for(i = 0, sum = 0; i < strlen(number); i++) {
            sum = sum * 10 + number[i] - '0';
            sum %= 17;
        }

        if(!sum)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
