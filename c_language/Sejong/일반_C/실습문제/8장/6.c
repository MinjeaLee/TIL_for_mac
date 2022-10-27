#include <stdio.h>

int func1(int x){
    int result = 2 * x * x - 5 * x + 1;

    return result;
}

int main(){
    int num;
    scanf("%d", &num);
    printf("%d", func1(num));

    return 0;
}