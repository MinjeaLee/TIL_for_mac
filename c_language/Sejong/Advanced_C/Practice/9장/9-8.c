#include <stdio.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int arr[50], n, index_a, index_b;
    int *p_arr;

    scanf("%d", &n);

    for(p_arr = arr; p_arr < arr + n; p_arr++){
        scanf("%d", p_arr);
    }

    scanf("%d %d", &index_a, &index_b);
    swap(arr + index_a, arr + index_b);

    for(p_arr = arr; p_arr < arr + n; p_arr++){
        printf(" %d", *p_arr);
    }    

    return 0;
}