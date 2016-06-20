#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, decimal, hexadecimal, binary1, binary2; //n為測資數量
	char number[5];
	
	fflush(stdin);
	scanf("%d", &n);
	
	if(n <= 0 || n > 1000)	return 1;		
	while(n--)
	{
		scanf("%s", number);
		
		sscanf(number, "%d", &decimal);
		sscanf(number, "%x", &hexadecimal);
		
		binary1 = binary2 = 0;
		while(decimal)
		{
			if(decimal & 1)
				binary1++;
			
			decimal >>= 1;
		}
		
		while(hexadecimal)
		{
			if(hexadecimal & 1)
				binary2++;
				
			hexadecimal >>= 1;
		}
		
		printf("%d %d\n", binary1, binary2);
	}
	
	return 0;
}
