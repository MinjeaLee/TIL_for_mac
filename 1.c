int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    i = 0;
    while (i < n && s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    if (i == n)
    {
        return (0);
    }
    else
    {
        return (s1[i] - s2[i]);
    }
}

#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    printf("%d", ft_strncmp("abCd", "abcd", 0));    

    return 0;
}