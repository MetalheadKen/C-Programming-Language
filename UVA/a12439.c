#include <stdio.h>
#include <stdlib.h>

const char Month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//���q�ѡG����C�Ӧr��A�^�ǸӤ���ƭ�
//�t�ѡG�]�u�ݧP�_�O�_�p��G��A�G��r�굥��"J"�B����"a" || ����"F"�B����p��29��ɦ~����1 
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
	//t���X������Aday������Ayear���~���Aans���X�Ӷ|�� 
	int i, t, day1, year1, day2, year2, ans;
	char month1[10], month2[10]; //month����� 
	
	fflush(stdin);
	while(scanf("%d", &t) != EOF)
	{
		if(t > 500) exit(1);
		
		for(i = 1; i <= t; i++)
		{
			//�i��J���N���P�_�A����ܼ� 
			scanf("%s %d, %d", month1, &day1, &year1);
			scanf("%s %d, %d", month2, &day2, &year2);
			
			//�p�G�����p��2��Ω�2��ɤ���p��29�骺�ܡA�Ӧ~������ 
			if(getmonth(month1) < 3) --year1; //�]��u�����v���h�ֶ|��A�G�����P�_ 
			if(getmonth(month2) < 2 || (getmonth(month2) == 2 && day2 < 29)) --year2;
			
			//�N�ĤG�Ӥ���e�o�͹L���|�~�ơA�A��h�Ĥ@�Ӥ���ҵo�ͼơA�Y����Ӥ�������o�͹L���|��� 
			ans = (year2 / 4 - year2 / 100 + year2 / 400) - (year1 / 4 - year1 / 100 + year1 / 400);
			
			printf("Case %d: %d\n", i, ans);
		}
	}
	
	return 0;
}
