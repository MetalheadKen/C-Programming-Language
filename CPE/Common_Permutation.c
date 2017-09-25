#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 1000

void FindTheSame(char *, char *, char *);
int Compare(const void *, const void *);

int main(int argc, char *argv[])
{
    char stringA[LENGTH], stringB[LENGTH];
    
    fflush(stdin);
    while (~scanf("%[^\n]%*c %[^\n]%*c", stringA, stringB)) {
        char answer[LENGTH] = {0};
        FindTheSame(stringA, stringB, answer);

        qsort(answer, strlen(answer), sizeof(answer[0]), Compare);

        printf("%s\n", answer);
    }

    return 0;
}

void FindTheSame(char *stringA, char *stringB, char *answer)
{
    int lengthA = strlen(stringA), lengthB = strlen(stringB);
    int position = 0;

    for (int i = 0; i < lengthA; i++) {
        for (int j = 0; j < lengthB; j++) {
            if (stringA[i] == ' ') continue;
            
            if (stringA[i] == stringB[j]) {
                int l = 0, answerLength = strlen(answer);

                while (l < answerLength && stringA[i] != answer[l])
                    l++;
                
                if (l >= answerLength) {
                    answer[position++] = stringA[i];
                    break;
                }
            }
        }
    }
}

int Compare(const void *letterA, const void *letterB)
{
    return (*(char *) letterA) - (*(char *) letterB);
}
