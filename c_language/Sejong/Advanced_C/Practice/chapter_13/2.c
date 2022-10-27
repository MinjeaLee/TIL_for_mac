#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float factorial(int n) {
    if(n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}

int main(){
    int x;
    float result = 1;

    scanf("%d",&x);

    for(int i=1; i <= x; i++){
        result += (1/factorial(i));
    }
    printf("%f\n", result);

    return 0;
}