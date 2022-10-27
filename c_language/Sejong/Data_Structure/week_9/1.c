#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main()
{
    int N;

    int index = 0;
    scanf("%d", &N);

    char *stack = (char *)malloc(sizeof(char) * N);
    int cnt;
    scanf("%d", &cnt);
    getchar();
    for (int i = 0; i < cnt; i++)
    {
        char arr[15];
        gets(arr);
        int len = strlen(arr);
        char second = 0;
        for (int j = 0; j < len; j++)
        {
            if (arr[j] == ' ')
            {
                arr[j] = ' ';
                arr[j] = '\0';
                second = arr[j + 1];
            }
        }
        char first[6];
        strcpy(first, arr);
        // printf("%s\n", first);
        if (strcmp(first, "PUSH") == 0)
        {
            if (N == index)
            {
                printf("Stack FULL\n");
            }
            else
            {
                if (index == 0)
                {
                    stack[0] = second;
                    index++;
                }
                else
                {
                    for (int j = 0; j < index; j++)
                    {
                        stack[index - j] = stack[index - 1 - j];
                    }
                    stack[0] = second;
                    index++;
                }
            }
        }
        else if (strcmp(first, "POP") == 0)
        {
            if (index == 0)
            {
                printf("Stack Empty\n");
            }
            else
            {
                index--;
                for (int j = 0; j < index; j++)
                {
                    stack[j] = stack[j + 1];
                }
            }
        }
        else if (strcmp(first, "PRINT") == 0)
        {
            for (int j = 0; j < index; j++)
            {
                printf("%c", stack[j]);
            }
            printf("\n");
        }
        else if (strcmp(first, "DownR") == 0)
        {
            if (second - '0' <= index)
            {
                char tmp = stack[second - '0' - 1];
                for (int j = 0; j < second - '0' - 1; j++)
                {
                    stack[second - '0' - 1 - j] = stack[second - '0' - 2 - j];
                }
                stack[0] = tmp;
            }
        }
        else if (strcmp(first, "UpR") == 0)
        {
            if (second - '0' <= index)
            {
                char tmp = stack[0];
                for (int j = 0; j < second - '0' - 1; j++)
                {
                    stack[j] = stack[j + 1];
                }
                stack[second - '0' - 1] = tmp;
            }
        }
        else if (strcmp(first, "PEEK") == 0)
        {
            if (index == 0)
            {
                printf("Stack Empty\n");
            }
            else
            {
                printf("%c\n", stack[0]);
            }
        }
        else if (strcmp(first, "DUP") == 0)
        {
            if (index == N)
            {
                printf("Stack FULL\n");
            }
            else
            {
                char tmp = stack[0];
                for (int j = 0; j < index; j++)
                {
                    stack[index - j] = stack[index - 1 - j];
                }
                stack[0] = tmp;
                index++;
            }
        }
    }
    return 0;
}