/*
 ============================================================================
 Name        : MoneyChange.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int money, m50 = 0, m20 = 0, m10 = 0;
    int *coin = &money;

    printf("�п�J�Q�I�������B�G");
    scanf("%d", &money);

    if(money == 50) {
        m20 = *coin / 20;
        money %= 20;
        m10 = money / 10;
    } else if(money == 20) {
        m10 = money / 10;
    } else {
        m50 = *coin / 50;
        if(m50 > 100) {
            money = (money % 50) + (m50 - 100) * 50;
            m50 = 100;
        }

        m20 = *coin / 20;
        if(m20 > 100) {
            money = (money % 20) + (m20 - 100) * 20;
            m20 = 100;
        }

        m10 = money / 10;
        if(m10 > 500) {
            money = (money % 10) + (m50 - 500) * 10;
            m10 = 500;
        }
    }

    printf("�I�������G\n 50���G%d��\n 20���G%d��\n 10���G%d��\n", m50, m20, m10);

    return EXIT_SUCCESS;
}
