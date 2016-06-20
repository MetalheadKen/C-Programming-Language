#include <stdio.h>

#define MAX 1000

int main(int argc, char *argv[]) {
	int i, replace, length, flag;
	long long number;
	
	fflush(stdin);
	while(~scanf("%d %lld", &replace, &number) && (replace != 0 || number != 0))
	{
		int value[MAX] = {0};
		
		length = flag = 0;
		for(i = 0; number; i++)
		{
			value[i] = number % 10;
			number /= 10;
			length++;			
		}
		
		for(i = length - 1; i >= 0; i--)
		{			
			if((value[i] != replace) && (value[i] != 0))
			{
				printf("%d", value[i]);
				flag++;
			}
		}
		
		if(!flag)
			putchar('0');
		
		putchar('\n');
	}
	
	return 0;
}
