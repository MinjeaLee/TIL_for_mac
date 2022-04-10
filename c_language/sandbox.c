#include <stdio.h>
int main()
{
    int a, b, c, n, i, k, m = 0, n1;

    scanf_s("%d", &n);

    for (i = 1; i < n + 1; i++)
    {
        printf(" ");
    }

    n1 = (n * n) % 9;

    while (n1 <= 0)
    {
        n1 = n1 + 9;
    }
    while (n1 >= 10)
    {
        n1 = n1 - 9;
    }

    printf("%d\n", n1);

    for (a = 1; a < n; a++)
    {
        m += (a * 2 + 1);

        for (b = a; b < n; b++)
        {
            printf(" ");
        }
        k = (((n * n) % 9) - m);
        for (c = 0; c <= (a * 2); c++)
        {

            while (k <= 0)
            {
                k = k + 9;
            }
            while (k >= 10)
            {
                k = k - 9;
            }

            printf("%d", k);
            k++;
        }
        printf("\n");
    }
}