#include <stdio.h>

int main(){
    int a, b, result;
    scanf("%d %d", &a, &b);
    result = 0;

    result = a > b ? a : b;
    printf("%d", result);

    return 0;
}