#include <stdio.h>

typedef struct _Date {
    int month;
    int day;
} Date;

/* 2011/01/01 is Saturday */
const int dayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *dayOfWeek[] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

const char *GetDayOfWeek(Date);

int main(int argc, char *argv[])
{
    int times;
    
    fflush(stdin);
    while (~scanf("%d", &times)) {
        while (times--) {
            Date date;
            scanf("%d %d", &date.month, &date.day);
            printf("%s\n", GetDayOfWeek(date));
        }
    }

    return 0;
}

const char *GetDayOfWeek(Date date)
{
    for (int i = 0; i < date.month - 1; i++)
        date.day += dayOfMonth[i];

    return dayOfWeek[date.day % 7];
}
