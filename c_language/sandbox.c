#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strtoword(char *temp, char **word, int len);      // p는 입력한 문자열 , q는 동적할당할 문자열 , len은 길이
void prt(char **word1, char **word2, int n1, int n2); // 같은 함수 찾아서 프린트 하는 함수
void dealloc(char **p, int n);                        // 메모리 해제 함수
void print(char **p, int n);

int main()
{

    int i, j, k, len1, len2, cntword1 = 0, lenword = 0;
    int n1, n2;
    char **word1 = NULL, **word2 = NULL;
    char temp1[101], temp2[101];
    char *temp_trade = NULL;

    // gets(temp1);
    // gets(temp2);
    strcpy(temp1, "red orange yellow green blue purple");
    strcpy(temp2, "pink red yellow black white purple");

    len1 = strlen(temp1);
    len2 = strlen(temp2);
    word1 = (char **) malloc(sizeof(char *));
    n1 = strtoword(temp1, word1, len1);
    word2 = (char **) malloc(sizeof(char *));
    n2 = strtoword(temp2, word2, len2);

    printf("%p %p\n", word1, word2);

    prt(word1, word2, n1, n2);

    print(word1, n1);
    print(word2, n2);

    dealloc(word1, n1);
    dealloc(word2, n2);

    return 0;
}

int strtoword(char *temp, char **word, int len)
{
    int i, j, k, cntword = 0;
    int lenword = 0;
    char *temp_trade = NULL;

    for (i = 0; i < len; i++)
        if (temp[i] == ' ')
            cntword++;

    word = (char **)realloc(word, sizeof(char *) * (cntword + 1));

    if (word == NULL)
    {
        printf("q 동적 메모리 할당 실패");
        return 0;
    }

    for (i = 0, j = 0; i < len; i++)
    {
        if (temp[i] != ' ')
            lenword++;

        else
        {
            (word)[j] = (char *)malloc(sizeof(char) * (lenword + 1));

            if (word[j] == NULL)
            {
                printf("q[j] 동적 메모리 할당 실패");
                return 0;
            }
            lenword = 0;
            j++;
        }
    }

    word[j] = (char *)malloc(sizeof(char) * (lenword + 1));
    word[j][lenword] = '\0';

    for (i = 0, j = 0, k = 0; i < len; i++)
    {
        if (temp[i] != ' ')
        {
            word[j][k] = temp[i];
            k++;
        }

        else
        {
            word[j][k] = '\0';
            j++;
            k = 0;
        }
    }

    for (i = 0; i < cntword; i++)
    {
        for (j = 0; j < cntword; j++)
        {
            if (strlen(word[j]) < strlen(word[j + 1]))
            {
                temp_trade = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp_trade;
            }

            else if (strlen(word[j]) == strlen(word[j + 1]))
            {
                if (strcmp(word[j], word[j + 1]) > 0)
                {
                    temp_trade = word[j];
                    word[j] = word[j + 1];
                    word[j + 1] = temp_trade;
                }
            }
        }
    }

    for (i = 0; i < cntword + 1; i++)
        printf("%s ", word[i]);

    printf("\n");

    return cntword + 1;
}

void prt(char **word1, char **word2, int n1, int n2)
{
    int i, j;
    if (word1 == NULL)
    {
        printf("error\n");
    }

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("w1 : %s\n", word1[i]);
            printf("w2 : %s\n", (word2)[j]);
            if (strcmp((word1[i]), (word2[j])) == 0)
                printf("-------%s\n", (word1[i]));
        }
    }
}

void dealloc(char **p, int n)
{
    int i;

    for (i = 0; i < n; i++)
        free(p[i]);

    free(p);
}

void print(char **p, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%s ", p[i]);
    printf("\n");
}