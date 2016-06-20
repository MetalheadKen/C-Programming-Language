#include <stdio.h>

#define TRUE  1
#define FALSE 0

int Prime(int);
int FermatTest(int);
unsigned int PowerMod(int ,int ,int);

int main(int argc, char *argv[]) {
	int number;
	
	fflush(stdin);
	while(~scanf("%d", &number) && number != 0)
	{
		if(number <= 2 || number >= 65000)
			return 0;
		else
		{
			if(!Prime(number) && FermatTest(number))
				printf("The number %d is a Carmichael number.\n", number);
			else
				printf("%d is normal.\n", number);
		}
	}
	
	return 0;
}

//��ƧP�_
int Prime(int num) {
	int i;
	
	for(i = 2; i * i < num; i++)
	{
		if(!(num % i))
			return FALSE;		
	}
	
	return TRUE;
}

//�O�����աG�Y a ^ n mod n = a �h�i�ର��Ʃ�Carmichael Number
int FermatTest(int num) {
	int i;
	
	for(i = 2; i < num; i++)
	{
		if(PowerMod(i, num, num) != i)
			return FALSE;		
	}
	
	return TRUE;
}

//��@ a ^ n mod n ��> a ^ 2 mod n = a * a mod n = (a mod n) * (a mod n) ����@�����U�� 
unsigned int PowerMod(int a, int num, int mod) {
	unsigned int temp;	
	
	if(num == 0)
		return 1;
	
	if(num == 1)
		return a % mod;
		
	temp = PowerMod(a, num / 2, mod);
	temp = temp * temp % mod;
	
	if(!(num & 1))	
		return temp;
	else
		return a * temp % mod;	
}
