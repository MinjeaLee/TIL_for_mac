#include <stdio.h>

int main(){
    int x[5], i, j, max, tmp;
    for(i = 0; i < 5; i++){
        scanf("%d", &x[i]);
    }
    for(i = 0; i < 4; i++){
        for(j = i + 1; j < 5; j++){
            if(x[j] < x[i]){
                tmp = x[j];
                x[j] = x[i];
                x[i] = tmp;
            }
        }
    }
    for(i = 0; i < 5; i++){
        printf("%d\n", x[i]);
    }
    return 0;
}