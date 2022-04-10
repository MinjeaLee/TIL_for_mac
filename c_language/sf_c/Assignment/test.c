#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, num_1, num_2 = 0;
    int k;

    scanf("%d", &n);

    for(int i = 0; i < n + 1; i++) {
        printf(" ");
    }

    num_1 = (n * n) % 9;

    while(num_1 <= 0) {
        num_1 = num_1 + 9;
    }
    

    return 0;
}