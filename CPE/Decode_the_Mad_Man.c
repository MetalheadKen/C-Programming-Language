#include <stdio.h>
#include <string.h>

#define KEYBOARD_LENGTH 33

#define LENGTH 1000

const char keyboard[KEYBOARD_LENGTH] = {
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'
};

void DecodeSpeech(char *);

int main(int argc, char *argv[])
{
    char string[LENGTH];
    
    fflush(stdin);
    while (fgets(string, LENGTH, stdin) != NULL) {
        DecodeSpeech(string);
        fputs(string, stdout);
    }

    return 0;
}

void DecodeSpeech(char *string)
{
    for (int i = 0; i < strlen(string); i++) {
        for (int j = 0; j < KEYBOARD_LENGTH; j++) {
            if (string[i] == keyboard[j] || string[i] == (keyboard[j] ^ 32)) {
                string[i] = keyboard[j - 2];
                break;
            }
        }
    }
}
