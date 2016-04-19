#include <stdio.h>
#include <stdlib.h>

const char Month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//普通解：比較每個字串，回傳該月份數值
//速解：因只需判斷是否小於二月，故當字串等於"J"且等於"a" || 等於"F"且日期小於29日時年份減1 
int getmonth(char *month) {
	int i, j, count;
	
	for(i = 0; i < 12; i++)
	{
		for(j = 0, count = 0; Month[i][j] != '\0'; j++)
		{
			if(month[j] != Month[i][j])
				count++;
		}
		
		if(!count) return (i + 1);
	}
}

int main(int argc, char *argv[]) {
	//t為幾筆測資，day為日期，year為年份，ans為幾個閏日 
	int i, t, day1, year1, day2, year2, ans;
	char month1[10], month2[10]; //month為月份 
	
	fflush(stdin);
	while(scanf("%d", &t) != EOF)
	{
		if(t > 500) exit(1);
		
		for(i = 1; i <= t; i++)
		{
			//可輸入完就做判斷，減少變數 
			scanf("%s %d, %d", month1, &day1, &year1);
			scanf("%s %d, %d", month2, &day2, &year2);
			
			//如果當月份小於2月或於2月時日期小於29日的話，該年份不算 
			if(getmonth(month1) < 3) --year1; //因算「之間」有多少閏日，故不做判斷 
			if(getmonth(month2) < 2 || (getmonth(month2) == 2 && day2 < 29)) --year2;
			
			//將第二個日期前發生過的閏年數，再減去第一個日期所發生數，即為兩個日期之間發生過的閏日數 
			ans = (year2 / 4 - year2 / 100 + year2 / 400) - (year1 / 4 - year1 / 100 + year1 / 400);
			
			printf("Case %d: %d\n", i, ans);
		}
	}
	
	return 0;
}
