#include <stdio.h>
#include <string.h>

#define INPUT_MAX 2000
#define STRING_MAX 14

const char language[][8] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};
const char hello[][13]   = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};

void GetLanguage(char string[])
{
    short i, find = 0; //find為判斷是否有找到對應的語言

    for(i = 0; i < 6; i++) {
        if(!strcmp(string, hello[i]))
            puts(language[i]), find = 1;
    }

    if(!find) puts("UNKNOWN");
}

int main(int argc, char *argv[])
{
    int count;
    char string[STRING_MAX + 1]; //string為輸入的字串

    for(count = 1; count <= INPUT_MAX && gets(string) != NULL; count++) {
        if(string[0] == '#' && string[1] == '\0') return 0;
        if(strlen(string) > STRING_MAX) return 1;

        printf("Case %d:", count);
        GetLanguage(string);
    }

    return 0;
}
