#include <stdio.h>
#include <stdlib.h>

const int MONTH_DAY[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *WEEK[10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"} ;

#define DAYS 5

//�̽d�ұo��2011/1/1�b�P���� 
int main(int argc, char *argv[]) {
	//t�����굧�ơAmonth������Aday����� 
	int i, t, month, day;
	
	fflush(stdin);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &month, &day);
		
		//�p���`�@�L�F�h�֤� 
		for(i = 1; i < month; i++)
			day += MONTH_DAY[i];
		
		day += DAYS; //�q�P�����}�l��	
		day %= 7; //�p��{�b�P���X 
		
		puts(WEEK[day]);
	}
	
	return 0;
}
