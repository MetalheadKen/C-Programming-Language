#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUM 4 
#define LENGTH 4 

#define ARRAY_SIZE(arr) \
            (sizeof(arr) / sizeof(((typeof(arr)){})[0]))

typedef struct Ans {
    int x;
    int y;
} Ans;

void Combination(int *, int, int, int);

int main(void)
{
    int array[LENGTH] = {0};

    srand(time(NULL));

    for (int i = 0; i < LENGTH; i++) {
        /* Get random values */
        array[i] = rand() % sizeof(LENGTH);
        printf("%d ", array[i]);
    }
    printf("\n");

    /* Print the answer */
    Combination(array, 0, 0, ARRAY_SIZE(array));

    return 0;
}

void Combination(int *arr, int posA, int posB, int len) {
    if (posB >= len) {
        posB = 0; posA += 1;
    }
    if (posA >= posB) {
        posB = posA;
    }
    if (posA >= len) {
        return;
    }
    
    if (arr[posA] + arr[posB] == SUM) {
        printf("posA=%d posB=%d\n", posA, posB);
    } 
    
    printf("%d %d\n", posA, posB);
    Combination(arr, posA, posB + 1, len);
}
