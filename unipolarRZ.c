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

    printf("Unipolar RZ encoded data is:\n");

    for (i = 0; i < n; i++)
    {
        if (b[i] == 1)
            printf("+V 0 ");  // +V for first half, 0 for second half
        else
            printf("0 0 ");   // 0 for entire bit duration
    }

    return 0;
}
