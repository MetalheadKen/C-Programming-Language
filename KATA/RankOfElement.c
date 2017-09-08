#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

size_t RankOfElement(const int *, size_t, size_t);

int main(int argc, char *argv[])
{
    int index;
    int array[LENGTH] = {0};

    fflush(stdin);
    for(int i = 0; i < LENGTH; i++) {
        scanf("%d", &array[i]);
    }

    scanf("%d", &index);

    printf("%d\n", RankOfElement(array, sizeof(array) / sizeof(array[0]), index));

    return 0;
}

size_t RankOfElement(const int *array, size_t length, size_t index)
{
    size_t count = 0;

    for(int i = 0; i < index; i++) {
        if(array[i] <= array[index]) {
            count++;
        }
    }

    for(int i = index; i < length; i++) {
        if(array[i] < array[index]) {
            count++;
        }
    }

    return count;
}
