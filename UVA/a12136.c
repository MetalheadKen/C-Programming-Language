#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //n�����ꪺ�ƶq�Awife_time��Danny�������d�l���ɶ��b���Ѫ��ĴX�����Ameeting_time��Danny�ѥ[�|ĳ���ɶ��b���Ѫ��ĴX����
    //hour[0]�Pminute[0]��hour[1]�Pminute[1]��Danny�������d�l���ɶ��Ahour[0]�Pminute[0]��hour[1]�Pminute[1]��Danny�ѥ[�|ĳ���ɶ�
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
