#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LENGTH 1000

bool IsEleven(char *);

int main(int argc, char *argv[])
{
    char number[LENGTH];

    fflush(stdin);
    while (gets(number) != NULL) {
        if (!strcmp(number, "0")) break;

        printf("%s ", number);

        if (IsEleven(number))
            printf("is a multiple of 11.\n");
        else
            printf("is not a multiple of 11.\n");
    }

    return 0;
}

bool IsEleven(char *number)
{
    for (int i = strlen(number) - 1; i > 0; i--) {      
        if (number[i] > number[i - 1]) {
            /* Borrow Digit */
            for(int j = i - 2; j >= 0; j--) {
                if (number[j] == '0')
                    number[j] = '9';
                else {
                    number[j]--; break;
                }
            }

            number[i - 1] = number[i - 1] + 10 - (number[i] - 0x30);
        } else
            number[i - 1] = number[i - 1] - number[i] + 0x30;

        number[i] = 0;
    }
    
    return (number[0] == '0');
}
