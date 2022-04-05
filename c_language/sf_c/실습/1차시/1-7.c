#include <stdio.h>

int f(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n * f(n - 1);
    }
}

int main(){
    int n;

    scanf("%d", &n);

    printf("%d", f(n));

    return 0;
}