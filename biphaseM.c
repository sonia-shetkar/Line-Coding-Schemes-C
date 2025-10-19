#include <stdio.h>

int main()
{
    int n, i;
    int b[100];
    int last = 1; // Start with +V (1 = +V, 0 = -V)

    printf("Enter the number of bits:\n");
    scanf("%d", &n);

    printf("Enter the bits (0s and 1s):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("Biphase Mark encoded data is:\n");

    for (i = 0; i < n; i++)
    {
        // Always transition at start
        last = !last;

        if (last == 1)
            printf("+V ");
        else
            printf("-V ");

        if (b[i] == 1)
        {
            // Mid-bit transition for '1'
            last = !last;
        }

        if (last == 1)
            printf("+V ");
        else
            printf("-V ");
    }

    return 0;
}

