#include <stdio.h>

int main(int argc, char *argv[]) {
	short i, t, a, b; //t����J���ơA�d��a~b 
	int sum; //sum���`�M 
	
	fflush(stdin);
	scanf("%hd", &t);
	if(t < 0 || t > 100) return 1;
	
	for(i = 1; i <= t; i++)
	{
		scanf("%hd", &a); scanf("%hd", &b);
		if(a < 0 || a > 100 || b < 0 || b > 100 || a > b) return 1;
		
		if(!(a & 1)) a++; //a���̤p�_�� 
		if(!(b & 1)) b--; //b���̤j�_��
		
		for(sum = 0; a <= b; a += 2)
			sum += a;
		
		printf("Case %hd:%d\n", i, sum);
		
		//�t��
		//�W�� + �U�� * �� / 2 OR ��N�ө_�ƪ�N ^ 2
		//(a + b) * ((b - a) / 2 + 1) / 2 => (a + b) * (b - a + 2) / 4
		//printf("Case %hd:%d\n", i, ((a + b) * (b - a + 2)) / 4);
	}
	
	return 0;
}
