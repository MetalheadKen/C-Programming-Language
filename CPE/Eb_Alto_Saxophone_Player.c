#include <stdio.h>
#include <stdlib.h>

#define LENGTH 201
#define FINGER 12

char *FINGER_OCTAVE[] =  {
    "c0111001111", "d0111001110",
    "e0111001100", "f0111001000",
    "g0111000000", "a0110000000",
    "b0100000000",

    "C0010000000", "D1111001110",
    "E1111001100", "F1111001000",
    "G1111000000", "A1110000000",
    "B1100000000"
};

void CountFinger(int *, char *);

int main(int argc, char *argv[])
{
    int times;
    char song[LENGTH];

    fflush(stdin);
    while (~scanf("%d%*c", &times)) {
        while (times--) {
            int fingerCount[FINGER] = {0};
            
            fgets(song, LENGTH, stdin);
            CountFinger(fingerCount, song);
        
            for (int i = 1; i < FINGER - 1; i++)
                printf("%d ", fingerCount[i]);
            
            printf("\n");
        }
    }

    return 0;
}

void CountFinger(int *count, char *song)
{
    char finger[FINGER] = {0};
    char *previousFinger, *currentFinger;

    currentFinger = finger;
    for (int i = 0; song[i] != '\n'; i++) {
        /* Find the fingering that needed for this octave */
        for (int j = 0; j < 14; j++) {
            if (song[i] == FINGER_OCTAVE[j][0]) {
                previousFinger = currentFinger;
                currentFinger = FINGER_OCTAVE[j];
                break;
            }
        }

        /* If the finger is turn 0 to 1, then count it */
        for (int j = 1; j < FINGER - 1; j++) {
            count[j] += (previousFinger[j] != currentFinger[j] && currentFinger[j] == '1');
        }
    }
}
