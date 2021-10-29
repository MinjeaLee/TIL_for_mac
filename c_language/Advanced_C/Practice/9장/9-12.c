#include <stdio.h>

void addArray(int *x, int *y, int *p_result, int n){
    int *p_tmp;

    for(p_tmp = p_result; p_tmp < p_result + n; p_tmp++){
        *p_tmp = *(x + (p_tmp - p_result)) + *(y + (n - (p_tmp - p_result) - 1));
    }
}

int main(){
    int a[20], b[20], result[20], n;
    int *p;

    scanf("%d", &n);

    for(p = a; p < a + n; p++){
        scanf("%d", p);
    }

    for(p = b; p < b + n; p++){
        scanf("%d", p);
    }

    addArray(a, b, result, n);

    for(p = result; p < result + n; p++){
        printf(" %d", *p);
    }

    return 0;
}
