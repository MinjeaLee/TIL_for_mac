#include <stdio.h>

int main(){
    int a, b, c;
    
    scanf("%d %d", &a, &b);
    c = a;
    a = a > b ? a : b;
    b = b == a ? c : b;

    printf("%d\n%d", a / b, a % b);

    return 0;
} 