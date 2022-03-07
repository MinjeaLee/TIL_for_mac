#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// make function two num add 
int add(int a, int b)
{
    return a + b;
}

int main(){
    int a, b;
    int result;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    result = add(a, b);

    printf("%d + %d = %d\n", a, b, result);

    return 0;
}