#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int *arr, n, tmp;
    scanf("%d", &n);
    
    arr = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}