#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    long  long n; //n���Y�C�|��n�ӼƦr

    fflush(stdin);
    while(scanf("%lld", &n) != EOF) {
        if(n <= 1 || n >= 1000000000)
            return 1;

        long long row = 0, final = 0;

        //���`�@���h�ּƦr
        for(i = 1; i <= n; i += 2)
            row += i;

        //��̫�@�ӼƦr���h��
        final = row * 2 - 1;

        //final + final - 2 + final - 4
        printf("%d\n", final * 3 - 6);
    }


    return 0;
}
