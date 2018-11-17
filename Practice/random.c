#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 81
#define TIMES  1000000

char table[] = {
    '9', '9', 
    '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
    'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

int main(void)
{
    int times;
    char seed[LENGTH] = {'\0'};

    srand(time(NULL));

    times = TIMES;
    while (times--) {
        /* Get random values */
        for (int i = 0; i < LENGTH; i++) {
            int position = rand() % sizeof(table);
            seed[i] = table[position];
        }
    }

    times = TIMES;
    while (times--) {
        /* Shuffle */
        for (int i = 0; i < LENGTH; i++) {
            int j = rand() % LENGTH;

            char temp = seed[i];
            seed[i] = seed[j];
            seed[j] = temp;
        }
    }

    /* Print the answer */
    printf("\n");
    for (int i = 0; i < LENGTH; i++) {
        printf("%c", seed[i]);
    }
    printf("\n");

    return 0;
}
