#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int *arr_n, *arr_m;
    int n, index = 0;

    scanf("%d", &n);

    arr_n = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        arr_n[i] = i;
    }
    
    arr_m = (int*)malloc(sizeof(int) * (n - 1));   

    for(int i = 0; i < n; i++) {
        if(arr_n[i] != n / 2){
            arr_m[index] = arr_n[i];
            index++;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        printf(" %d", arr_m[i]);
    }
    printf("\n");

    free(arr_n);
    free(arr_m);

    return 0;
}