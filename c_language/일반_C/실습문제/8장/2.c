#include <stdio.h>

int sum(int x){
    int add = x * (x + 1) / 2;
    return add;
}

int main(){
    int a, b, result;
    scanf("%d %d", &a, &b);
    result = sum(b) - sum(a - 1);
    printf("%d", result);
    return 0;
}