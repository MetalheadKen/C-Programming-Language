#include <stdio.h>

int main(int argc, char *argv[]) {
	int hour1, minute1, hour2, minute2, minute;
	
	fflush(stdin);
	while(~scanf("%d %d %d %d", &hour1, &minute1, &hour2, &minute2))
	{
		if(hour1 == 0 && minute1 == 0 && hour2 == 0 && minute2 == 0)
			return 0;
			
		minute = (hour2 - hour1) * 60 + minute2 - minute1;
		
		//若minute為負數代表鬧鐘相隔了一天 
		if(minute < 0)
			minute += 24 * 60;
			
		printf("%d\n", minute);
	}
	
	return 0;
}
