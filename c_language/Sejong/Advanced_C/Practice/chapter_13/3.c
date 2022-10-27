#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibo(int n)
{
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else{
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main(){
    int x, result;
    scanf("%d", &x);

    printf("%d", fibo(x));

    return 0;
}