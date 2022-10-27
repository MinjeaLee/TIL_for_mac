#include <stdio.h>

void prt(int x[][5], int n);

int main(){
    int x[20][5], n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &x[i][j]);
        }
    }

    prt(x, n);

    return 0;
}

void prt(int x[][5], int n){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 5; j++){
            printf("%d ", x[i][j]);
        }
    }
    printf("\n");
}
