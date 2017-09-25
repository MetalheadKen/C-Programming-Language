#include <stdio.h>

void CountMines(int, int, char [*][*]);

int main(int argc, char *argv[])
{
    int row, column, times = 1;

    fflush(stdin);
    while (~scanf("%d %d%*c", &row, &column) && row != 0 || column != 0) {
        char field[row + 1][column + 1];
        
        for (int i = 1; i < row + 1; i++) {
            for (int j = 1; j < column + 1; j++) {
                scanf("%c", &field[i][j]);
                if (field[i][j] == '.')
                    field[i][j] = 0;
            }
            getchar();
        }

        CountMines(row, column, field);

        printf("Field #%d:\n", times++);
        for (int i = 1; i < row + 1; i++) {
            for (int j = 1; j < column + 1; j++) {
                if(field[i][j] == '*')
                    printf("%c", field[i][j]);
                else
                    printf("%d", field[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

void CountMines(int row, int column, char field[row + 1][column + 1])
{
    for (int i = 1; i < row + 1; i++) {
        for (int j = 1; j < column + 1; j++) {
            if (field[i][j] == '*') {
                if (field[i][j - 1] != '*') field[i][j - 1]++;
                if (field[i][j + 1] != '*') field[i][j + 1]++;
                if (field[i - 1][j] != '*') field[i - 1][j]++;
                if (field[i + 1][j] != '*') field[i + 1][j]++;
                if (field[i - 1][j + 1] != '*') field[i - 1][j + 1]++;
                if (field[i + 1][j - 1] != '*') field[i + 1][j - 1]++;
                if (field[i - 1][j - 1] != '*') field[i - 1][j - 1]++;
                if (field[i + 1][j + 1] != '*') field[i + 1][j + 1]++;
            }
        }
    }
}
