#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num;

int square(int x)
{
    printf("square(%d)\n", x);

    return x * x;
}

int main()
{
    scanf("%d", &num);

    printf("%d\n", square(num));

    return 0;
}
