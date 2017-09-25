#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100
#define LETTER_CLASS 26

typedef struct _Letter {
    char ascii;
    int  count;
} Letter;

void CountCharacter(Letter *, const char *);
int Compare(const void *, const void *);

int main(int argc, char *argv[])
{
    int  inputTimes;
    char string[LENGTH];
    Letter letter[LETTER_CLASS];
    
    fflush(stdin);
    while (~scanf("%d\n", &inputTimes)) {
        /* Initialize the variable of letter */
        for (int i = 0; i < LETTER_CLASS; i++) {
            letter[i].ascii = 'A' + i;
            letter[i].count = 0;
        }

        for (int i = 0; i < inputTimes; i++) {
            fgets(string, LENGTH, stdin);
            CountCharacter(letter, string);
        }

        qsort(letter, LETTER_CLASS, sizeof(letter[0]), Compare);

        for (int i = 0; i < LETTER_CLASS; i++)
            if (letter[i].count)
                printf("%c %d\n", letter[i].ascii, letter[i].count);
            else break;
    }

    return 0;
}

void CountCharacter(Letter *letter, const char *string)
{
    while (*string) {
        if (*string >= 'A' && *string <= 'Z')
            letter[*string - 'A'].count++;
        else if (*string >= 'a' && *string <= 'z')
            letter[*string - 'a'].count++;
        string++;
    }
}

int Compare(const void *letter1, const void *letter2)
{
    Letter *letterA = (Letter *) letter1;
    Letter *letterB = (Letter *) letter2;

    if (letterA->count == letterB->count)
        return letterA->ascii - letterB->ascii;
    else
        return letterB->count - letterA->count;
}
