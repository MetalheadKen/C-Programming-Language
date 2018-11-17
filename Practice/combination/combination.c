#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUM    10
#define LENGTH 10

#define MAX(X, Y) \
            ((Y & ((X - Y) >> 31))  | ((X & (~(X - Y) >> 31))))

#define ARRAY_SIZE(ARR) \
            (sizeof(ARR) / sizeof(((typeof(ARR)){})[0]))

void Combination(int *, int, int, int);

int main(void)
{
    int array[LENGTH] = {0};

    srand(time(NULL));

    for (int i = 0; i < LENGTH; i++) {
        /* Get random values */
        array[i] = rand() % ARRAY_SIZE(array);
        printf("%d ", array[i]);
    }
    printf("\n");

    /* Print the answer */
    Combination(array, 0, 0, ARRAY_SIZE(array));

    return 0;
}

void Combination(int *arr, int posA, int posB, int len) {
    posA += (posB >= len);
    posB = MAX(posA, (posB % len));

    if (posA >= len) return;
    
    if (arr[posA] + arr[posB] == SUM) {
        printf("posA=%2d posB=%2d numA=%2d numB=%2d\n", posA, posB, arr[posA], arr[posB]);
    } 
    
    //printf("%d %d\n", posA, posB);
    Combination(arr, posA, posB + 1, len);
}
