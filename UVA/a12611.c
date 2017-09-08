#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //t為測資數量，r為圓的半徑，length為長方形的長，width為長方形的寬，right為右線段，left為左線段
    int i, t, r, length, width, right, left;

    fflush(stdin);
    scanf("%d", &t);

    for(i = 1; i <= t; i++) {
        scanf("%d", &r);

        length 	= r * 5;
        width 	= length * 60 / 100;
        right 	= length * 55 / 100;
        left 	= length * 45 / 100;

        //印出左上、右上、右下、左下座標
        printf("Case%d：\n", i);
        printf("%d %d\n", width / 2, -left);
        printf("%d %d\n", right, width / 2);
        printf("%d %d\n", right, -width / 2);
        printf("%d %d\n", -left, -width / 2);
    }

    return 0;
}
