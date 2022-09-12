#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addArray(int *a, int *b, int *result, int n){
    for (int i = 0; i < n; i++){
        *(result + i) = *(a + i) + *(b + n - 1 - i);
    }
}

int main(){
    int n;
    int x[20], y[20], result[20];
    int *ptr_x = x, *ptr_y = y, *ptr_result = result;

    scanf("%d", &n);
    for(int *p = x; p < x + n; p++){
        scanf("%d", p);
    }
    for(int *p = y; p < y + n; p++){
        scanf("%d", p);
    }
    addArray(ptr_x, ptr_y, ptr_result, n);
    for(int *p = result; p < result + n; p++){
        printf("%d ", *p);
    }


    return 0;
}