#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH      20
#define LINE_LENGTH 6

#define ROW         4
#define COLUMN      5

#define SWAP(X, Y) ((X) = (X) ^ (Y) ^ (Y = X))

typedef char *(*FuncPtr)(char *);

char *MoveInSquaredString(FuncPtr, char *);
char *RowColumnConvert(char *);
char *RotateNinetyDegree(char *);
char *SelfWithRowColumnConvert(char *);

int main(int argc, char *argv[])
{
    char buffer[LINE_LENGTH], string[LENGTH] = {0};

    fflush(stdin);
    for(int i = 0;
            string[LENGTH - 1] != '\n' && fgets(buffer, LINE_LENGTH, stdin) != NULL; i++) {
        strcat(string, buffer);
    }

    string[LENGTH - 1] = '\0';

    char *matrix;

    matrix = MoveInSquaredString(RowColumnConvert, string);
    printf("Symmetry with respect to the main diagonal:\n");
    printf("%s\n\n", matrix);
    free(matrix);

    matrix = MoveInSquaredString(RotateNinetyDegree, string);
    printf("Clockwise rotation 90 degrees:\n");
    printf("%s\n\n", matrix);
    free(matrix);

    matrix = MoveInSquaredString(SelfWithRowColumnConvert, string);
    printf("Initial string merge with Symmetry with respect to the main diagonal:\n");
    printf("%s\n", matrix);
    free(matrix);

    return 0;
}

char *MoveInSquaredString(FuncPtr MatrixHandler, char *string)
{
    char *matrix = (char *)malloc((strlen(string) + 1) * sizeof(char));

    strcpy(matrix, string);

    return MatrixHandler(matrix);
}

char *RowColumnConvert(char *matrix)
{
    /* Convert Row Value and Column Value */
    for(int row = 0; row < ROW; row++) {
        for(int col = row + 1; col < COLUMN - 1; col++) {
            SWAP(matrix[row * COLUMN + col], matrix[col * COLUMN + row]);
        }
    }

    return matrix;
}

char *RotateNinetyDegree(char *matrix)
{
    char *buffer = (char *)malloc((strlen(matrix) + 1) * sizeof(char));

    strcpy(buffer, matrix);

    /* Rotate 90 Degrees */
    for(int row = 0; row < ROW; row++) {
        for(int col = 0; col < COLUMN - 1; col++) {
            matrix[row * COLUMN + col] = buffer[(COLUMN - col - 2) * COLUMN + row];
        }
    }

    free(buffer);

    return matrix;
}

char *SelfWithRowColumnConvert(char *buffer)
{
    char *matrix = (char *)malloc((strlen(buffer) + 1) * 2 * sizeof(char));

    /* String Connect the Original String and the Convert Row and Column String */
    for(int row = 0; row < ROW; row++) {
        for(int col = 0; col < COLUMN * 2; col++) {
            if((buffer[row * COLUMN + col] == '\n') || (buffer[row * COLUMN + col] == '\0')) {
                matrix[row * COLUMN * 2 + col] = '|';

                col++;
                for(int i = 0; i < COLUMN - 1; i++, col++) {
                    matrix[row * COLUMN * 2 + col] = buffer[i * COLUMN + row];
                }

                matrix[row * COLUMN * 2 + col] = '\n';
                break;
            }

            matrix[row * COLUMN * 2 + col] = buffer[row * COLUMN + col];
        }
    }

    matrix[ROW * COLUMN * 2 - 1] = '\0';

    free(buffer);

    return matrix;
}
