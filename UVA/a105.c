#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, left, height, right; //left為建築物的左座標，height為建築物高度， right為建築物右座標
    int rightest = 0, build[10005] = {0}; //rightest為最右座標，build為結果圖

    while(~scanf("%d %d %d", &left, &height, &right)) {
        for(i = left; i < right; i++) {
            if(height > build[i])
                build[i] = height; //右端處不記錄高度
        }
        rightest = (rightest < right) ? right : rightest;
    }

    for(i = 1; i <= rightest; i++) {
        if(build[i - 1] != build[i])
            printf("%d %d ", i, build[i]);
    }

    /*if(build[rightest - 1] == build[rightest])
    	printf("%d %d ", build[rightest], rightest);
    putchar('0');*/

    return 0;
}
