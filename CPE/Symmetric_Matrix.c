#include <stdio.h>

typedef long long int int64;

char *IsSymmetric(int64 *, int);

int main(int argc, char *argv[])
{
    int times, dimension;

    fflush(stdin);
    while (~scanf("%d", &times)) {
        for (int i = 1; i <= times; i++) {
            scanf("\nN = %d", &dimension);

            int length = dimension * dimension;
            int64 matrix[length];

            for (int i = 0; i < length; i++)
                scanf("%lld", &matrix[i]);

            printf("Test #%d: %s\n", i, IsSymmetric(matrix, length));
        }
    }

    return 0;
}

char *IsSymmetric(int64 *matrix, int length)
{
    for (int i = 0; i < length / 2; i++) {
        if (matrix[i] !=  matrix[length - i - 1] || matrix[i] < 0)
            return "Non-symmetric.";
    }
    
    return "Symmetric.";
}
