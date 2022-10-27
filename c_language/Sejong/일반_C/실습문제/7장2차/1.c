#include <stdio.h>

int main(){
    int x[3][3], plus = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &x[i][j]);
        }
    }
    for(int i = 0; i < 3; i++){
        plus += x[i][i];
    }
    printf("%d", plus);

    return 0;
}