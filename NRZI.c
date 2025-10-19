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

    printf("Encoded data is:\n");

    for (i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            // Toggle when bit is 0
            last = !last;
        }

        // Print same level twice (representing one bit period)
        if (last == 1)
            printf("+V +V ");
        else
            printf("-V -V ");
    }

    printf("\n");
    return 0;
}

