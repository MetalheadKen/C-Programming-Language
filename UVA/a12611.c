#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //t������ƶq�Ar���ꪺ�b�|�Alength������Ϊ����Awidth������Ϊ��e�Aright���k�u�q�Aleft�����u�q
    int i, t, r, length, width, right, left;

    fflush(stdin);
    scanf("%d", &t);

    for(i = 1; i <= t; i++) {
        scanf("%d", &r);

        length 	= r * 5;
        width 	= length * 60 / 100;
        right 	= length * 55 / 100;
        left 	= length * 45 / 100;

        //�L�X���W�B�k�W�B�k�U�B���U�y��
        printf("Case%d�G\n", i);
        printf("%d %d\n", width / 2, -left);
        printf("%d %d\n", right, width / 2);
        printf("%d %d\n", right, -width / 2);
        printf("%d %d\n", -left, -width / 2);
    }

    return 0;
}
