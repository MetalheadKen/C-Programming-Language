#include <stdio.h>
#include <stdlib.h>

int n; //n�����j�p 
char **board;
char *board_y;

void findship(int i, int j) {
	//��ɧP�_ 
	if(i < 0 || i >= n || j < 0 || j >= n) return;
	//���L�
	if(board[i][j] == '.') return;
	board[i][j] = '.';
	
	findship(i - 1, j);
	findship(i + 1, j);
	findship(i, j - 1);
	findship(i, j + 1);	
}

int main(int argc, char *argv[]) {
	//t�����굧�ơAn�����j�p�Acount����ƶq 
	int i, j, k, t, count;
	
	fflush(stdin);
	while(scanf("%d", &t) != EOF)
	{
		if(t > 100) exit(1);
		for(k = 1; k <= t; k++)
		{
			scanf("%d", &n);
			if(n > 100) exit(1);
			
			//Memory Allocation
			board = (char **)malloc(n * sizeof(*board) + n * n * sizeof(**board));
			board_y = (char *)(board + n);
			for(i = 0; i < n; i++, board_y += n)
					board[i] = board_y;
			
			//Input	
			for(i = 0; i < n; i++)
				scanf("%s", board[i]);
			
			//Find BattleShip
			for(i = 0, count = 0; i < n; i++)
			{
				for(j = 0; j < n; j++)
				{
					if(board[i][j] == 'x')
					{
						count++; 
						findship(i, j);
					}
				}
			}
			
			printf("Case %d: %d\n", k, count);
			free(board);
		}
	}
			
	return 0;
}
