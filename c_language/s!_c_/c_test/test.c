#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char cipher[1000];
    char plain_text[1000];
    char key_word[20];

    int len_cipher;
    int len_key_word;
    int flag = 0;
    int key;

    gets(cipher);
    gets(key_word);

    len_cipher = strlen(cipher);
    len_key_word = strlen(key_word);

    for (int i = 0; i < 26; i++)
    {
        strcpy(plain_text, cipher); 
        for (int j = 0; j < len_cipher; j++)
        {
            if (cipher[j] == ' ')
            {
                plain_text[j] = ' ';
            }
            else if ((cipher[j] >= '0' && cipher[j] <= 'Z') && (cipher[j + 1] == ' ' || cipher[j + 1] == '\0') && (cipher[j] - i == '.' || cipher[j] - i == ',' || cipher[j] - i == '!'))
            {
                plain_text[j] = cipher[j] - i;
            }
            else if (cipher[j] >= 'a' && cipher[j] <= 'z')
            {
                plain_text[j] = cipher[j] - i;
                if (plain_text[j] < 'a')
                {
                    plain_text[j] += 26;
                }
            }
            else if (cipher[j] >= 'A' && cipher[j] <= 'Z')
            {
                plain_text[j] = cipher[j] - i;
                if (plain_text[j] < 'A')
                {
                    plain_text[j] += 26;
                }
            }
            else
            {
                plain_text[j] = cipher[j] - i;
            }
        }

        // not use strstr()
        for (int i = 0; i < len_cipher - len_key_word + 1; i++)
        {
            if (strncmp(plain_text + i, key_word, len_key_word) == 0)
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            key = i;
            break;
        }
    }
    printf("key = %d\n", key);
    printf("plain text = %s\n", plain_text);

    return 0;
}