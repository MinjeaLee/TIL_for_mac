#include <stdio.h>

int main(){
    int x[3][3], y[2][2], count, sx, sy;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &x[i][j]);
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &y[i][j]);
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d", x[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf(" %d", y[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            count = 0;
            if(x[i][j] == y[0][0]){
                count++;
            }
            if(x[i][j+1] == y[0][1]){
                count++;
            }
            if(x[i+1][j] == y[1][0]){
                count++;
            }
            if(x[i+1][j+1] == y[1][1]){
                count++;
            }
            if(count == 4){
                sx = i;
                sy = j;
                break;
            }
        }
        if(count == 4){
            break;
        }
    }
    if(count == 4){
        printf("%d %d", sx, sy);
    }
    else{
        printf("none");
    }



    return 0;
}