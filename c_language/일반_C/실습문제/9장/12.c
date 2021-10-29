#include <stdio.h>

void addArray(int* p_x, int* p_y, int* p_result, int n){
    int *p;
    int total;

    for(p = p_result; p < p_result + n; p++){
        total = *(p_x + (p - p_result)) + *(p_y + (n -(p - p_result) - 1));
        *p = total;
    }   

}

int main(){
    int x[20], y[20], result[20];
    int n;
    int *p;
    scanf("%d", &n);
    for(p = x; p < x + n; p++){
        scanf("%d", p);
    }
    for(p = y; p < y + n; p++){
        scanf("%d", p);
    }

    addArray(x, y, result, n);
    for(int i = 0; i < n; i++){
        printf("%d", result[i]);
    }
    printf("\n");

    for(p = result; p < result + n; p++){
        printf(" %d", *p);
    }

    return 0;
}