#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int arr[5], sorted[5];
    int *p_arr, *p_arr2, *p_sorted;

    p_sorted = sorted;

    for(p_arr = arr; p_arr < arr + 5; p_arr++){
        scanf("%d", p_arr);
        *p_sorted = *p_arr;
        p_sorted++;
    }

    for(p_arr = sorted; p_arr < sorted + 4; p_arr++){
        for(p_arr2 = p_arr + 1; p_arr2 < sorted + 5; p_arr2++){
            if(*p_arr < *p_arr2){
                swap(p_arr, p_arr2);
            }
        }
    }
    for(p_arr = sorted; p_arr < sorted + 4; p_arr++){
        for(p_arr2 = p_arr + 1; p_arr2 < sorted + 5; p_arr2++){
            if(*p_arr == *p_arr2){
                *p_arr2 = INT_MIN;
            }
        }
    }
    
    for(p_arr = arr; p_arr < arr + 5; p_arr++){
        for(p_sorted = sorted; p_sorted < sorted + 5; p_sorted++){
            if(*p_arr == *p_sorted){
                printf("%d=r%d ",*p_arr, p_sorted - sorted + 1);
            }
        }
    }

    return 0;
}