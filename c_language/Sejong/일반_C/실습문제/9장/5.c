#include <stdio.h>

void swap(int* x, int* y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    int x[5], rank[5];
    int *ptr_x, *ptr_rank, *a, *b;

    for(ptr_x = x; ptr_x < x + 5; ptr_x++){
        scanf("%d", ptr_x);
        *(rank + (ptr_x - x)) = *ptr_x; 
    }
    for(a = rank; a < rank + 4; a++){
        for(b = a + 1; b < rank + 5; b++){
            if(*a < *b){
                swap(a, b);
            }
        }
    }

    for(ptr_x = x; ptr_x < x + 5; ptr_x++){
        for(ptr_rank = rank; ptr_rank < rank + 5; ptr_rank++){
            // printf("*ptr_x = %d *ptr_rank = %d\n", *ptr_x, *ptr_rank);
            if(*ptr_x == *ptr_rank){
                printf("%d=r%d ", *ptr_x, ptr_rank - rank + 1);
                break;
            }
        }
    }


    return 0;
}