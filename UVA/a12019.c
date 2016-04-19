#include <stdio.h>
#include <stdlib.h>

const int MONTH_DAY[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *WEEK[10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"} ;

#define DAYS 5

//依範例得知2011/1/1在星期六 
int main(int argc, char *argv[]) {
	//t為測資筆數，month為月份，day為日期 
	int i, t, month, day;
	
	fflush(stdin);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &month, &day);
		
		//計算總共過了多少天 
		for(i = 1; i < month; i++)
			day += MONTH_DAY[i];
		
		day += DAYS; //從星期六開始算	
		day %= 7; //計算現在星期幾 
		
		puts(WEEK[day]);
	}
	
	return 0;
}
