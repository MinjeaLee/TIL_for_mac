#include <stdio.h>

int func2(int x, int a, int b, int c){
    int result = a * x * x + b * x + c; 

    return result;
}

int main(){
    int num, coe1, coe2, coe3;
    scanf("%d", &num);
    scanf("%d %d %d", &coe1, &coe2, &coe3);
    printf("%d", func2(num, coe1, coe2, coe3));

    return 0;
}