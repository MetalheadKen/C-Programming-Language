#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //n為測資的數量，wife_time為Danny劃分給妻子的時間在今天的第幾分鐘，meeting_time為Danny參加會議的時間在今天的第幾分鐘
    //hour[0]與minute[0]到hour[1]與minute[1]為Danny劃分給妻子的時間，hour[0]與minute[0]到hour[1]與minute[1]為Danny參加會議的時間
    int i, n, hour[2], minute[2], wife_time[2], meeting_time[2];

    fflush(stdin);
    while(~scanf("%d", &n)) {
        if(n <= 0 || n >= 2001) exit(1);

        for(i = 1; i <= n; i++) {
            scanf("%d:%d %d:%d", &hour[0], &minute[0], &hour[1], &minute[1]);
            wife_time[0] = hour[0] * 60 + minute[0];
            wife_time[1] = hour[1] * 60 + minute[1];

            scanf("%d:%d %d:%d", &hour[0], &minute[0], &hour[1], &minute[1]);
            meeting_time[0] = hour[0] * 60 + minute[0];
            meeting_time[1] = hour[1] * 60 + minute[1];

            if(wife_time[0] > meeting_time[1] || wife_time[1] < meeting_time[0])
                printf("Case %d: Hits Meeting\n", i);
            else
                printf("Case %d: Mrs Meeting\n", i);
        }
    }

    return 0;
}
