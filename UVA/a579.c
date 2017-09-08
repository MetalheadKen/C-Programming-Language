#include <stdio.h>

int main(int argc, char *argv[])
{
    int hour, minute;
    double hour_degree, minute_degree, difference;

    fflush(stdin);
    while(~scanf("%d:%d", &hour, &minute) && (hour != 0 || minute != 0)) {
        //小時度數 = 360度 / 12格 * 小時 +  分鐘 / 60 * 30 (因分針每走60格，時針就走30度)
        hour_degree = (double)(hour) * 30.0 + (double)(minute) / 60.0 * 30.0;

        //分鐘度數 = 360度 / 60格 * 分鐘
        minute_degree = (double)(minute) * 6.0;

        difference = (hour_degree > minute_degree) ? (hour_degree - minute_degree) : (minute_degree - hour_degree);

        printf("%.3lf\n", (difference > 180.0) ? 360.0 - difference : difference);
    }

    return 0;
}
