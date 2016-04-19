#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//battle為目前有幾瓶可以喝，empty為目前的空瓶數，have為目前喝了多少瓶 
	int battle, empty, have;
	
	fflush(stdin);
	while(~scanf("%d", &battle))
	{
		if(battle < 1 || battle > 200) exit(1);
		
		empty = have = 0;
		while(battle)
		{
			empty += battle; //喝掉後的剩餘總空瓶數 
			have += battle; //紀錄喝了多少瓶 
			battle = empty / 3; //每 3 個空瓶換一瓶Cola 
			empty %= 3; //換完後剩多少空瓶						
		}
		
		//如果還有 2 瓶空瓶，就可以跟別人借 1 瓶換完且喝完後還給他人 
		if(empty == 2)
			printf("%d\n", have + 1);
		else
			printf("%d\n", have);
	}
		
	return 0;
}
