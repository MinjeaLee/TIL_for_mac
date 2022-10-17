// (Binary search - non recursive version) A program that inputs n integer keys (dictionary) and key K to explore K -Ki to output K location in the dictionary.

// Embodiment
// 1. Dynamically allocate an array of N, storage key in the input dictionary (assuming that there is no redundancy key)
// 2. Find the location of the search key using binary search
// 3. Implemented as a non -re -re -version version (ie repeated version)

// Output
// The smallest value (ie index) output of the tall X of the dictionary that satisfies x ≥ k
// (Assuming that the location starts from 0, and there is no X that meets the above conditions, N output)

// input example
// 8 -7
// -92 -31 -7 4 14 20 29 4
// output example
// 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int binary_search(int *arr, int start, int end, int key){
    int mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return end + 1;
}

int main(){
    int n, k;
    int *arr;
    int i;
    int result;

    scanf("%d %d", &n, &k);

    arr = (int *)malloc(sizeof(int) * n);
    if(arr == NULL){
        write(2, "malloc error", 12);
        exit(1);
    }

    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    result = binary_search(arr, 0, n - 1, k);
    printf("%d", result);

    free(arr);
    if(arr != NULL){
        arr = NULL;
    }
    return 0;   
}
