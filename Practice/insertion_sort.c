#include <stdio.h>
#include <string.h>

#define LENGTH 20

void Insertion_Sort(char (*)[LENGTH], char *, int); 

int main(void)
{
    int input_count;
    char input[LENGTH] = {0};

    scanf("%d", &input_count);

    char str_arr[input_count][LENGTH];

    setbuf(stdin, NULL);
    for (int i = 1; i <= input_count; i++) {
        scanf("%s", input);
        Insertion_Sort(str_arr, input, i);
    }

    printf("\n");
    for (int i = 0; i < input_count; i++) {
        printf("%s\n", str_arr[i]);
    }

    return 0;
}

void Insertion_Sort(char (*str_arr)[LENGTH], char *str, int count)
{
    int i = 0;

    for (i = 0; i < count; i++) {
        if (strcmp(str, str_arr[i]) < 0) {
            for (int j = count - 1; j > i; j--) {
                strcpy(str_arr[j], str_arr[j - 1]);
            }
            
            strcpy(str_arr[i], str);
            break;
        }
    }

    if (i == count) strcpy(str_arr[i - 1], str);
}
