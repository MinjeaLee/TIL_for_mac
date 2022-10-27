#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// use in-place alignment.
// maintain the front part of the array as aligned

// insertion sort algorithm

void insertion_sort(int *arr, int n){
    for (int i = 1; i < n; i++){
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

int main(){
    int n;

    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // // maintain the front part of the array as aligned
    // for (int i = 1; i < n; i++){
    //     int j = i - 1;
    //     int key = arr[i];
    //     while (j >= 0 && arr[j] > key){
    //         arr[j + 1] = arr[j];
    //         j--;
    //     }
    //     arr[j + 1] = key;

    //     // for (int k = 0; k < n; k++){
    //     //     printf("%d ", arr[k]);
    //     // }
    //     // printf("\n");
    // }
    
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++){
        printf(" %d", arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}