#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

int main(int argc, char *argv[]) {
	int i, a, b; //a�O�ڲ{�b�ݪ��W�D�A��b�h�O�ڷQ�n�������W�D
	
	fflush(stdin);
	
	for(i = 0; i < 200; i++)
	{
		scanf("%d %d", &a, &b);
	
		if(a == -1 && b == -1)
			return 0;
		else
		{
			if(abs(a - b) > 50)
				printf("%d\n", min(100 - a, 100 - b));
			else
				printf("%d\n", abs(a - b));
		}
	}
	
	return 0;
}
