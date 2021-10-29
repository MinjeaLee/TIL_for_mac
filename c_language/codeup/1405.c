#include <stdio.h>

int main(){
    int n, x[1000], i, j, k, count = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < n; i++){
        for(j = i; j < n ; j++){
            printf("%d ", x[j]);
        }
        for(k = n - i; k < n; k++){
            printf("%d ", x[count]);
            count++;
        }
        count = 0;
        printf("\n");
    }

    return 0;
}