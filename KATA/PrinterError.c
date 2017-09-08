#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

char *PrinterError(char *);

int main(int argc, char *argv[])
{
    char string[LENGTH] = {0};

    fflush(stdin);
    gets(string);

    char *result = PrinterError(string);

    puts(result);
    free(result);

    return 0;
}

char *PrinterError(char *string)
{
    int length = 0, errorCount = 0;

    /* Calculate of Error Count */
    while(*string) {
        errorCount += (*string < 'a' || *string > 'm');

        string++;
        length++;
    }

    char *result = (char *)malloc(length * sizeof(char));
    sprintf(result, "%d/%d", errorCount, length);
    //asprintf(&result, "%d/%d", errorCount, length);

    return result;
}
