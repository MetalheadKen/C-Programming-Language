#include <stdio.h>

#define MAX 50

int main(int argc, char *argv[])
{
    int i, t, countM, countF; //t為測資數量
    char string[MAX + 1] ;

    fflush(stdin);
    scanf("%d", &t);

    while(t--) {
        fflush(stdin);
        gets(string);

        countM = countF = 0;
        for(i = 0; string[i]; i++) {
            if(string[i] == 'M')
                countM++;
            else if(string[i] == 'F')
                countF++;
        }

        if(countM == countF)
            printf("LOOP\n");
        else
            printf("NOLOOP\n");
    }

    return 0;
}
