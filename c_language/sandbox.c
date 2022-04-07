#include <stdio.h>
#include <string.h>

int main(void)
{
    char names[200] = {
        0,
    };
    char array[50][21] = {
        0,
    };

    int i, j;
    int flag = 0;
    int names_len;

    int idx = 0;
    int k = 0;

    fgets(names, 200, stdin);

    names_len = strlen(names);
    names[names_len - 1] = '\0';

    for (i = 0; i < names_len; i++)
    {
        if (names[i] == '"')
        {
            flag++;
        }
        if (flag % 2 == 0 && names[i] == ' ')
        {
            names[i] = '\0';
        }
    }

    while (idx < names_len)
    {
        if (*(names + idx) == '"')
        {
            idx++;
        }
        strcpy(array[k++], names + idx);
        idx += strlen(names + idx) + 1;
    }

    char tmp[21];
    for (i = 0; i < k - 1; i++)
    {
        for (j = i; j < k; j++)
        {
            if (strcmp(array[i], array[j]) > 0)
            {
                strcpy(tmp, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], tmp);
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < strlen(array[i]); j++)
        {
            if (array[i][j] == '"')
                continue;
            printf("%c", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}