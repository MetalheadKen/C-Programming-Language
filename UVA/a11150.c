#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//battle���ثe���X�~�i�H�ܡAempty���ثe���Ų~�ơAhave���ثe�ܤF�h�ֲ~ 
	int battle, empty, have;
	
	fflush(stdin);
	while(~scanf("%d", &battle))
	{
		if(battle < 1 || battle > 200) exit(1);
		
		empty = have = 0;
		while(battle)
		{
			empty += battle; //�ܱ��᪺�Ѿl�`�Ų~�� 
			have += battle; //�����ܤF�h�ֲ~ 
			battle = empty / 3; //�C 3 �ӪŲ~���@�~Cola 
			empty %= 3; //������Ѧh�֪Ų~						
		}
		
		//�p�G�٦� 2 �~�Ų~�A�N�i�H��O�H�� 1 �~�����B�ܧ����ٵ��L�H 
		if(empty == 2)
			printf("%d\n", have + 1);
		else
			printf("%d\n", have);
	}
		
	return 0;
}
