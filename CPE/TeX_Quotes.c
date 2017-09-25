#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LENGTH 1000

void ReplaceQuote(char *);

int main(int argc, char *argv[])
{
    char string[LENGTH];
    
    fflush(stdin);
    while (~scanf("%[^\n]%*c", string)) {
        ReplaceQuote(string);
        printf("\n");
    }

    return 0;
}

void ReplaceQuote(char *string)
{
    bool flag = 0;

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '"') {
            switch (flag)  {
                case 0: printf("``"); break;
                case 1: printf("''");
            }

            flag = !flag; continue;
        }
        printf("%c", string[i]);
    }
}
