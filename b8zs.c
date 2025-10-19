#include <stdio.h>

int main()
{
    int n, i, zeroCount = 0;
    int b[200];
    int last = -1; // Last polarity (+1 = +V, -1 = -V)

    printf("Enter the number of bits:\n");
    scanf("%d", &n);

    printf("Enter the bits (0s and 1s):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("B8ZS encoded data is:\n");

    for (i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            last = -last; // Alternate polarity for '1'
            printf("%s ", (last == 1) ? "+V" : "-V");
            zeroCount = 0; // Reset consecutive zeros
        }
        else
        {
            zeroCount++;

            if (zeroCount == 8)
            {
                // Apply B8ZS substitution
                int sub[8];
                if (last == 1)  // Last 1 was +V
                    sub[0]=0, sub[1]=0, sub[2]=0, sub[3]=1, sub[4]=-1, sub[5]=0, sub[6]=-1, sub[7]=1;
                else             // Last 1 was -V
                    sub[0]=0, sub[1]=0, sub[2]=0, sub[3]=-1, sub[4]=1, sub[5]=0, sub[6]=1, sub[7]=-1;

                for (int j = 0; j < 8; j++)
                {
                    if (sub[j] == 1) printf("+V ");
                    else if (sub[j] == -1) printf("-V ");
                    else printf("0 ");
                }

                // Update last polarity to last non-zero in substitution
                for (int j = 7; j >= 0; j--)
                    if (sub[j] != 0) { last = sub[j]; break; }

                zeroCount = 0; // reset zero counter
            }
            else
            {
                // Print zeros immediately if not part of B8ZS
                printf("0 ");
            }
        }
    }

    printf("\n");
    return 0;
}

