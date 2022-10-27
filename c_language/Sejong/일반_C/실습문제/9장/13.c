#include <stdio.h>

int arrsum(int* x, int* y){
    int total = 0;
    int* p;
    for(p = x; p <= y; p++){
        total += *p;
    }
    
    return total;
}

int main(){
    int n, s, e, x[100];
    int* p;

    scanf("%d %d %d", &n, &s, &e);
    for(p = x; p < x + n; p++){
        scanf("%d", p);
    }
    
    printf("%d", arrsum(x + s, x + e));

    return 0;
}