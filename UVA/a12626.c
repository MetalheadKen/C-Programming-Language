#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

int main(int argc, char *argv[]) {
	int i, N, ans; //N���ƤJ����
	
	fflush(stdin);
	scanf("%d", &N);
	
	while(N--)
	{
		//128�]�̤j�r���Q�i�128�A600�]�̦h�u���J600�Ӧr�� 
		char ascii[128] = {0}, string[600] = {0};
	
		scanf("%s", string);
		for(i = 0; i < strlen(string); i++)
			ascii[string[i]]++;
			
		ans = min(ascii['M'] / 1, min(ascii['A'] / 3, min(ascii['R'] / 2, min(ascii['G'] / 1, min(ascii['I'] / 1, ascii['T'] / 1)))));
		
		printf("%d\n", ans);
	}
	
	return 0;
}
