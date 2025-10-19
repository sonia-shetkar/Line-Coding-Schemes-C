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
        scanf("%d", &b[i]);

    printf("Differential Manchester encoded data is:\n");

    for (i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            // 0 → Transition at start
            last = !last;  // toggle polarity at start
        }
        // Print first half (start of bit)
        if (last == 1)
            printf("+V ");
        else
            printf("-V ");

        // Mid-bit transition always happens
        last = !last;  // toggle polarity for mid-bit
        if (last == 1)
            printf("+V ");
        else
            printf("-V ");
    }

    printf("\n");
    return 0;
}

