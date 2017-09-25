#include <stdio.h>
#include <stdlib.h>

#define LENGTH 1000
#define ASCII_LENGTH 97

typedef struct _Letter {
    int ascii;
    int count;
} Letter;

void CountCharacter(Letter *, const char *);
int Compare(const void *, const void *);

int main(int argc, char *argv[])
{
    char string[LENGTH];
    Letter letter[ASCII_LENGTH];

    fflush(stdin);
    while (~scanf("%[^\n]%*c", string)) {
        /* Initialize the variable letter */
        for (int i = 0; i < ASCII_LENGTH; i++) {
            letter[i].ascii = i + 32;
            letter[i].count = 0;
        }

        CountCharacter(letter, string);
        qsort(letter, ASCII_LENGTH, sizeof(letter[0]), Compare);

        for (int i = 0; i < ASCII_LENGTH; i++) {
            if (letter[i].count)
                printf("%d %d\n", letter[i].ascii, letter[i].count);
        }
    }

    return 0;
}

void CountCharacter(Letter *letter, const char *string)
{
    for (int i = 0; string[i]; i++)
        letter[string[i] - 32].count++;
}

int Compare(const void *letter1, const void *letter2)
{
    Letter *letterA = (Letter *) letter1;
    Letter *letterB = (Letter *) letter2;

    if (letterA->count != letterB->count)
        return letterA->count - letterB->count;
    else
        return letterB->ascii - letterA->ascii;
}
