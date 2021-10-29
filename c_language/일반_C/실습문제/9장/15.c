#include <stdio.h>

void ABC(int* x, int *y){
    int* p_x;
    int tmp;
    for(p_x = x + 1; p_x < y; p_x++){
        if(*x < *p_x){
            tmp = *x;
            *x = *p_x;
            *p_x = tmp;
        }
    }

}

int main(){
    int a[10];
    int* p;
    for(p = a; p < a + 10; p++){
        scanf("%d", p);
    }
    for(p = a; p < a + 9; p++){
        ABC(p, a + 10);
    }

    for(p = a; p < a + 10; p++){
        printf(" %d", *p);
    }

    return 0;
}