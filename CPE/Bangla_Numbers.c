#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 15

void BanglaNumber(char *, char **, const char *, int);

int main(int argc, char *argv[])
{
    char   number[LENGTH];
    size_t testCaseTimes = 0;

    fflush(stdin);
    while (gets(number) != NULL) {
        char *outputString = (char *) malloc(sizeof(char));
        *outputString = '\0';
    
        /* Splitting from the last place of string */
        BanglaNumber(number, &outputString, "", 2);

        while (number[0] != '\0') {
            BanglaNumber(number, &outputString, " shata ", 1);
            BanglaNumber(number, &outputString, " hajar ", 2);
            BanglaNumber(number, &outputString, " lakh ",  2);
            BanglaNumber(number, &outputString, " kuti ",  2);
        }

        printf("%d. %s\n", ++testCaseTimes, outputString);
    }

    return 0;
}

void BanglaNumber(char *number, char **outputString, const char *constString, int printLength)
{
    int  length = strlen(number);
    char tempString[printLength + 1];
    char *banglaString = (char *) malloc((printLength + strlen(constString) + 1) * sizeof(char));

    /* Get the string with a length of printLength */
    if (length > 1) {
        for (int i = 0, j = length - printLength; j <= length; i++, j++)
            tempString[i] = number[j];
    } else
        tempString[0] = number[length - 1];

    /* String combination */
    int value = atoi(tempString);
    if (value) {
        strcpy(banglaString, tempString);
        strcat(banglaString, constString);

        char temporaryString[strlen(*outputString) + 1];
        strcpy(temporaryString, *outputString);

        *outputString = (char *) realloc(*outputString, (printLength + strlen(constString) + strlen(*outputString) + 1) * sizeof(char));
        sprintf(*outputString, "%s%s", banglaString, temporaryString);
    }
    
    free(banglaString);
    number[length - printLength] = '\0';
}
