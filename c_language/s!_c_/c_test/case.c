#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int check[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            check[i][j] = 1;
        }
    }
    int cnt = 0;
    while (1)
    {
        char a[100005] = {};
        int check_idx = -1;
        int si[3] = {-1, 0, 1};
        int sj[3] = {-1, 0, 1};
        scanf("%[^\n]s", a);
        getchar();
        if (!strcmp("0", a))
        {
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] == ' ')
            {
                cnt++;
                check_idx = i;
            }
        }
        if (cnt == 1 && a[0] != ' ' && a[strlen(a) - 1] != ' ')
        {
            int X = atoi(a);
            int Y = atoi(&a[check_idx + 1]);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (i == 1 && j == 1)
                        continue;
                    if (X + si[i] >= 0 && X + si[i] < 10 && Y + sj[j] >= 0 && Y + sj[j] < 10)
                    {
                        check[X + si[i]][Y + sj[j]] *= -1;
                    }
                }
            }
            if (!cnt)
                puts("");
            puts(" ");
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    printf("%c ", check[i][j] == 1 ? 'O' : '#');
                }
                printf("\n");
            }
            printf(" ");
        }
        else
        {
            if (!cnt)
                puts("");
            puts(" ");
            puts("ERROR");
            printf(" ");
        }
        cnt++;
    }
}