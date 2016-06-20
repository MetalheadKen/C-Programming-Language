#include <stdio.h>

int main(int argc, char *argv[]) {
	int i, j, t, n, location; //t為測資數量，n為指令數量
	char command[20], instruction[101]; //command為當前指令，instruction為記錄指令 
	
	fflush(stdin);
	scanf("%d", &t);
	
	if(t > 100) return 1;
	while(t--)
	{
		scanf("%d", &n);
		
		if(n < 1 || n > 100) return 1;
		
		location = 0;
		for(i = 0; i < n; i++)
		{
			fflush(stdin);
			gets(command);
			
			if(command[0] == 'L')
			{
				instruction[i] = -1;
				location--;
			}
			else if(command[0] == 'R')
			{
				instruction[i] = 1;
				location++;
			}
			else
			{
				sscanf(command + 8, "%d", &j);
				instruction[i] = instruction[j - 1];
				location += instruction[i];
			}
		}
		
		printf("%d\n", location);
	}
	
	return 0;
}
