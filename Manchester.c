#include <stdio.h>

int main()
{
    int n, i;
    int b[100];

    printf("Enter the number of bits:\n");
    scanf("%d", &n);

    printf("Enter the bits (0s and 1s):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("Manchester encoded data:\n");

    for (i = 0; i < n; i++)
    {
        if (b[i] == 0)  // 0 → Low-to-High
            printf("-V +V ");
        else            // 1 → High-to-Low
            printf("+V -V ");
    }

    printf("\n");
    return 0;
}

