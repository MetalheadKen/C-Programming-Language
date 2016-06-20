#include <stdio.h>

#define LENGTH 1000000 

int main(int argc, char *argv[]) {
	int i, max, count, remove;
	char string[LENGTH];
	
	fflush(stdin);
	while(gets(string) != NULL)
	{
		max = count = remove = 0;
		for(i = 0; string[i]; i++)
		{
			if(string[i] == ' ')
				count++;
			else
			{
				max = max < count ? count : max;
				count = 0;
			}
		}
		
		while(max != 1)
		{
			max = max / 2 + max % 2;
			remove++;
		}
		
		printf("%d\n", remove);
	}
	
	return 0;
}
