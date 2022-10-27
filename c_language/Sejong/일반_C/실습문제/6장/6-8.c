#include <stdio.h>

int main(){
    int n, m, i, j, result;
    scanf("%d %d", &n, &m);

    for(i = n; i <= m; i++){
        result = 1;
        for(j = 1; j <= i; j++){
            result *= j;
        }
        printf("%d!=", i);
        for(j = 1; j <= i; j++){
            printf("%d", j);
            if(j != i){
                printf("*");
            }
        }
        printf("=%d\n", result);
    }

    return 0;
}