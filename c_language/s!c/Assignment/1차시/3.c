#include <stdio.h>

int main(){
    int n, direct, x;
    int wave[100][100];

    scanf("%d", &n);

    if(n % 2 == 1){
        x = (2 * n + 1) / 2 - 1;
        direct = 1;
        for(int i = 0; i < 4 * n + 1; i++){ // ³ôÀÌ wave[i][]
            x += direct;
            wave[i][x] = 1;
            if(x == n * 2){
                direct = -1;
            }
            if(x == 0){
                direct = 1;
            }
        }
    }
    else{
        x = (2 * n + 1) / 2 + 1;
        direct = -1;
        for(int i = 0; i < 4 * n + 1; i++){
            x += direct;
            wave[i][x] = 1;
            if(x == n * 2){
                direct = -1;
            }
            if(x == 0){
                direct = 1;
            }
        }
    }

    for(int i = 0; i < 4 * n + 1; i++){
        for(int j = 0; j < 2 * n + 1; j++){
            if(wave[i][j] == 1){
                printf("O");
            }
            else{
                printf("X");
            }
        }
        printf("\n");
    }

    return 0;
}