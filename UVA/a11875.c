#include <stdio.h>

#define TIME 15

int main(int argc, char *argv[]) {
	int i, j, t, n, number[TIME]; //t������ƶq�An�������N�n��J�h�֭Ӽ�
	
	fflush(stdin);
	scanf("%d", &t);
	
	for(i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		for(j = 0; j < n; j++)
			scanf("%d", &number[j]);
			
		printf("Case %d: %d\n", i, number[n / 2]); //�]�D�بƥ��ƧǹL�A�T�i������X���G 
	}
	
	return 0;
}
