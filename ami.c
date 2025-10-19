#include <stdio.h>

int main()
{
    int n, i;
    int b[100];
    int last = -1; // To track polarity of last '1' (+1 = +V, -1 = -V)

    printf("Enter the number of bits:\n");
    scanf("%d", &n);

    printf("Enter the bits (0s and 1s):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("AMI encoded data is:\n");

    for (i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            printf("0 ");   // Zero → No signal
        }
        else
        {
            // Alternate polarity for '1'
            last = -last;
            if (last == 1)
                printf("+V ");
            else
                printf("-V ");
        }
    }

    return 0;
}
