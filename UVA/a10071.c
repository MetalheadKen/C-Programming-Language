#include <stdio.h>

int main(int argc, char *argv[])
{
    int v, t; //v���t�סAt���ɶ�

    fflush(stdin);
    while(~scanf("%d %d", &v, &t))
        printf("%d\n", 2 * v * t); //�첾 = �����t�� * �ɶ�

    return 0;
}
