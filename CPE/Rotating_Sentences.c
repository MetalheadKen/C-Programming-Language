#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW    100
#define COLUMN 100

void RotateSentences(char (*)[], int, int);

int main(int argc, char *argv[])
{
    int  maxRow = 0, maxColumn = 0;
    char string[ROW][COLUMN] = {0};
    
    fflush(stdin);
    while (~scanf("%[^\n]%*c", string[maxRow])) {
        /* Find the maximum of string length */
        int length = strlen(string[maxRow]);
        if (maxColumn < length) maxColumn = length;

        maxRow++;
    }
    RotateSentences(string, maxRow, maxColumn);
    
    return 0;
}

void RotateSentences(char (*string)[COLUMN], int row, int column)
{
    for (int i = 0; i < column; i++) {
        for (int j = row - 1; j >= 0; j--) {
            if (string[j][i])
                printf("%c", string[j][i]);
        }
        printf("\n");
    }
}
