#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// selection sort algorithm
// Use in place.
// Keep the back of the array in a sorting state, and use only one exchange operation for each repetition.
// (find the largest value every time, and sort by filling from the right

void selection_sort(int *arr, int n){
    for (int i = n - 1; i > 0; i--){
        int max_index = i;
        for (int j = i - 1; j >= 0; j--){
            if (arr[j] > arr[max_index]){
                max_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}

int main(){
    int n;

    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // Keep the back of the array in a sorting state, and use only one exchange operation for each repetition.
    // (find the largest value every time, and sort by filling from the right
    // for (int i = n - 1; i > 0; i--){
    //     int max = 0;
    //     for (int j = 1; j <= i; j++){
    //         if (arr[max] < arr[j]){
    //             max = j;
    //         }
    //     }
    //     int temp = arr[i];
    //     arr[i] = arr[max];
    //     arr[max] = temp;

    //     // for (int k = 0; k < n; k++){
    //     //     printf("%d ", arr[k]);
    //     // }
    //     // printf("\n");
    // }

    selection_sort(arr, n);

    for (int i = 0; i < n; i++){
        printf(" %d", arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}