#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, left, height, right; //left���ؿv�������y�СAheight���ؿv�����סA right���ؿv���k�y��
    int rightest = 0, build[10005] = {0}; //rightest���̥k�y�СAbuild�����G��

    while(~scanf("%d %d %d", &left, &height, &right)) {
        for(i = left; i < right; i++) {
            if(height > build[i])
                build[i] = height; //�k�ݳB���O������
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
