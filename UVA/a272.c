#include <stdio.h>

#define MAX 1000000

int main(int argc, char *argv[])
{
    int i, flag;
    char string[MAX + 1];

    fflush(stdin);
    while(gets(string) != NULL) {
        flag = 1;
        for(i = 0; string[i] != '\0'; i++) {
            if(string[i] == '"') {
                if(flag)
                    printf("``");
                else
                    printf("''");

                flag ^= 1;
            } else
                putchar(string[i]);
        }

        putchar('\n');
    }

    return 0;
}
