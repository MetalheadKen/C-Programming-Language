#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 102
#define COLUMN 102

#define max(x, y) ((x) > (y) ? (x) : (y))

void Rotate(char (*string)[COLUMN], int row, int column)
{
    int i, j;

    //︽锣传
    for(i = 0; i < column; i++) {
        for(j = row - 1; j >= 0; j--) {
            if(string[j][i] == 0) {
                printf(" ");
                continue;
            }

            printf("%c", string[j][i]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[])
{
    int max_row, max_length; //max_row程︽计max_length程
    char string[ROW][COLUMN] = {'\0'};

    fflush(stdin);
    max_row = max_length = 0;
    while(gets(string[max_row]) != NULL) {
        max_length = max(max_length, strlen(string[max_row]));
        max_row++;
    }

    Rotate(string, max_row, max_length);

    return 0;
}
