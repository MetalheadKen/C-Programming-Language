#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10

#define SWAP(X, Y) ((X) = (X) ^ (Y) ^ ((Y) = (X)))

void ReverseString(char *, int, int);

int main(int argc, char *argv[])
{
    char numberA[LENGTH] = {0}, numberB[LENGTH] = {0};

    fflush(stdin);
    while (~scanf("%s %s", numberA, numberB)) {
        if (numberA[0] == '0' && numberA[1] == '\0' && numberB[0] == '0' && numberB[1] == '\0') return 0;

        int carry = 0, carryCount = 0;

        /* Reverse the string, let that can add the number form units digit  */
        ReverseString(numberA, 0, strlen(numberA) - 1);
        ReverseString(numberB, 0, strlen(numberB) - 1);
        
        /* Count the number of carry operations */
        for (int i = 0; i < LENGTH; i++) {
            int temp  = numberA[i] + numberB[i] + carry;
            carry = (temp - 0x60) / 10;

            if (carry > 0) carryCount++;
        }
        
        switch (carryCount) {
            case 0:
                    printf("No carry operation.\n");
                    break;
            case 1:
                    printf("%d carry operation.\n", carryCount);
                    break;
            default:
                    printf("%d carry operations.\n", carryCount);
        }
    }

    return 0;
}

void ReverseString(char *string, int start, int end)
{
    if (start >= end) return;

    SWAP(*(string + start), *(string + end));
    return ReverseString(string, start + 1, end - 1);
}
