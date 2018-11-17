#include <stdio.h>
#include <string.h>

#define LENGTH 10

void Merge(char (*)[LENGTH], int, int, int);
void Merge_Sort(char (*)[LENGTH], int, int);

int main(void)
{
    char string[][LENGTH] = {
        "Ken", "Cindy", "David", "Amy",
    };

    int length = sizeof(string) / sizeof(char [LENGTH]);

    Merge_Sort(string, 0, length - 1);

    /* Print the answer */
    for (int i = 0; i < length; i++) {
        printf("%s\n", string[i]);
    }

    return 0;
}

void Merge_Sort(char (*str)[LENGTH], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        Merge_Sort(str, low, mid);
        Merge_Sort(str, mid + 1, high);
        Merge(str, low, mid, high);
    }
}

void Merge(char (*dst)[LENGTH], int low, int mid, int high) {
    int i = 0, j = 0, k = low;

    int len_l = mid - low + 1;
    int len_r = high - mid;
    
    char src_l[len_l][LENGTH];
    char src_r[len_r][LENGTH];

    /* Copy data to temp array src_l and src_r */
    for (int i = 0; i < len_l; i++) {
        strcpy(src_l[i], dst[low + i]);
    }
    for (int j = 0; j < len_r; j++) {
        strcpy(src_r[j], dst[mid + 1 + j]);
    }

    /* Merge two array into array dst in ascending order */
    while (i < len_l && j < len_r) {
        if (strcmp(src_l[i], src_r[j]) < 0) {
            strcpy(dst[k], src_l[i]);
            i++;
        } else {
            strcpy(dst[k], src_r[j]);
            j++;
        }
        k++;
    }

    /* Copy remaining data to array dst */
    while (i < len_l) {
        strcpy(dst[k], src_l[i]);
        i++; k++;
    }
    while (j < len_r) {
        strcpy(dst[k], src_r[j]);
        j++; k++;
    }
}

