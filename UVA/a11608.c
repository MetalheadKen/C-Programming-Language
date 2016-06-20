#include <stdio.h>

#define MONTH 12

int main(int argc, char *argv[]) {
	int i, problem, case_number = 1, make[MONTH] = {0}, need[MONTH] = {0}, answer;
	
	fflush(stdin);
	while(~scanf("%d", &problem) && problem > 0)
	{
		for(i = 0; i < MONTH; i++)
			scanf("%d", &make[i]);
			
		for(i = 0; i < MONTH; i++)
			scanf("%d", &need[i]);
						
		answer = problem;
		
		printf("Case %d:\n", case_number++);
		for(i = 0; i < MONTH; i++)
		{
			if(answer> need[i])
			{
				answer -= need[i];
				printf("No problem! :D\n");
			}
			else
				printf("No problem. :(\n");
				
			answer += make[i];
		}		
	}
	
	return 0;
}
