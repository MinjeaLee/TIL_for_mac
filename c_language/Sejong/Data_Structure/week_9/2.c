#include <stdio.h>
#include <string.h>

int main()
{
    char arr[1000];
    int flag = 0;
    char stack[1000] = {
        0,
    };
    gets(arr);
    int len = strlen(arr);
    int index = 0;
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            cnt++;
            if (index == 0)
            {
                stack[0] = arr[i];
            }
            else
            {
                for (int j = 0; j < index; j++)
                {
                    stack[index - j] = stack[index - 1 - j];
                }
                stack[0] = arr[i];
            }
            index++;
        }
        if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            cnt++;
            if ((arr[i] == ')' && stack[0] == '(') || (arr[i] == '}' && stack[0] == '{') || (arr[i] == ']' && stack[0] == '['))
            {
                index--;

                for (int j = 0; j < index; j++)
                {
                    stack[j] = stack[j + 1];
                }
                stack[index] = '\0';
            }
            else
            {
                flag = 1;
            }
        }
    }
    if (flag == 1 || stack[0] != '\0')
    {
        printf("Wrong_%d", cnt);
    }
    else
    {
        printf("OK_%d", cnt);
    }
    return 0;
}