#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int N, i, j, k, len_X = 0, len = 0, chk = 0, cnt = 0, max = 0;
    char X[101] = {'\0'}, **Y = NULL, tmp[101] = {'\0'}, result[101] = {'\0'};

    scanf("%d %s", &N, X);
    len_X = strlen(X);
    Y = (char **)malloc(N * sizeof(char *));
    if (Y == NULL)
    {
        printf("Not enough memory!");
        return -1;
    }

    getchar();
    for (i = 0; i < N; i++)
    {
        gets(tmp);
        len = strlen(tmp);
        Y[i] = (char *)malloc((len + 1) * sizeof(char));
        strcpy(Y[i], tmp);

        for (j = 0; j < len; j++)
        {
            tmp[j] = NULL;
        }

        cnt = 0;
        for (j = 0; j < len; j++)
        {
            if (X[0] == Y[i][j])
            {
                chk = 0;
                for (k = 0; k < len_X; k++, j++)
                {
                    if (X[k] == Y[i][j])
                    {
                        chk++;
                    }
                    else
                    {
                        break;
                    }
                }

                if (chk == len_X)
                {
                    cnt++;
                    j--;
                }
            }
        }

        if (max < cnt)
        {
            strcpy(result, Y[i]);
            max = cnt;
        }
    }

    if (max == 0)
    {
        printf("NONE");
    }
    else
    {
        puts(result);
    }

    for (i = 0; i < N; i++)
    {
        free(Y[i]);
    }
    free(Y);
    return 0;
}