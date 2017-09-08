/*
 ============================================================================
 Name        : VeigarHouse.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int *door, int count)
{
    int i, j, temp;

    for(i = count - 2; i >= 0; i--) {
        for(j = 0; j <= i; j++) {
            if(door[j] > door[j + 1]) {
                temp = door[j];
                door[j] = door[j + 1];
                door[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int i, count, door[20], middle, sum = 0;

    printf("�п�J�˱��ƶq�G");
    fflush(stdin);
    scanf("%d", &count);

    if((count <= 1) || (count >= 20)) {
        printf("�п�J1~20���Ʀr!!!\7\7\7");
        return 0;
    }

    printf("�п�J%d���˱��a�������G", count);

    for(i = 0; i < count; i++)
        scanf("%d", &door[i]);

    sort(door, count);

    middle = door[count / 2];
    for(i = 0; i < count; i++)
        sum += abs(middle - door[i]);

    printf("��U�ӿ˱��a���`�M�G\n%d", sum);

    return EXIT_SUCCESS;
}
