#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_row(int **p, int M, int N);
int check_col(int **p, int M, int N);

int main(void)
{
    int M, N, x, y, z, **p = NULL, max = 0;

    scanf("%d %d", &M, &N);
    p = (int **)calloc(M, sizeof(int *));
    for (int i = 0; i < M; i++)
    {
        p[i] = (int *)calloc(N, sizeof(int));
    }

    scanf("%d %d %d", &x, &y, &z);
    while (x != 0 || y != 0 || z != 0)
    {
        p[x][y] = z;
        scanf("%d %d %d", &x, &y, &z);
    }

    if (check_col(p, M, N) > check_row(p, M, N))
    {
        max = check_col(p, M, N);
    }
    else
    {
        max = check_row(p, M, N);
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf(" %d", p[i][j]);
        }
        printf("\n");
    }
    printf("%d", max);

    for (int i = 0; i < M; i++)
    {
        free(p[i]);
    }
    free(p);
    return 0;
}

int check_row(int **p, int M, int N)
{
    int max = 0, cnt = 0;

    for (int i = 0; i < M; i++)
    {
        cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (p[i][j] == 0)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            if (max < cnt)
            {
                max = cnt;
            }
        }
        if (max < cnt)
        {
            max = cnt;
        }
    }

    return max;
}

int check_col(int **p, int M, int N)
{
    int max = 0, cnt = 0;

    for (int j = 0; j < N; j++)
    {
        cnt = 0;
        for (int i = 0; i < M; i++)
        {
            if (p[i][j] == 0)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            if (max < cnt)
            {
                max = cnt;
            }
        }
        if (max < cnt)
        {
            max = cnt;
        }
    }

    return max;
}
