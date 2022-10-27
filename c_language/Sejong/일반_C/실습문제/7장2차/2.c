#include <stdio.h>

int main(){
    int score[3][2], total = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &score[i][j]);
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            total += score[i][j];
        }
        printf("%d\n", total);
        total = 0;
    }

    return 0;
}