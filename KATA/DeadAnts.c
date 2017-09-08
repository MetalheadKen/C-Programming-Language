#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

enum {ANTS_HEAD, ANTS_BODY, ANTS_FOOT, ANTS_LENGTH};

int DeadAntsCount(const char *);

int main(int argc, char *argv[])
{
    char string[LENGTH] = {0};

    fflush(stdin);
    gets(string);

    printf("%d\n", DeadAntsCount(string));

    return 0;
}

int DeadAntsCount(const char *ants)
{
    int deadCount[ANTS_LENGTH] = {0};
    int max = 0, length = strlen(ants);

    /* Count The Dead Ants */
    for(int i = 0; i < length; i++) {
        if(ants[i] == 'a' && ants[i + 1] == 'n' && ants[i + 2] == 't') {
            i += 2;
        } else if(ants[i] == 'a') deadCount[ANTS_HEAD]++;
        else if(ants[i] == 'n') deadCount[ANTS_BODY]++;
        else if(ants[i] == 't') deadCount[ANTS_FOOT]++;
    }

    /* Find The Maximum Number */
    for(int i = 0; i < ANTS_LENGTH; i++) {
        if(deadCount[i] > max) {
            max = deadCount[i];
        }
    }

    return max;
}
