#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//t�����ꪺ�ƶq�Alength����J�����סAwidth����J���e�סAheigth����J������ 
	int i, t, length, width, height;
	
	fflush(stdin);
	while(scanf("%d", &t) != EOF)
	{
		if(t > 100) exit(1);
		
		for(i = 1; i <= t; i++)
		{
			scanf("%d %d %d", &length, &width, &height);
			
			if(length < 1 || height > 50) 
			{
				printf("Case %d: bad\n", i);
				continue;
			}
			
			if(length <= 20 && width <= 20 && height <= 20)
				printf("Case %d: good\n", i);
			else
				printf("Case %d: bad\n", i);			
		}		
	}
		
	return 0;
}
