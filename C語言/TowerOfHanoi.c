/*
 ============================================================================
 Name        : TowerOfHanoi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void Hanoi(int, char, char, char);

//如果柱子標為ABC，要由A搬至C，在只有一個盤子時，就將它直接搬至C，當有兩個盤子，就將B當作輔助柱
//Hanoi(圓環數量, 來源柱, 暫存柱, 目的柱)
void Hanoi(int n, char A, char B, char C) {
	//由於遞迴關係，若只宣告int count = 0 將會一直重設為零
	//count 只有第一次會初始化成0
	static int count = 0;

	if(n == 1)
	{
		count++;
		//把圓環從來源柱搬到目的柱 (A －> C)，次數只有一次
		printf("第%d步：移動%d從塔%c到塔%c\n", count, 1, A, C);
	}
	else
	{
		//Hanoi(圓環數量, 來源柱欄, 暫存柱欄, 目的柱欄)
		//Hanoi(n - 1, 來源柱, 目的柱, 暫存柱)
		Hanoi(n - 1, A, C, B); //把第n - 1個圓環從來源柱搬到暫存柱 (A －> B)
		count++;
		//列印，並且把第n個圓環從來源柱搬到目的柱
		//Hanoi(1, A, B, C);
		printf("第%d步：移動%d從塔%c到塔%c\n", count, n, A, C);
		//Hanoi(n - 1, 暫存柱, 來源柱, 目的柱)
		Hanoi(n - 1, B, A, C); //把第n - 1個圓環從暫存柱搬到目的柱 (B －> C)
	}
}

/*Hannoi Function在遞迴中將副程式再展開兩個小的子副程式，
 所以若輸入3個圓環，其移動次數將為2^3-1，若輸入n個圓環，其移動次數將為2^n-1*/

int main(void) {
	int n;

	printf("請輸入第一根柱子上有幾個圓環：");
	fflush(stdin);
	scanf("%d", &n);

	Hanoi(n, 'a', 'b', 'c');

	return EXIT_SUCCESS;
}
