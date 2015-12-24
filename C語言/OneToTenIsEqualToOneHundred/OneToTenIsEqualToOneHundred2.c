#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char OPER[] = {'+', '-', '*', '/'};
double result[9];
int a, b, c, d, e, f, g, h, i;
size_t count = 0;

double cal(double, double, int);

double cal(double a, double b, int operators) {
	if(operators == 0)
		return (a + b);
	else if(operators == 1)
		return (a - b);
	else if(operators == 2)
		return (a * b);
	else if(operators == 3)
		return (a / b);
}

int main(int argc, char *argv[]) {
	for(a = 0; a < 4; a++)
	{
		//result[0] = calculate(1.0, 2.0, a);
		for(b = 0; b < 4; b++)
		{
			//result[1] = calculate(result[0], 3.0, b);
			for(c = 0; c < 4; c++)
			{
				//result[2] = calculate(result[1], 4.0, c);
				for(d = 0; d < 4; d++)
				{
					//result[3] = calculate(result[2], 5.0, d);
					for(e = 0; e < 4; e++)
					{
						//result[4] = calculate(result[3], 6.0, e);
						for(f = 0; f < 4; f++)
						{
							//result[5] = calculate(result[4], 7.0, f);
							for(g = 0; g < 4; g++)
							{
								//result[6] = calculate(result[6], 8.0, g);
								for(h = 0; h < 4; h++)
								{
									//result[7] = calculate(result[6], 9.0, h);
									for(i = 0; i < 4; i++)
									{
										result[8] = cal(cal(cal(cal(cal(cal(cal(cal(cal(1.0, 2.0, a), 3.0, b), 4.0, c), 5.0, d), 6.0, e), 7.0, f), 8.0, g), 9.0, h), 10.0, i);
										
										if(result[8] == 100.0)
										{	
											printf("1 %c 2 %c 3 %c 4 %c 5 %c 6 %c 7 %c 8 %c 9 %c 10 = 100\n", OPER[a], OPER[b],	OPER[c], OPER[d], OPER[e], OPER[f], OPER[g], OPER[h], OPER[i]);
											count++;
										}
									}	 
								}
							}
						}
						
					}
				}
			}
		}
	}
	
	printf("%d", count);
	
	return 0;
}
