#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
    int n, *arr, sum = 0;


    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);


    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("%d\n", sum);

    return 0;
}