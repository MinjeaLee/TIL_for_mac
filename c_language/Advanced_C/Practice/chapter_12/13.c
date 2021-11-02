#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, d;
    int *arr;

    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &d);
    realloc(arr, (n - d) * sizeof(int));

    for(int i = 0; i < n - d; i++){
        printf("%d", arr[i]);
    }
    free(arr);


    return 0;
}