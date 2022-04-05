#include <stdio.h>

void input(int *x, int *y, int *z){
    scanf("%d %d %d", x, y, z);
}
void output(int *x, int *y, int *z){
    printf("%d %d %d", *x, *y, *z);
}

int main(){
    int x, y, z;
    input(&x, &y, &z);
    output(&x, &y, &z);
    
    return 1;
}