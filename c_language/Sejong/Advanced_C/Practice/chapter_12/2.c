#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n;
    float *arr, max = INT_MIN;

    scanf("%d", &n);
    arr = (float *)malloc(sizeof(float) * n);

    for(int i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    printf("%.2f\n", max);
    free(arr);

    return 0;
}