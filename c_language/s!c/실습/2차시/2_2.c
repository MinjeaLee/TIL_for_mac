#include <stdio.h>

void swap(int *x, int * y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
    int x, y;

    scanf("%d %d", &x, &y);
    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);

    return 0;
}

