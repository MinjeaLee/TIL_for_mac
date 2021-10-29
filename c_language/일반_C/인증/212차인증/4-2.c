#include <stdio.h>

int main()
{
    int m, x[51], i, avg[51], tmp[5], temp, j,k;
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &x[i]);
    }
    if (m % 2 == 0)
    {
        printf("Invalid Input");
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            avg[i] = x[i];
        }
        for (i = 2; i < m - 2; i++)
        {
            tmp[0] = x[i - 2];
            tmp[1] = x[i - 1];
            tmp[2] = x[i];
            tmp[3] = x[i + 1];
            tmp[4] = x[i + 2];
            for (j = 0; j < 4; j++)
            {
                for (k = j + 1; k < 5; k++)
                {
                    if (tmp[j] < tmp[k])
                    {
                        temp = tmp[j];
                        tmp[j] = tmp[k];
                        tmp[k] = temp;
                    }
                }
            }
            avg[i] = tmp[2];
        }
        for (i = m - 2; i < m; i++)
        {
            avg[i] = x[i];
        }
        for (i = 0; i < m; i++)
        {
            printf(" %d", avg[i]);
        }
    }

    return 0;
}