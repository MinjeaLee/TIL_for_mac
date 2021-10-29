#include <stdio.h> 

int arrsum(int *arr_s, int *arr_e){
    int *p_tmp;
    int total = 0;

    for(p_tmp = arr_s; p_tmp <= arr_e; p_tmp++){
        total += *p_tmp;
    }

    return total;
}

int main(){
    int arr[100], n, s, e;
    int *p_arr;

    scanf("%d %d %d", &n, &s, &e);

    for(p_arr = arr; p_arr < arr + n; p_arr++){
        scanf("%d", p_arr);
    }

    printf("%d", arrsum(arr+ s, arr + e));

    return 0;
}