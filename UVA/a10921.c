#include <stdio.h>

#define MAX 30

int main(int argc, char *argv[])
{
    //A~Z¼Æ¦rÂà´«
    const char table[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    int i;
    char string[MAX + 1];

    fflush(stdin);
    while(gets(string) != NULL) {
        for(i = 0; string[i]; i++) {
            if(string[i] >= 'A' && string[i] <= 'Z')
                string[i] = table[string[i] - 'A'] + '0';
        }

        puts(string);
    }

    return 0;
}
