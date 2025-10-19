#include <stdio.h>

int main()
{
    int n, i;
    int b[100];

    printf("Enter the number of bits:\n");
    scanf("%d", &n);

    printf("Enter the bits (0s and 1s):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("Biphase-S (Manchester) encoded data is:\n");

    for (i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            // '1' → High to Low (+V → -V)
            printf("+V -V ");
        }
        else
        {
            // '0' → Low to High (-V → +V)
            printf("-V +V ");
        }
    }

    return 0;
}

