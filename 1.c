#include <stdio.h>
#include <string.h>

int a = 0;

int recursion(const char *s, int l, int r)
{
    a++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s)
{
    a = 0;
    return recursion(s, 0, strlen(s) - 1);
}

int main()
{
    int n;
    char s[1024];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s);
        isPalindrome(s);
        printf("%d %d\n", isPalindrome(s), a);
    }
}