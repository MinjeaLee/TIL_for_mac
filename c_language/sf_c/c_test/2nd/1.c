#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input(int *p, int N)
{
    int *pnt;

    for (pnt = p; pnt < p + N; pnt++)
    {
        scanf("%d", pnt);
    }
}

void output(int *p, int K)
{
    int *pnt;
    for (pnt = p; pnt < p + K; pnt++)
    {
        printf(" %d", *pnt);
    }
}

int main()
{
    int n, m, k;
    int x[100], y[100];
    int min, *x_index, *y_index;

    scanf("%d", &m);
    scanf("%d", &n);

    input(x, m);
    input(y, n);

    scanf("%d", &k);

    if (m > n)
    {
        min = n;
    }
    else
    {
        min = m;
    }

    if (min == n)
    {
        x_index = x;
        y_index = y;
        for (int i = 0; i < min / k; i++)
        {
            output(x_index, k);
            x_index += k;
            output(y_index, k);
            y_index += k;
        }
        for (; x_index < x + m; x_index++)
        {
            printf(" %d", *x_index);
        }
    }
    else
    {
        x_index = x;
        y_index = y;
        for (int i = 0; i < min / k; i++)
        {
            output(x_index, k);
            x_index += k;
            output(y_index, k);
            y_index += k;
        }
        for (; y_index < y + n; y_index++)
        {
            printf(" %d", *y_index);
        }
    }

    return 0;
}