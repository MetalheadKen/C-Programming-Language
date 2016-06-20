#include <stdio.h>

int main(int argc, char *argv[]) {
	int i, t; //t為測資數量 
	float degree, fahrenheit, celsius;
	
	fflush(stdin);
	scanf("%d", &t);
	
	for(i = 1; i <= t; i++)
	{
		scanf("%f %f", &celsius, &degree);
		
		fahrenheit = (9 * celsius) / 5 + 32;
		fahrenheit += degree;
		celsius = (fahrenheit - 32) * 5 / 9;
		
		printf("Case %d: %.2f\n", i, celsius);
	} 
	
	return 0;
}
