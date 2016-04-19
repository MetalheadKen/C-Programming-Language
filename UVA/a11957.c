#include <stdio.h>
#include <stdlib.h>

int n; //n為方格大小 
char **board;
char *board_y;

void findship(int i, int j) {
	//邊界判斷 
	if(i < 0 || i >= n || j < 0 || j >= n) return;
	//有無船隻
	if(board[i][j] == '.') return;
	board[i][j] = '.';
	
	findship(i - 1, j);
	findship(i + 1, j);
	findship(i, j - 1);
	findship(i, j + 1);	
}

int main(int argc, char *argv[]) {
	//t為測資筆數，n為方格大小，count為船隻數量 
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
