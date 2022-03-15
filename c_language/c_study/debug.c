#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    int sum = 0;

    scanf("%d", &n);

    
    for(int i = 0; i <= n; i++){
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}