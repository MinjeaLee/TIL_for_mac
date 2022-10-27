#include <stdio.h>

int add_to_k(int *p_s, int *p_e){
    int result = 0;
    int *p_tmp;
    for(p_tmp = p_s; p_tmp <= p_e; p_tmp++){
        result += *p_tmp;
    }
    return result;
}

int main(){
    int arr[100], n, total = 0;
    int *p_arr;
    
    scanf("%d", &n);

    for(p_arr = arr; p_arr < arr + n; p_arr++){
        scanf("%d", p_arr);
    }
    for(p_arr = arr; p_arr < arr + n; p_arr++){
        total += add_to_k(arr, p_arr);
    }

    printf("%d", total);

    return 0;
}