#include <stdio.h>

void swap(int* x, int* y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    int x[3];
    int *p_x, *p_y;

    for(p_x = x; p_x < x + 3; p_x++){
        scanf("%d", p_x);
    }
    for(p_x = x; p_x < x + 2; p_x++){
        for(p_y = p_x + 1; p_y < x + 3; p_y++){
            if(*p_x < *p_y){
                swap(p_x, p_y);
            }
        }
    }

    printf("%d", *(x + 1));

    return 0;
}