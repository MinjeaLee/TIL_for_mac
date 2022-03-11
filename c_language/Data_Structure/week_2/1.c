#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int modulo(int a, int b){ // use only plus and minus operators
    int r = a;
    while(r >= b){
        r -= b;
    }
    return r;      
}

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", modulo(a, b));
    

    return 0;
}