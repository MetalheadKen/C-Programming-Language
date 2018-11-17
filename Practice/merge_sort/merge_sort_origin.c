#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

void Merge(char *, int, int, int);
void Merge_Sort(char *, int, int);

int main(void)
{
    char string[LENGTH] = { 5, 3, 4, 2, 1 };

    Merge_Sort(string, 0, sizeof(string) / sizeof(char) - 1);

    /* Print the answer */
    for (int i = 0; i < LENGTH; i++) {
        printf("%d ", string[i]);
    }
    printf("\n");

    return 0;
}

void Merge_Sort(char *str, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        Merge_Sort(str, low, mid);
        Merge_Sort(str, mid + 1, high);
        Merge(str, low, mid, high);
    }
}

void Merge(char *dst, int low, int mid, int high) {
    int i = 0, j = 0, k = low;

    int len_l = mid - low + 1;
    int len_r = high - mid;
    
    char src_l[len_l];
    char src_r[len_r];

    /* Copy data to temp array src_l and src_r */
    for (int i = 0; i < len_l; i++) {
        src_l[i] = dst[low + i];
    }
    for (int j = 0; j < len_r; j++) {
        src_r[j] = dst[mid + 1 + j];
    }

    /* Merge two array into array dst in ascending order */
    while (i < len_l && j < len_r) {
        if (src_l[i] < src_r[j]) {
            dst[k] = src_l[i];
            i++;
        } else {
            dst[k] = src_r[j];
            j++;
        }
        k++;
    }

    /* Copy remaining data to array dst */
    while (i < len_l) {
        dst[k] = src_l[i];
        i++; k++;
    }
    while (j < len_r) {
        dst[k] = src_r[j];
        j++; k++;
    }
}

