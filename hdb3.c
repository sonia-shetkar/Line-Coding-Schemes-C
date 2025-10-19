#include <stdio.h>

int main()
{
    int n, i, zeroCount = 0, oneCount = 0;
    int b[200];
    int last = -1; // Last polarity (+1 = +V, -1 = -V)

    printf("Enter the number of bits:\n");
    scanf("%d", &n);

    printf("Enter the bits (0s and 1s):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("HDB3 encoded data is:\n");

    for (i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            last = -last; // Alternate polarity
            printf("%s ", (last == 1) ? "+V" : "-V");
            oneCount++;
            zeroCount = 0; // reset zeros
        }
        else
        {
            zeroCount++;

            if (zeroCount == 4)
            {
                if (oneCount % 2 == 0)
                {
                    // Even → B00V
                    int B = last;      // B same polarity as last 1
                    int V = -last;     // V opposite polarity
                    printf("%s 0 0 %s ", (B==1)?"+V":"-V", (V==1)?"+V":"-V");
                    last = V;          // Update last polarity
                }
                else
                {
                    // Odd → 000V
                    int V = -last;     // V opposite polarity
                    printf("0 0 0 %s ", (V==1)?"+V":"-V");
                    last = V;          // Update last polarity
                }

                zeroCount = 0; // Reset zero counter
                oneCount = 0;  // Reset one counter
            }
            else
            {
                printf("0 "); // Print zeros <4
            }
        }
    }

    printf("\n");
    return 0;
}




