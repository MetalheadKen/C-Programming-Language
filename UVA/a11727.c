#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, T, a, b, c; //T為輸入次數 
	
	fflush(stdin);
	scanf("%d", &T);
	
	if(T >= 20)
		return 0;
		
	for(i = 1; i <= T; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		
		if((1000 >= a && a >= 10000) || (1000 >= b && b >= 10000) || (1000 >= c && c >= 10000))
			return 0;
			
		if((a < b && b < c && a < c) || (c < b && b < a && c < a))
			printf("Case %d: %d\n", i, b);
		if((a < c && c < b && a < b) || (b < c && c < a && b < a))
			printf("Case %d: %d\n", i, c);
		if((b < a && a < c && b < c) || (c < a && a < b && c < b))
			printf("Case %d: %d\n", i, a);		
	}
	
	return 0;
}
