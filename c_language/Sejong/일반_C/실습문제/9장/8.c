#include <stdio.h>

void swap(int *x, int* y){
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x[50], n, a, b;
    int *p_x;

    scanf("%d", &n);
    for(p_x = x; p_x < x + n; p_x++){
        scanf("%d", p_x);
    }
    scanf("%d %d", &a, &b);

    swap(x + a, x + b);

    for(p_x = x; p_x < x + n; p_x++){
        printf(" %d", *p_x);

    }
    
    return 0;
}