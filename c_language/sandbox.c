#include <stdio.h>
int main()
{
    int a;

    scanf("%d", &a);

    int n[a];

    for (int i = 0; i < a; i++)
    {
        scanf("%d", &n[i]);
    }

    
    for (int i = 0; i < a; i++)
    {
        printf("%d\n", n[i]);
    }

    return 0;
}