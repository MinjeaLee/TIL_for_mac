#include <stdio.h>
#include <limits.h>

void swap(int *x, int *y){
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

void abc(int *a, int count){
    int *p_tmp, *p_max;
    int max_num = INT_MIN;
    for(p_tmp = a + count - 1; p_tmp >= a; p_tmp--){
        if(*p_tmp > max_num){
            max_num = *p_tmp;
            p_max = p_tmp;
        }
    }
    swap(a, p_max);
}

int main(){
    int a[10], n = 10;
    int *p;

    for(p = a; p < a + 10; p++){

        scanf("%d", p);
    }

    for(p = a; p < a + 9; p++){
        abc(p, n);
        n--;
    }

    for(p = a; p < a + 10; p++){
        printf(" %d", *p);
    }
    
    return 0;
}