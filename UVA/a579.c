#include <stdio.h>

int main(int argc, char *argv[])
{
    int hour, minute;
    double hour_degree, minute_degree, difference;

    fflush(stdin);
    while(~scanf("%d:%d", &hour, &minute) && (hour != 0 || minute != 0)) {
        //�p�ɫ׼� = 360�� / 12�� * �p�� +  ���� / 60 * 30 (�]���w�C��60��A�ɰw�N��30��)
        hour_degree = (double)(hour) * 30.0 + (double)(minute) / 60.0 * 30.0;

        //�����׼� = 360�� / 60�� * ����
        minute_degree = (double)(minute) * 6.0;

        difference = (hour_degree > minute_degree) ? (hour_degree - minute_degree) : (minute_degree - hour_degree);

        printf("%.3lf\n", (difference > 180.0) ? 360.0 - difference : difference);
    }

    return 0;
}
